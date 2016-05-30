//
//  MNBeaconRegion.h
//  MNProximityManager
//
//  Created by Alberto Salas on 31/01/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MNRegion.h"

/**
 * MNBeaconRegion models a Beacon Region. It's similar to the Beacon UUID but UUID could be changed eventually. Anyway you shouldn't store any reference to a <MNBeaconRegion>, use it only for chain events and method calls.
 */
@interface MNBeaconRegion : MNRegion

/**
 *  If True, sdk should query to server for related info (location, campaigns...)
 *  If false, sdk should not do it.
 *
 *  @since TODO
 */
@property (nonatomic, assign, readonly) BOOL hasInfo;

@end
