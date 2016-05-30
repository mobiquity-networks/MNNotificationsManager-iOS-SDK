//
//  MNPOI.h
//  MNProximityManager
//
//  Created by Alberto Salas on 05/09/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MNPOI models a Point Of Interest
 */
@interface MNPOI : NSObject

/**
 *  MNPOI's indentifier
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  MNPOI's name
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 *  MNPOI's type
 */
@property (nonatomic, strong, readonly) NSString *type;

@end
