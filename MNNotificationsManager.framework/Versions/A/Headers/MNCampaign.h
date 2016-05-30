//
//  MNCampaign.h
//  MNProximityManager
//
//  Created by Alberto Salas on 23/01/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * MNCampaign models a campaign and contains information about it and a list of <MNResource>
 *
 * @note Equality based on the identifier
 */
@interface MNCampaign : NSObject

/**
 * Campaign identifier
 * @since v1.0 
 */
@property (nonatomic, strong, readonly) NSString *identifier;

@end
