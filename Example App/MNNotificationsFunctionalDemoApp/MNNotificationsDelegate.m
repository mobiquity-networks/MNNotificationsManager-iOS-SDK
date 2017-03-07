//
//  MNNotificationsManagerCustomDelegate.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import "MNNotificationsDelegate.h"
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>


@implementation MNNotificationsDelegate

- (void)mnManagerDidRangeBeacon:(MNBeaconLocationSignal * _Nonnull)beaconLocationSignal {
    NSLog(@"The SDK saw a known beacon, you can retrieve information such as venue from the MNBeaconLocationSignal.");
}

- (void)mnManagerDidChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    NSLog(@"The Authorization state just changed to either Denied or Restricted. You should prompt your user to change it back.");
}

- (void)mnManagerDidChangeBluetoothState:(CBCentralManagerState)state {
    NSLog(@"The Bluetooth on the deviec was just de-activated.  You might want to prompt your user to turn it back on.");
}

- (void)mnManagerDidFailWithError:(NSError * _Nonnull)error {
    NSLog(@"The MNNotifications SDK ran into some issues. The errors reported here will be able to be rectified by you. These include things such as incorrect or missing App Key and Secret.");
}

@end
