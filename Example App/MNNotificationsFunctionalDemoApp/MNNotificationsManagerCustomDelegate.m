//
//  MNNotificationsManagerCustomDelegate.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import "MNNotificationsManagerCustomDelegate.h"


@implementation MNNotificationsManagerCustomDelegate

- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didChangeAuthorizationStatus:(MNPMAuthorizationStatus)status
{
    NSLog(@"Auth status did change: %ld",status);
}


- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didChangeBluetoothState:(MNPMBluetoothState)state
{
    NSLog(@"Bluetooth status did change: %ld",state);
}

@end
