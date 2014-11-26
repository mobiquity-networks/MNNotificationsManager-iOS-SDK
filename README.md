# MNNotificationsManager

## Installation

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
3. Other Linker Flags: `-ObjC` ([Why?](https://developer.apple.com/library/mac/qa/qa1490/_index.html))

### Background Modes Required

- Location Updates

## iOS 8 - Location Authorization
 
MNNotificationsManager makes use of the authorization patterns established with the iOS 8 release, but remains compatible with the iOS 7 authorization system.

References:

- [WWDC 2014 Session 706 “What’s New in Core Location”](https://developer.apple.com/videos/wwdc/2014/?id=706)
- [Core Location Manager Changes in iOS 8](http://nevan.net/2014/09/core-location-manager-changes-in-ios-8/)

To integrate Notifications SDK into your application, you should take into account the two different authorization schemes present in iOS 7 and iOS 8:

- On iOS 7 you had the *choice* of adding your own message to the privacy alert adding the ```NSLocationUsageDescription``` key and a message to your Application's Info.plist. 
- On **iOS 8** that key is deprecated and has been replaced by these two:
	```
	￼NSLocationAlwaysUsageDescription
		
	NSLocationWhenInUseUsageDescription
	```
	iOS 8 **requires** you the use of one of them. In our particular case, if you want to integrate MNNotificationsManager into your application you **must** specify the **NSLocationAlwaysUsageDescription** key and a message in your Info.plist.
- If you need to support both iOS versions, you must specify the NSLocationAlwaysUsageDescription key, and optionally NSLocationUsageDescription, recommended for a better user experience for iOS 7 users.

## Usage

### MNNotificationsManager Instance
In order to start using the SDK, you have to get an instance of MNNotificationsManager, which requires the use of its asynchronous factory method.
 
Init sample:

```objectivec
MNBAppKey *appKey = [[MNBAppKey alloc] initWithAppKey:@"providedAppKey" andSecretKey:@"providedSecretKey"];
CustomMNNotificationsManagerDelegate *delegate = [[CustomMNNotificationsManagerDelegate alloc] init];
[MNNotificationsManager notificationsManagerWithAppKey:appKey options:nil user:nil delegate:delegate completionHandler:^(MNNotificationsManager *notificationsManager, NSError *error) {
        if (!error) {
            self.notificationsManager = notificationsManager;
            [self.notificationsManager start];
        } else {
            NSLog(@"Error creating Notifications Manager: %@"error.localizedDescription);
        }
    }];
```

### Options

MNNotificationsManager's factory method has an ```options``` parameter. This ```MNNMOptions```' instance can be used to configure some sdk's functionalities.

See ```MNNMOptions```' class reference for a description of each property.

### User

MNNotificationsManager's factory method has an ```user``` parameter. This ```MNUser```' instance can be used to inform the SDK about:

1. User's role type: This value allows you to deploy different information on the same beacons deployment with different User's role types. Default is ```MNUserRoleTypeFinalUser```.
2. User's login, provider and *audience* data: This information will be sent along with the stats in order to filter/show information as accurate as possible to Backend's users.

See ```MNUser```' reference for a description of each property.

### SDK integration with local notifications
Due to the nature of the framework, it's mandatory for the app to call [MNNotificationsManager -processLocalNotification:localNotification] in its [UIApplicationDelegate application:didReceiveLocalNotification:] method, in a similar way as shown in this example:

```objectivec
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
	BOOL isNotificationsManagerNotification = [notificationsManager processLocalNotification:notification];
    if (isNotificationsManagerNotification) {
        NSLog(@"SDK owned local notification, do nothing");
    } else {
        NSLog(@"SDK did not process the notification");
        // Process the notification
        ...
    }
}
```


### MNNotificationsManagerDelegate

MNNotificationsManager informs the delegate object about status changes of device systems involved in the correct operation of the SDK. Following is an example of how to implement a custom MNNotificationsManagerDelegate:

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
#### Location Services and Bluetooth state/status

MNNotificationsManager requires the application to be authorized to use Location Services and Bluetooth to be powered on, so it is recommended to implement the two delegate methods to monitorize their value changes.

### Reference

See the included docset.

## Core Location's regions limit

Due to the Core Location's 20 regions limit and the shared data between CLLocationManager instances, **the simultaneous use of MNSignalsManager and CLLocationManager's monitoring or ranging is not supported.** There are not restrictions to use the rest of CLLocationManager's functionalities.

If the number of configured BeaconRegions and Geofences is greater than 20, MNNotificationsManager will monitore every BeaconRegion but will use user's location to monitore only the nearest Geofences.

## IDFA Use

This framework makes extensive use of the Apple's **advertising identifier** by default. This identifier is unique to each device and therefore Apple supervises how the developers are using it in their apps. If your app uses IDFA with MNNotificationsManager (default behaviour), you will have to indicate it in the last phase of your app App Store submit, in the section titled [**Advertising Identifier**](https://developer.apple.com/library/ios/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html)

Also you can choose not to use it and rely in the more restrictive vendor identifier by setting to NO the MNNMOptions property :
```objectivec
@property (nonatomic, assign) BOOL useIDFAWhenPossible;
 ```

## iOS 6 Support

MNNotificationsManager does not work on iOS 6 but it allows Apps to run on a device using it. Apps compatible with iOS 6 should check the iOS version using "isOSVersionSupported" before calling any other MNSignalsManager method.

1. MNNotificationsManager should be installed manually.
2. Set CoreLocation.framework status to "Optional" at "Link Binary With Libraries".
3. Check iOS version before using MNNotificationsManager.

## License

Mobiquity Technologies, Inc. All rights reserved. See the LICENSE file for more info.

