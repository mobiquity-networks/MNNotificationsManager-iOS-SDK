//
//  AppDelegate.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import "AppDelegate.h"
#import <MNNotifications/MNNotifications-Swift.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    UILocalNotification *notification = launchOptions[UIApplicationLaunchOptionsLocalNotificationKey];
    
    if (notification) {
        [self application:application didReceiveLocalNotification:notification];
    }
    
    return YES;
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    // Notifications Manager SDK makes use of local notifications to show alerts to the user.
    if ([[MNManager sharedInstance] isMNNotification:notification]) {
        NSLog(@"This Notification belongs to the MNNotifications SDK, it should be passed to it to be handled.");
        [[MNManager sharedInstance] processLocalNotification:notification];
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

@end
