//
//  MNVersionProtocol.h
//  MNProximityManager
//
//  Created by Alberto Salas on 27/03/15.
//  Copyright (c) 2015 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MNVersionProtocol <NSObject>

/**
 * SDK Name
 */
- (NSString *) sdkName;

/**
 * Build Version
 */
- (NSUInteger) build;

/**
 * Commit
 */
- (NSString *) commit;

/**
 * Marketing Version
 */
- (NSString *) marketingVersion;

@end
