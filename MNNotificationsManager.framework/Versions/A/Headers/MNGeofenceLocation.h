//
//  MNGeofenceLocation.h
//  MNProximityDomain
//
//  Created by Jesus on 31/8/16.
//  Copyright © 2016 Mobiquity Networks. All rights reserved.
//

#import "MNLocation.h"
@class MNGeofence;

@interface MNGeofenceLocation : MNLocation

@property (nonatomic, strong) MNGeofence *geofence;

@end
