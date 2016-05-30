//
//  MNStat.h
//  MNProximityDomain
//
//  Created by Alberto Salas on 07/11/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MNStatValue.h"
#import "MNStatTypes.h"

@interface MNStat : NSObject

@property (nonatomic, assign, readonly) MNStatType type;

@property (nonatomic, strong, readonly) MNStatValue *value;

@property (nonatomic, strong, readonly) NSDate *timestamp;

- (instancetype) initWithType:(MNStatType)type value:(MNStatValue *)value timestamp:(NSDate *)timestamp;
+ (instancetype) statWithType:(MNStatType)type value:(MNStatValue *)value timestamp:(NSDate *)timestamp;

- (instancetype) initWithType:(MNStatType)type value:(MNStatValue *)value;
+ (instancetype) statWithType:(MNStatType)type value:(MNStatValue *)value;

- (instancetype) initWithType:(MNStatType)type object:(id)object;
+ (instancetype) statWithType:(MNStatType)type object:(id)object;

@end
