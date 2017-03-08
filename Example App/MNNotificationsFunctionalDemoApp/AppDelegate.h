//
//  AppDelegate.h
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MNNotifications/MNNotifications-Swift.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>


@interface AppDelegate : UIResponder <UIApplicationDelegate, MNNotificationsDelegate>

@property (strong, nonatomic) UIWindow *window;

@end

