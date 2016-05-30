# MNNotificationsManager


## 1. Installation

### Prerequisites

MNNotificationsManager supports distribution (but **not execution**) in iOS7 and **execution on iOS 8 or above**. If your app supports iOS 7, you must check for iOS version compatibility with the provided ```[MNNotificationsManager -isOSVersionSupported] ``` method before calling any other initialization method:

```objectivec
if ([MNNotificationsManager isOSVersionSupported]) {
    // MNNotificationsManager initialization
    // ...
}   

```

### Using CocoaPods

MNNotificationsManager is available through [CocoaPods](http://cocoapods.org), to install
it, simply add the following dependency to your Podfile:

    pod 'MNNotificationsManager', :git => 'https://github.com/mobiquity-networks/MNNotificationsManager-iOS-SDK.git'

### Manually

1. Add MNNotificationsManager.framework and MNProximityManager.bundle to you project.
2. Link binary with Libraries:
	- CoreData.framework
	- CoreLocation.framework
	- AdSupport.framework
	- MobileCoreServices.framework
	- CoreBluetooth.framework
    - UIKit.framework
    - CoreTelephony.framework
3. Other Linker Flags: `-ObjC` ([Why?](https://developer.apple.com/library/mac/qa/qa1490/_index.html))

## 2.  Location Authorization Set-Up

To integrate Notifications SDK into your application, you have to add this key with a custom description in your Application's Info.plist:

```
￼NSLocationAlwaysUsageDescription	
```

References:

- [WWDC 2014 Session 706 “What’s New in Core Location”](https://developer.apple.com/videos/wwdc/2014/?id=706)
- [Core Location Manager Changes in iOS 8](http://nevan.net/2014/09/core-location-manager-changes-in-ios-8/)
 

## 3. Usage

### MNNotificationsManager Instance
In order to start using the SDK, you have to get an instance of MNNotificationsManager, which requires the use of its asynchronous factory method.

At this moment, you will need to provide a valid Mobiquity Networks Application Key and Secret. Values can be obtained from your [Panel account](https://panel.mobiquitynetworks.com) under Clients & Apps.

Basic initialization example:

```objectivec
#import <MNNotificationsManager/MNNotificationsManager.h>

// Provide a Mobiquity Networks Application Key and Secret.  Values can be obtained from
// your panel account under Clients & Apps
MNAppKey *appKey = [[MNAppKey alloc] initWithAppKey:@"providedAppKey" 
                                       andSecretKey:@"providedSecretKey"];
                                       
// Keep a strong reference to your custom MNNotificationsManagerDelegate implementation 
// (the object of your app which will receive valuable information on the SDK status)
self.notificationsManagerDelegate = [[CustomMNNotificationsManagerDelegate alloc] init];

// MNNotificationsManager instantiation
[MNNotificationsManager notificationsManagerWithAppKey:appKey 
                                               options:nil 
                                                  user:nil 
                                              delegate:self.notificationsManagerDelegate 
                                     completionHandler:^(MNNotificationsManager *notificationsManager, NSError *error) {
	if (!error) {
		NSLog(@"NMNotificationsManager instantiation success");
		// Keep a strong reference to the Notifications Manager object in your app.
		self.notificationsManager = notificationsManager;
		// Once initialized, you can call the start method whenever you want to start operation.
		[self.notificationsManager start];
	} else {
		// In case of initialization problem, the error object contains all the information of it. 
		NSLog(@"NMNotificationsManager instantiation error: %@", error.localizedDescription);
	}
}];
```

### Options

As seen above, MNNotificationsManager's factory method offers an optional ```options``` parameter. You can use a ```MNNMOptions``` instance to configure the SDK:

- statsTrackingValues: You can append extra information that will be sent with your Mobiquity usage stats as a dictionary of key-value pairs:


```

    MNNMOptions *options = [[MNNMOptions alloc] init];    
    options.statsTrackingValues = @{
   	   @"customKey1" : @"value1",
       @"customKey2" : @"value2"
    };
    
```

### User and User Audience (Demography)

MNNotificationsManager's factory method has an optional ```user``` parameter. You can use a ```MNUser``` instance to inform the SDK about:

1. User's role type: This value allows you to send information about the role of the user who is using the application with the stats. There are 3 different User's role types, Tester, Developer, Final User. Default is ```MNUserRoleTypeFinalUser```.
2. *Audience* data: This information will be sent along with the stats in order to filter/show information as accurate as possible to Mobile users and to extract valuable statistics about use.

It is possible to send different types of information regarding the app user like the gender, birthday or user preferences (custom tags) that the platform will use later to provide the most accurate targeting for your campaigns. To provide this kind of information use of the ```audience``` property in ```MNUser``` that accepts a ```MNUserAudience``` object:

```objectivec
    MNUserAudience *userAudience = [[MNUserAudience alloc] init];
    userAudience.tags = @[@"adventure sports", @"computers", @"art"];
    
    MNUser *user = [[MNUser alloc] initWithUserName:@"sample user"];
    user.userAudience = userAudience;
``` 

The file MNUserAudience.h contains the potential choices most of the audience properties can take:

```objectivec
static NSString* const kMNUserAudienceGenderMale = @"M";
static NSString* const kMNUserAudienceGenderFemale = @"F";

static NSString* const kMNUserAudienceEducationCollege = @"CLL";
static NSString* const kMNUserAudienceEducationGradSchool = @"GS";
static NSString* const kMNUserAudienceEducationNoCollege = @"NCLL";

```
Only assign constants to the MNUserAudience properties 

userAudience.gender = kMNUserAudienceGenderFemale;
userAudience.maritalStatus = kMNUserAudienceMaritalStatusMarried;
userAudience.kids = 2;

```


See ```MNUser``` and ```MNUserAudience``` reference for a description of each property.

### SDK integration with local notifications
Due to the nature of the framework, it's mandatory for your app to redirect received local notifications to the SDK for it to manage them automatically.

To do that, you must call ```[MNNotificationsManager +processLocalNotification:]``` in its ```[UIApplicationDelegate application:didReceiveLocalNotification:]``` method and in the ```[UIApplicationDelegate application:didFinishLaunchingWithOptions:]```, in a similar way as shown in this example:

```objectivec
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
	BOOL isNotificationsManagerNotification = [MNNotificationsManager processLocalNotification:notification];
    if (isNotificationsManagerNotification) {
        NSLog(@"Notifications Manager has processed the local notification for us, it was a Notifications SDK generated local notification");
    } else {
        NSLog(@"Notifications Manager has not processed the local notification, we should do it here because it is a notification related to our own app");
        // Process the notification
        ...
    }
}
```
    
```objectivec
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UILocalNotification *notification = launchOptions[UIApplicationLaunchOptionsLocalNotificationKey];
    BOOL isNotificationsManagerNotification = [MNNotificationsManager processLocalNotification:notification];
    if (isNotificationsManagerNotification) {
        NSLog(@"Notifications Manager has processed the local notification for us, it was a Notifications SDK generated local notification");
    } else {
        NSLog(@"Notifications Manager has not processed the local notification, we should do it here because it is a notification related to our own app");
    }
    return YES;
}
```

### MNNotificationsManagerDelegate

MNNotificationsManager informs the delegate object about status changes of device systems involved in the correct operation of the SDK, for example when Location Services authorization is disabled or Bluetooth is Powered Off, and also when geographical information of interest is discovered nearby.

#### Location Services and Bluetooth state/status

MNNotificationsManager requires the application to be authorized to use Location Services and Bluetooth to be powered on, so it is recommended to implement the two delegate methods to monitor their value changes.

```objectivec
- (void) notificationsManager:(MNNotificationsManager *) notificationsManager didChangeAuthorizationStatus:(MNPMAuthorizationStatus)status
{
    if (status == MNPMAuthorizationStatusRestricted || status == MNPMAuthorizationStatusDenied) {
        // User doesn't allow us to use the location services
        // Maybe you could show an error?
    }
}

- (void) notificationsManager:(MNNotificationsManager *) notificationsManager didChangeBluetoothState:(MNPMBluetoothState)state
{
    if (state == MNPMBluetoothStatePoweredOff) {
        // Bluetooth is powered off
        // Maybe you could ask the user to turn it on?
    }
}
```

#### Geographical information discovering

The delegate object is also notified when relevant information for your app is found in the current location. To take advantage of this information, you should implement the delegate method shown in the following sample code:

```objectivec
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager beaconLocationSignal:(MNNMBeaconLocationSignal *)beaconLocationSignal;
{
    NSLog(@"Discovered %lu POIs, in '%@'", (unsigned long) beaconLocationSignal.nearPOIs.count, beaconLocationSignal.venue.name);
}

```

### Compatibility with location based apps and third party SDKs

iOS only allows monitoring up to 20 regions (BeaconRegions or Geofences) by application. Therefore MNNotificationsManager monitors a maximum of 8 regions simultaneously as a way to improve coexistence with third party SDKs that use Core Location, or integration in apps that also use that iOS Framework.

To optimize the use of geofences, Notification Manager makes use of the user location to load only the nearest ones, as monitoring all geofences at the same time is not possible due to the limitations and far from good practice.

MNNotificationsManager adds the prefix ```Mobiquity_``` to its monitored regions. **If you use another SDK or CoreLocation in your app, please ensure these regions are not modified in any way**.

## IDFA Use

This framework makes extensive use of the Apple's **advertising identifier** by default. This identifier is unique to each device and therefore Apple supervises how the developers are using it in their apps. You will need to indicate it in the last phase of your app App Store submit, in the section titled [**Advertising Identifier**](https://developer.apple.com/library/ios/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html)


## Sample Application

The *Example App* directory in the repository's root contains the source code for a basic functionality app that shows a way to integrate the SDK into your application. You can use it as a starting point for your integration process, and as a basic testing application adding your provided App Key and Secret.

## License

Mobiquity Technologies, Inc. All rights reserved. See the LICENSE file for more info.

