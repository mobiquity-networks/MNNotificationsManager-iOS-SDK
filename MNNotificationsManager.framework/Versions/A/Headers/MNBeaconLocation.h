//
//  MNBeaconLocation.h
//  MNProximityDomain
//
//  Created by Alberto Salas on 24/03/15.
//  Copyright (c) 2015 Mobiquity Networks. All rights reserved.
//

#import "MNLocation.h"
#import "MNVenue.h"
#import "MNPOI.h"

@interface MNBeaconLocation : MNLocation

@property (nonatomic, strong) MNVenue *venue;

@property (nonatomic, strong) NSArray *nearPOIs;

@end
