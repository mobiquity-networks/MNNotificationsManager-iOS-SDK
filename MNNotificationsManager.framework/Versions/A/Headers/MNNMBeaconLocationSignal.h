//
//  MNNMBeaconLocation.h
//  MNNotificationsManager
//
//  Created by Alberto Salas on 31/7/15.
//  Copyright (c) 2015 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MNVenue.h"
#import "MNPOI.h"
#import "MNBeacon.h"

@interface MNNMBeaconLocationSignal : NSObject

@property (nonatomic, strong, readonly) MNVenue *venue;

@property (nonatomic, strong, readonly) NSArray *nearPOIs;

@property (nonatomic, strong, readonly) MNBeacon *beacon;

@end
