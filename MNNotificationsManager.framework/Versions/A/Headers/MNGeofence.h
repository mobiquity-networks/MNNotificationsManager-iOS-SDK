//
//  MNGeofence.h
//  MNProximityManager
//
//  Created by Alberto Salas on 27/03/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import "MNRegion.h"
#import "MNCampaign.h"
#import "MNGeofenceLocation.h"

/**
 * MNGeofence models a geofence with a geographic center and radius.
 */
@interface MNGeofence : MNRegion

/**
 * The latitude in degrees. Positive values indicate latitudes north of the equator. Negative values indicate latitudes south of the equator.
 */
@property (nonatomic, assign, readonly) double latitude;

/**
 * The longitude in degrees. Measurements are relative to the zero meridian, with positive values extending east of the meridian and negative values extending west of the meridian.
 */
@property (nonatomic, assign, readonly) double longitude;

/**
 * The radius (measured in meters) that defines the geographic area’s outer boundary.
 */
@property (nonatomic, assign, readonly) double radius;

/**
 * The type of the geofence.
 */
@property (nonatomic, strong, readonly) NSString *type;

/**
 * The name of the geofence.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 * Async request for the associated campaigns
 * @param block Completion block with the associated campaigns or an error
 * @since v1.0 
 */
- (void) campaignsWithBlock:(void (^)(NSArray *campaigns, NSError *error))block;

/**
 * Async request for the associated location
 * @param block Completion block with the associated location or an error
 * @since v2.0
 */
- (void) locationWithBlock:(void (^)(MNGeofenceLocation *, NSError *))block;

@end
