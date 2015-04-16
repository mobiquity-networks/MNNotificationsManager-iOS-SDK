# MNNotificationsManager

## 1. Installation

### Using CocoaPods

MNNotificationsManager is available through [CocoaPods](http://cocoapods.org), to install
it, **add the Mobiquity Networks Spec Repo** to your Podfile:

	source 'https://github.com/mobiquity-networks/CocoaPods.git'
	
and then, simply add the following dependency to your Podfile:

    pod 'MNNotificationsManager', '~> 1.0'

Note that `'~> 1.0'` and `'~> 1.0.0'` have different behavior, see the [Podfile Syntax Reference](http://guides.cocoapods.org/syntax/podfile.html#pod). We recomend to use the first one.

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

To integrate Notifications SDK into your application, you should take into account the two different authorization schemes present in iOS 7 and iOS 8:

- On iOS 7 you had the *choice* of adding your own message to the privacy alert adding the ```NSLocationUsageDescription``` key and a message in your Application's Info.plist. 
- On **iOS 8** that key is deprecated and has been replaced by these two:
	```
	￼NSLocationAlwaysUsageDescription
		
	NSLocationWhenInUseUsageDescription
	```
	**iOS 8 requires you the use of one of them. In our particular case, if you want to integrate MNNotificationsManager into your application you must specify the ```NSLocationAlwaysUsageDescription``` key and a message in your Info.plist.**
- If you need to support both iOS versions, **you must specify the NSLocationAlwaysUsageDescription key, and optionally NSLocationUsageDescription**, recommended for a better user experience for iOS 7 users.

References:

- [WWDC 2014 Session 706 “What’s New in Core Location”](https://developer.apple.com/videos/wwdc/2014/?id=706)
- [Core Location Manager Changes in iOS 8](http://nevan.net/2014/09/core-location-manager-changes-in-ios-8/)
 

## 3. Usage

### MNNotificationsManager Instance
In order to start using the SDK, you have to get an instance of MNNotificationsManager, which requires the use of its asynchronous factory method.

At this moment, you will need to provide a valid Mobiquity Networks Application Key and Secret. Values can be obtained from your [Panel account](http://panel.mobiquitynetworks.com) under Clients & Apps.

Basic initialization example:
```objectivec
// Provide a Mobiquity Networks Application Key and Secret.  Values can be obtained from
// your panel account under Clients & Apps
MNAppKey *appKey = [[MNAppKey alloc] initWithAppKey:@"providedAppKey" 
                                       andSecretKey:@"providedSecretKey"];
                                       
// Keep a strong reference to your custom MNNotificationsManagerDelegate implementation 
// (the object of your app which will receive valuable information on the SDK status.
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
		// It is NOT recommended to use the Singleton Pattern to wrap the Notifications Manager
		// instance.
		self.notificationsManager = notificationsManager;
		// Once initialized, you can call the start method whenever you want to start operation.
		[self.notificationsManager start];
	} else {
		NSLog(@"NMNotificationsManager instantiation error: %@", error.localizedDescription);
	}
}];
```

### Options

As seen above, MNNotificationsManager's factory method offers an optional ```options``` parameter. You can use a ```MNNMOptions``` instance to configure some SDK functionalities:

- activityIndicatorManaged: if set to YES (default value), status bar network activity indicator will be shown with the SDK network operations.
- useIDFAWhenPossible: MNNotificationsManager will try to use [ASIdentifierManager sharedManager].advertisingIdentifier whenever is possible. You can disable this behaviour by setting it to NO. Then MNNotificationsManager will use [UIDevice identifierForVendor] instead. Read more in the **IDFA Use** chapter.
- statsTrackingValues: You can append extra information that will be sent with your Mobiquity usage stats as a dictionary of key-value pairs:
```

    MNNMOptions *options = [[MNNMOptions alloc] init];    
    options.statsTrackingValues = @{
   	   @"customKey1" : @"value1",
       @"customKey2" : @"value2"
    };
    
```

### User

MNNotificationsManager's factory method has an optional ```user``` parameter. You can use a ```MNUser```' instance to inform the SDK about:

1. User's role type: This value allows you to send information about the role of the user who is using the application with the stats. There are 3 different User's role types, Tester, Developer, Final User. Default is ```MNUserRoleTypeFinalUser```.
2. User's login, provider and *audience* data: This information will be sent along with the stats in order to filter/show information as accurate as possible to Mobile users and to extract valuable statistics about use.

It is possible to send different types of information regarding the app user like the gender, birthday or user preferences (custom tags) that the platform will use later to provide the most accurate targeting for your campaigns. To provide this kind of information make use of the ```audience``` property in ```MNUser``` that accepts a ```MNUserAudience``` object:

```objectivec
    MNUserAudience *userAudience = [[MNUserAudience alloc] init];
    userAudience.gender = kMNUserAudienceGenderFemale;
    userAudience.tags = @[@"adventure sports", @"computers", @"art"];
    
    MNUser *user = [[MNUser alloc] initWithUserName:@"sample user"];
    user.userAudience = userAudience;
``` 


See ```MNUser``` and ```MNUserAudience``` reference for a description of each property.

### SDK integration with local notifications
Due to the nature of the framework, it's mandatory for your app to redirect received local notifications to the SDK for it to manage them automatically.

To do that, you must call ```[MNNotificationsManager +processLocalNotification:]``` in its ```[UIApplicationDelegate application:didReceiveLocalNotification:]``` method and in the ```[UIApplicationDelegate application:didFinishLaunchingWithOptions:]``, in a similar way as shown in this example:

```objectivec
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
	BOOL isNotificationsManagerNotification = [MNNotificationsManager processLocalNotification:notification];
    if (isNotificationsManagerNotification) {
        NSLog(@"SDK owned local notification, do nothing");
    } else {
        NSLog(@"SDK did not process the notification");
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
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didDiscoveredGeoInfo:(MNNMGeoInfo *)geoInfo
{
    NSLog(@"Discovered %lu POIs, in '%@'", (unsigned long)geoInfo.pois.count, geoInfo.venue.name);
}

```

### Compatibility with location based apps and third party SDKs

iOS only allows monitoring up to 20 regions (BeaconRegions or Geofences) by application. Therefore MNNotificationsManager monitors a maximum of 8 regions simultaneously as a way to improve coexistence with third party SDKs that use Core Location, or integration in apps that also use that iOS Framework.

To optimize the use of geofences, Notification Manager makes use of the user location to load only the nearest ones, as monitoring all geofences at the same time is not possible due to the limitations and far from good practice.

MNNotificationsManager adds the prefix ```Mobiquity_``` to its monitored regions. **If you use another SDK or CoreLocation in your app, please ensure these regions are not modified in any way**.

### Reference

See the included docset.

## IDFA Use

This framework makes extensive use of the Apple's **advertising identifier** by default. This identifier is unique to each device and therefore Apple supervises how the developers are using it in their apps. If your app uses IDFA with MNNotificationsManager (default behaviour), you will need to indicate it in the last phase of your app App Store submit, in the section titled [**Advertising Identifier**](https://developer.apple.com/library/ios/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html)

Also you can choose not to use it and rely in the more restrictive vendor identifier by setting to NO the MNNMOptions property :
```objectivec
@property (nonatomic, assign) BOOL useIDFAWhenPossible;
 ```

## iOS 6 Support

MNNotificationsManager does not work on iOS 6 but it allows Apps to run on a device using it. Apps compatible with iOS 6 should check the iOS version using "isOSVersionSupported" before calling any other Notifications Manager method.

1. MNNotificationsManager should be installed manually.
2. Set CoreLocation.framework status to "Optional" at "Link Binary With Libraries".
3. Check iOS version before using MNNotificationsManager.

## Sample Application

The *Example App* directory in the repository's root contains the source code for a basic functionality app that shows a way to integrate the SDK into your application. You can use it as a starting point for your integration process, and as a basic testing application adding your provided App Key and Secret.

## License

Mobiquity Technologies, Inc. All rights reserved. See the LICENSE file for more info.

