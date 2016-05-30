//
//  MNBeacon.h
//  MNProximityManager
//
//  Created by Alberto Salas on 09/01/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MNBeaconRegion.h"
#import "MNCampaign.h"
#import "MNBeaconLocation.h"

/**
 * A C enum that hold Beacon Proximity information. See [CLLocationManager CLProximity](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManagerDelegate_Protocol/CLLocationManagerDelegate/CLLocationManagerDelegate.html).
 *
 * @since v1.0 
 */
typedef NS_ENUM(NSInteger, MNBeaconProximity) {
    /** The proximity of the beacon could not be determined. */
	MNBeaconProximityUnknown,
    /** The beacon is in the user’s immediate vicinity. */
	MNBeaconProximityImmediate,
    /** The beacon is relatively close to the user. */
	MNBeaconProximityNear,
    /** The beacon is far away. */
	MNBeaconProximityFar
};

/**
 * The MNBeacon class represents a beacon that was encountered during region ranging. You do not create instances of this class directly. The proximityManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
 *
 * The identity of a beacon is defined by its identifier property because UUID, major and minor of physical beacons could be change eventually.
 *
 * See [CLBeacon Class Reference](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeacon_class/Reference/Reference.html).
 *
 * @note Equality based on the identifier
 */
@interface MNBeacon : NSObject

/**
 * Beacon Identifier
 * @since v1.0 
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 * Beacon Region
 * @since v1.0 
 */
@property (nonatomic, strong, readonly) MNBeaconRegion *region;

/**
 * The relative distance to the beacon as a MNBeaconProximity value.
 * @since v1.0 
 */
@property (nonatomic, assign, readonly) MNBeaconProximity proximity;

/**
 * The relative distance to the beacon as a string.
 * @since v1.0 
 */
@property (nonatomic, strong, readonly) NSString *proximityString;

/**
 * The accuracy of the proximity value, measured in meters from the beacon.
 *
 * @discussion Indicates the one sigma horizontal accuracy in meters. Use this property to differentiate between beacons with the same proximity value. Do not use it to identify a precise location for the beacon. Accuracy values may fluctuate due to RF interference.
 *
 * A negative value in this property signifies that the actual accuracy could not be determined.
 *
 * @since v1.0 
 */
@property (nonatomic, assign, readonly) double accuracy;

/**
 * The received signal strength of the beacon, measured in decibels.
 * @discussion This value is the average RSSI value of the samples received since the range of the beacon was last reported to your app.
 * @since v1.0 
 */
@property (nonatomic, assign, readonly) NSInteger rssi;

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
- (void)locationWithBlock:(void (^)(MNBeaconLocation *, NSError *))block;

@end
