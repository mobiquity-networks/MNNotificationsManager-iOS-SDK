//
//  MNVenue.h
//  MNProximityManager
//
//  Created by Alberto Salas on 05/09/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MNVenue models a venue
 */
@interface MNVenue : NSObject

/**
 *  MNVenue's indentifier
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  MNVenue's name
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 *  MNVenue's type
 */
@property (nonatomic, strong, readonly) NSString *type;

@end
