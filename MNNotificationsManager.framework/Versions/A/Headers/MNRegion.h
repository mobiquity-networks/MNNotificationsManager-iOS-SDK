//
//  MNRegion.h
//  MNProximityManager
//
//  Created by Alberto Salas on 23/01/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A C enum that hold region state information. See [CLRegion CLRegionState](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLRegion_class/Reference/Reference.html)
 *
 * @since v1.0 
 */
typedef NS_ENUM(NSInteger, MNRegionState) {
    /** It is unknown whether the location is inside or outside of the region. */
    MNRegionStateUnknown,
    /** The location is inside the given region. */
    MNRegionStateInside,
    /** The location is outside of the given region. */
    MNRegionStateOutside
};

/**
 * MNRegion models a region. It's the abstract superclass for beaconregions and geofences, so it shouldn't be instanciated.
 *
 * @note Equality based on the identifier
 */
@interface MNRegion : NSObject

/**
 * Identifier of the region
 * @since v1.0 
 */
@property (nonatomic, strong, readonly) NSString *identifier;

@end
