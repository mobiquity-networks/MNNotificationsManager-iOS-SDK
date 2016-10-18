//
//  MNLocation.h
//  MNProximityDomain
//
//  Created by Alberto Salas on 24/03/15.
//  Copyright (c) 2015 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MNVenue.h"
#import "MNPOI.h"


@interface MNLocation : NSObject

@property (nonatomic, strong) MNVenue *venue;

@property (nonatomic, strong) NSArray *nearPOIs;

@end
