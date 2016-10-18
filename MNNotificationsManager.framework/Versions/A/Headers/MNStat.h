//
//  MNStat.h
//  MNProximityDomain
//
//  Created by Alberto Salas on 07/11/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MNStatValue.h"
#import "MNStatTypes.h"
#import "MNPMUserLocation.h"

@interface MNStatContext : NSObject

@property (nonatomic, strong, readonly) NSDate *timestamp;

@property (nonatomic, strong, readonly) MNPMUserLocation *userLocation;

@property (nonatomic, assign, readonly) NSNumber *appState;

+ (instancetype) statContextWithTimestamp:(NSDate *)timestamp userLocation:(MNPMUserLocation *)userLocation appState:(NSNumber *)appState;

@end

@interface MNStat : NSObject

@property (nonatomic, assign, readonly) MNStatType type;

@property (nonatomic, strong, readonly) MNStatValue *value;

@property (nonatomic, strong, readonly) MNStatContext *context;

+ (instancetype) statWithType:(MNStatType)type value:(MNStatValue *)value context:(MNStatContext *)context;
+ (instancetype) statWithType:(MNStatType)type object:(id)object context:(MNStatContext *)context;

@end
