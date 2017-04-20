//
//  AppDelegate.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    UILocalNotification *notification = launchOptions[UIApplicationLaunchOptionsLocalNotificationKey];
    
    if (notification) {
        [self application:application didReceiveLocalNotification:notification];
    }
    
    [MNManager sharedInstance].delegate = self;
    [[MNManager sharedInstance] startSDK];

    return YES;
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    // Notifications Manager SDK makes use of local notifications to show alerts to the user.
    if ([[MNManager sharedInstance] isMNNotificationWithNotification:notification]) {
        NSLog(@"This Notification belongs to the MNNotifications SDK, it should be passed to it to be handled.");
        [[MNManager sharedInstance] processLocalNotificationWithNotification:notification];
    } else {
        NSLog(@"This Notification does not belong to the MNNotifications SDK.");
    }
}

- (void)applicationWillResignActive:(UIApplication *)application {
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application {

}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

}

- (void)applicationWillTerminate:(UIApplication *)application {

}

- (void)mnManagerDidRangeBeaconWithBeaconLocationSignal:(MNBeaconLocationSignal *)beaconLocationSignal {
    NSLog(@"The SDK saw a known beacon, you can retrieve information such as venue from the MNBeaconLocationSignal.");
}

- (void)mnManagerDidChangeAuthorizationStatusWithStatus:(CLAuthorizationStatus)status {
    NSLog(@"The Authorization state just changed to either Denied or Restricted. You should prompt your user to change it back.");
}

- (void)mnManagerDidPowerOffBluetooth {
    NSLog(@"The Bluetooth on the device was just de-activated.  You might want to prompt your user to turn it back on.");
}

- (void)mnManagerDidFailWithErrorWithError:(NSError *)error {
    NSLog(@"The MNNotifications SDK ran into some issues. The errors reported here will be able to be rectified by you. These include things such as incorrect or missing App Key and Secret.");
}

@end
