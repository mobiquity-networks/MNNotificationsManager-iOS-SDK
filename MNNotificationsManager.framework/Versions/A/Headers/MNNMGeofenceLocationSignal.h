//
//  MNNMGeofenceLocationSignal.h
//  MNNotificationsManager
//
//  Created by Jesus on 31/8/16.
//  Copyright © 2016 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MNVenue.h"
#import "MNPOI.h"
#import "MNGeofence.h"

@interface MNNMGeofenceLocationSignal : NSObject

@property (nonatomic, strong, readonly) MNVenue *venue;

@property (nonatomic, strong, readonly) NSArray *nearPOIs;

@property (nonatomic, strong, readonly) MNGeofence *geofence;

@end
