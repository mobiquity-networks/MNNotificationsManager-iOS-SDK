![logo](http://www.mobiquitynetworks.com/wp-content/themes/mobiquity/images/logo.jpg)

# iOS Mobiquity Networks SDK V2 #

# Migration From Pre-2.0 Versions #

This version of the SDK is a complete rewrite from version 1.x and thus all the integration, entry points, and delegates have been redone. As such, we’ve attempted to cover all points of upgrading from a previous version. If you’re newly installing this SDK, then feel free to skip this section and head down to the section below titled “Installation".

To start with, you’ll need to remove all references to the current SDK and delete it from your project.  If it was manually added to your project, simply delete both MNNotificationsManager.framework and MNProximityManager.bundle.  If it was added through cocoapods, you’ll need to do a few extra steps.

Once you’ve finished removing the existing framework, you can go ahead and follow the instructions above to install the new framework.

## Removing Via Cocoapods ##

To remove an existing pod the easiest (and best) way is to use a couple Cocoapods plugins (github links: https://github.com/CocoaPods/cocoapods-deintegrate, https://github.com/BendingSpoons/cocoapods-clean)

1. Install deintegrate and clean:

```
$ gem install cocoapods-deintegrate
```

```
$ gem install cocoapods-clean
```

2. Run deintegrate in the folder of the project:

```
$ pod deintegrate
```

3. Clean:

```
$ pod clean
```

4. Modify your podfile (delete the line with the MNNotificationsManager) and run:

```
$ pod install
```

(Note: If your project no longer has any pods this last step can be skipped)


## Linker Flags ##

You can remove the existing linker flag –ObjC as it is no longer required by our SDK.  If you use another SDK that requires it, you can leave it.

## AppKey/Secret ##

In the previous version, the appkey and secret were passed to the new instance of the MNNotifications manager through the MNAppKey class.  The SDK will now read these from a property list file called mobiquity.plist.  Create a new plist file in XCode (plist files can be created via the File->New File dialog and selecting Resource type file and creating a Property List file).  You can then add your appkey and secret here using the keys “appkey” and “secret” respectively.

## Instantiation ##

In the previous version of the SDK you would use a completion block to either receive your instance of the notification manager, or any associated error while trying to instantiate it.  This has been changed to use a delegate callback.   There’s an interface called MNNotificationsDelegate that contains an optional method to receive any errors associated to the SDK.  These errors will contain descriptions, reasons, and a possible recovery solution.

This delegate callback will be used anytime there’s an associated error in the framework that might be able to be solved by the application developer.  These are broken down into error code types which can be accessed as an enum in the MNManager shared instance (such as plist errors, location services errors, or deep linking errors).

This delegate can be set through the MNManager shared instance.

## Options ##

In previous versions of the framework you could pass custom “options” to the SDK to be uploaded with the event data.  This can still be done, but rather than instantiating a custom class, you can create a Dictionary (or NSDictionary if using Objective-C) of string keys and string values.  This dictionary can then be passed to the MNManager shared instance.  For an example of this, see the section below titled “CustomVars”.  You can also retrieve the existing dictionary of values set and add new items to it before passing it back to the framework.

## User Audience/Demographics ##

You can still pass demographics information through the framework.  This is now done by instantiating a new MNDemographics class and setting the fields you would like before passing to the MNManager shared instance.  All fields are optional.  Most of the fields in the demographics class are enum values.  For more information and samples regarding demographics see the section below titled “Demographics”


## SDK Integration with Local Notifications ##
The SDK still requires integration with local notifications, however this integration has changed slightly.  We now offer a method in MNManager that will tell you if the notification comes from our SDK or not.  For more information, see the section title “Local Notifications” below.

## Previous Delegates ##
In the previous version of the SDK you could receive callbacks through a delegate.  This is still possible, but the method signatures have changed slightly.  If you were receiving any of the previous delegate callback methods, please take a look at their new method signatures above under the “Delegates” section.



# Installation #

The MNNotifications.framework currently supports iOS 8.0 and up.

## CocoaPods ##

We recommend using the CocoaPods installation method as it's easier to consume a fat framework in your project.

Turn on framework support in your Podfile and add the following line to your Podfile:

```
pod 'MNNotifications', :git => 'https://github.com/mobiquity-networks/MNNotificationsManager-iOS-SDK.git'
```

## Manual ##

1. Drag and Drop MNNotifications.framework into the “Embedded Binaries” section of your app.  Ensure “Copy if required” is selected so that Xcode copies the framework into the correct location.

This will automatically link it and embed it into your app.  See screenshot below.

![screenshot](http://i.imgur.com/ZqANjSa.png)


2. This extra step is for those using Objective-C only

Xcode 7.x: In your build options, set “Embedded Content Contains Swift Code” to Yes.

Xcode 8.x and up: In your build options, set “Always Embed Swift Standard Libraries” to Yes

This is required since the framework is written in Swift.  If your app is already written in Swift, this step is not required.


3. Add required scripts to Build Phases of your project.

You need to add 2 scripts to your Build Phases to strip the simulator slice from our fat framework on any archive build of your app. If this isn't done, it will be rejected from the App Store due to it containing the x86_64 and i386 slices of the framework.

This has been adopted from a great blogpost on the subject available here: http://code.hootsuite.com/an-introduction-to-creating-and-distributing-embedded-frameworks-in-ios/

Under the Build Phases tab, add a new run script phase, drag it so it's just after "Target Dependencies" and paste the following in the run script editor area:

```
# Removal script for simulator slices

# Script provided by @bstover from http://code.hootsuite.com/an-introduction-to-creating-and-distributing-embedded-frameworks-in-ios/

# 1
# Set bash script to exit immediately if any commands fail.
set -e

# 2
# Setup some constants for use later on.
FRAMEWORK_NAME="MNNotifications"

# 3
# If there exists a backup version of the framework, restore it and remove backup
if [[ -d "${SRCROOT}/backup" ]]; then
rm -rf "${SRCROOT}/${FRAMEWORK_NAME}.framework"
cp -rf "${SRCROOT}/backup/${FRAMEWORK_NAME}.framework" "${SRCROOT}/${FRAMEWORK_NAME}.framework"
rm -rf "${SRCROOT}/backup"
fi

# 4
# Only perform the following steps when building for release on device
if [[ "${CONFIGURATION}" == "Release" && "${SDKROOT}" == *"iPhoneOS"* ]]; then

# 5
# Create backup copy of framework
mkdir "${SRCROOT}/backup"
cp -rf "${SRCROOT}/${FRAMEWORK_NAME}.framework" "${SRCROOT}/backup/${FRAMEWORK_NAME}.framework"

# 6
# Strip out the unneeded architectures
lipo "${SRCROOT}/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}" -remove "i386" -output "${SRCROOT}/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}"
lipo "${SRCROOT}/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}" -remove "x86_64" -output "${SRCROOT}/${FRAMEWORK_NAME}.framework/${FRAMEWORK_NAME}"
fi
```

Create a second run script phase and place it after "Embed Framework", and paste the following in the run script editor area:

```
# Replace Framework we removed simulator slices from with original backup

# Script provided by @bstover from http://code.hootsuite.com/an-introduction-to-creating-and-distributing-embedded-frameworks-in-ios/

# 1
# Set bash script to exit immediately if any commands fail.
set -e

# 2
# Setup some constants for use later on.
FRAMEWORK_NAME="MNNotifications"

# 3
# Restore backup copy of framework and remove backup
if [[ -d "${SRCROOT}/backup" ]]; then
rm -rf "${SRCROOT}/${FRAMEWORK_NAME}.framework"
cp -rf "${SRCROOT}/backup/${FRAMEWORK_NAME}.framework" "${SRCROOT}/${FRAMEWORK_NAME}.framework"
rm -rf "${SRCROOT}/backup"
fi
```


# Location Authorization Set-Up #

MNNotifications framework uses the devices location both when the app is running foreground and when it’s in the background.  Thus, if you app doesn’t already support location awareness, you will need to add the following keys to the Application’s Info.plist file:

```
￼NSLocationAlwaysAndWhenInUsageDescription
￼NSLocationWhenInUseUsageDescription
```

If your app supports iOS10 and earlier you need to add the following key as well:

```
￼NSLocationAlwaysUsageDescription
```

References:

* [Request Always Authorization](https://developer.apple.com/documentation/corelocation/choosing_the_authorization_level_for_location_services/request_always_authorization)

# Usage #

The entry point for all calls to the SDK is the shared instance of MNManager class.  It is here that you can start, stop, enable, disable, and set the delegate, among other things.  These will all be covered below.

## Adding AppKey/Secret ##

Whether you’re using Swift or ObjectiveC we use a custom plist file in the application that contains the App Key and Secret (provided by Mobiquity Networks) along with some other options that can be set.  You’ll need to create a new plist file for you app titled “mobiquity.plist”.  At a minimum this plist must contain 2 entries: “appkey” and “secret”.


## Starting the SDK ##

**Swift**

```
import MNNotifications

...

MNManager.sharedInstance.startSDK()
```


**Objective-C**

```
#import <MNNotifications/MNNotifications-swift.h>

...

[[MNManager sharedInstance] startSDK];
```

And that’s it! The SDK will now start and run in the background without any further integration required.  We do, however, recommend implementing the optional delegate callback methods below.

The current version of the framework supports Swift 3.1.

## Delegates ##

There is an optional delegate with four optional methods to implement.  We recommend at a minimum to implement the error delegate method to handle any errors that might occur in the SDK (such as plist with your appkey/secret).  The others cover things such as Bluetooth being turned off (you will only receive this callback when BT is turned off so you can possibly alert the user), when the authorization status changes to denied or restricted (you will only receive this if it becomes denied or restricted), or when we range a beacon.

Setting the delegate is done through the MNManager shared instance.


### Delegate Name ###
MNNotificationsDelegate

### Optional Delegate Methods ###

**Note:** If you're implementing the authorization callback you need to import CoreLocation.

**Note:** If you're implementing the Bluetooth state callback you need to import CoreBluetooth.

**Swift**

```
func mnManagerDidRangeBeacon(beaconLocationSignal: MNBeaconLocationSignal)
func mnManagerDidChangeAuthorizationStatus(status: CLAuthorizationStatus)
func mnManagerDidChangeBluetoothState(state: CBCentralManagerState)
func mnManagerDidFailWithError(error: NSError)
```

**Objective-C**

```
- (void)mnManagerDidRangeBeaconWithBeaconLocationSignal:(MNBeaconLocationSignal *)beaconLocationSignal
- (void)mnManagerDidChangeAuthorizationStatusWithStatus:(CLAuthorizationStatus)status
- (void)mnManagerDidPowerOffBluetooth
- (void)mnManagerDidFailWithErrorWithError:(NSError *)error
```

# Local Notifications #

The SDK requires that any notification that has been displayed by the SDK be passed back to the SDK for proper handling.  You will need to override 2 methods in your app delegate and, using the provided methods in MNManager, pass the UILocalNotification to the SDK.

Below you can find examples for both Swift and Objective-C.

**Swift**

```
func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
	if let notification = launchOptions?[UIApplicationLaunchOptionsLocalNotificationKey] as? UILocalNotification {
		if MNManager.sharedInstance.isMNNotification(notification) {
			MNManager.sharedInstance.processLocalNotification(notification)
		}
	}

	//Do any other work required/handle other notifications

}


func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
	if MNManager.sharedInstance.isMNNotification(notification) {
		MNManager.sharedInstance.processLocalNotification(notification)
	}
	
	//Handle other type of notification
}

```


**Objective-C**

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	UILocalNotification *notification = [launchOptions valueForKey:UIApplicationLaunchOptionsLocalNotificationKey];
	if (notification) {
		if ([[MNManager sharedInstance] isMNNotificationWithNotification:notification]) {
			[[MNManager sharedInstance] processLocalNotificationWithNotification:notification];
		}
	}
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
	if (notification) {
		if ([[MNManager sharedInstance] isMNNotificationWithNotification:notification]) {
			[[MNManager sharedInstance] processLocalNotificationWithNotification:notification];
		}
	}
}

```

# Custom Vars #

You can pass custom variables to the SDK through the MNManager instance.  This is done through a Dictionary (or NSDictionary in Objective-C) with string keys and string values.  There’s also a method to retrieve any previously set custom vars.

**Swift**

```
//Setting CustomVars
let customVars = ["var1": "value1",
"var2": "value2"]
MNManager.sharedInstance.setCustomVars(customVars)

//Retrieving CustomVars
let previouslySetCustomVars:[String:String]? = MNManager.sharedInstance.getCustomVars()
```

**Objective-C**

```
//Setting CustomVars
NSDictionary *customVars = @{@"var1": @"value1",
@"var2": @"value2"};
[[MNManager sharedInstance] setCustomVarsWithCustomVars:customVars];

//Retrieving CustomVars
NSDictionary *previouslySetCustomVars = [[MNManager sharedInstance] getCustomVars];
```

# Custom Tags #

You can set custom tags that will be included in all server calls.  You can also retrieve any existing tags that have been set.

**Swift**

```
// Setting CustomTags
let customTags = ["tag1", "tag2", "tag3"]
MNManager.sharedInstance.setTags(customTags)

// Gettings CustomTags
let existingTags = MNManager.sharedInstance.getTags()
```

**Objective-C**

```
// Setting CustomTags
NSArray *customTags = @[@"tag2", @"tag2", @"tag3"];
[[MNManager sharedInstance] setTagsWithTags:customTags];

// Retrieving CustomTags
NSArray *existingCustomTags = [[MNManager sharedInstance] getTags];
```

# Demographics #

You can add demographics information to the server calls, and retrieve any previously set demographics.

**Swift**

```
// Creating and Setting Demographics
let demographics = MNDemographics()
demographics.education = MNEducation.COLLEGE
demographics.ethnicity = MNEthnicity.CAUSASIAN
demographics.gender = MNGender.MALE
demographics.income = MNIncomeRange.RANGE_$100001_
demographics.maritalStatus = MNMaritalStatus.MARRIED
demographics.numberOfKids = 1
demographics.birthday = "1983-09-28"
demographics.lang = NSLocale.preferredLanguages()[0]

MNManager.sharedInstance.setDemographics(demographics)

// Retrieving any previously stored demographics (if available)
let existingDemographics = MNManager.sharedInstance.getDemographics()

// To remove a currently set demographic, some can set to nil, others use the NOT_SET enum.
existingDemographics?.birthday = nil
existingDemographics?.education = MNEducation.NOT_SET
```

**Objective-C**

```
// Settings demographics information
MNDemographics *demographics = [[MNDemographics alloc] init];
demographics.education = MNEducationCollege;
demographics.ethnicity = MNEthnicityAsian;
demographics.gender = MNGenderMale;
demographics.income = MNIncomeRangeRange_$100001_;
demographics.maritalStatus = MNMaritalStatusMarried;
demographics.numberOfKids = [NSNumber numberWithInt:1];
demographics.birthday = @"1983-09-28";
demographics.lang = [[NSLocale preferredLanguages] objectAtIndex:0];

[[MNManager sharedInstance] setDemographicsWithDemographics:demographics];

// Retrieving demographics
MNDemographics *existingDemographics = [[MNManager sharedInstance] getDemographics];

// To remove a currently set demographic, some can set to nil, others use the NOT_SET enum.
existingDemographics.education = MNEducationNot_SET;
```

# Custom Events #

The iOS SDK currently does not support custom events.  If you would like to make use of this functionality, please contact Mobiquity Networks Inc.

# Compatibility with location based apps and third party SDKs #

iOS only allows monitoring up to 20 regions (BeaconRegions or Geofences) by application. Therefore the MNNotifications SDK monitors a maximum of 6 regions simultaneously as a way to improve coexistence with third party SDKs that use Core Location, or integration in apps that also use that iOS Framework.

To optimize the use of geofences, the SDK makes use of the user location to load only the nearest ones, as monitoring all geofences at the same time is not possible due to the limitations and far from good practice.

The MNNotifications SDK adds the prefix Mobiquity_ to its monitored regions (both beacon and geofence). If you use another SDK or CoreLocation in your app, please ensure these regions are not modified in any way.

# IDFA Use #

This framework makes extensive use of the Apple's advertising identifier by default. This identifier is unique to each device and therefore Apple supervises how the developers are using it in their apps. You will need to indicate it in the last phase of your app App Store submit, in the section titled Advertising Identifier

# Sample Application #

The Example App directory in the repository's root contains the source code for a basic functionality app that shows a way to integrate the SDK into your application. You can use it as a starting point for your integration process, and as a basic testing application adding your provided App Key and Secret.

# License #

Mobiquity Technologies, Inc. All rights reserved. See the LICENSE file for more info.

# Release Notes #
* **2.7**
    * Added new event tracking
* **2.6**
    * Lower battery usage
    * Further improvements to location accuracy
    * iOS 11/Xcode 9/Swift 4 support
* **2.5.2**
    * Re-Release 2.5.1 as Fat Framework
* **2.5.1**
    * Improved device tracking
* **2.5**
    * Improved location accuracy
    * Increased location data points
    * Optimized energy management
    * Various minor bug fixes
* **2.1.2**
    * Bug Fix
* **2.1.1**
    * Fix for issue found in field with PersistentStoreCoordinator creation.
* **2.1.0**
    * Re-Release of 2.0 Supporting Swift 3.1
* **2.0.0**
    * Initial 2.0 Release Supporting Swift 2.2
