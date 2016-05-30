//
//  MNUser.h
//  MNProximityManager
//
//  Created by Alberto on 23/01/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MNUserAudience.h"

/**
 * A C enum that hold User role types.
 * @since v1.0 
 */
typedef NS_ENUM(NSUInteger, MNUserRoleType) {
    /** Final User */
    MNUserRoleTypeFinalUser,
    /** Developer */
    MNUserRoleTypeDeveloper,
    /** Tester */
    MNUserRoleTypeTester
};

/**
 * MNUser models a final user. It's used for stats and the role type is used for the campaigns associted to beacons.
 */
@interface MNUser : NSObject <NSCopying>

/**
 * User name
 * @since v1.0 
 * @deprecated No longer used in Mobiquity Panel, has no effect in SDK state
 */
@property (nonatomic, copy) NSString *username  __attribute__((deprecated("No longer used in Mobiquity Panel")));

/**
 * Authentication provider
 * @since v1.0 
 * @deprecated No longer used in Mobiquity Panel, has no effect in SDK state
 */
@property (nonatomic, copy) NSString *authProvider  __attribute__((deprecated("No longer used in Mobiquity Panel")));

/**
 * Role type, used to getting campaigns associated to beacons. For a list of possible values, see the <MNUserRoleType> type.
 * @since v1.0 
 */
@property (nonatomic, assign) MNUserRoleType roleType;

/**
 * Role type, as a String
 * @since v1.0 
 */
//@property (nonatomic, readonly) NSString *roleTypeString;

/**
 * User Target
 * @since v1.0 
 */
@property (nonatomic, strong) MNUserAudience *userAudience;

/**
 * Init method
 * @param username User name, for stats
 * @since v1.0 
 * @deprecated Username no longer used in Mobiquity Panel, has no effect in SDK state, use the -init initializer instead.
 */
- (instancetype) initWithUserName:(NSString *)username __attribute__((deprecated("Username no longer used by the platform, use the -init initializer instead")));

/**
 * Init method
 * @param username User name, for stats
 * @param authProvider Authentication provider, for stats
 * @since v1.0 
 * @deprecated Username and authProvider no longer used in Mobiquity Panel, have no effect in SDK state, use the -init initializer instead.
 */
- (instancetype) initWithUserName:(NSString *)username authProvider:(NSString *)authProvider __attribute__((deprecated("Username and authProvider no longer used by the platform, use the -init initializer instead")));

/**
 * Init method
 * @param username User name, for stats
 * @param authProvider Authentication provider, for stats
 * @param roleType Role type, used to getting campaigns associated to beacons. For a list of possible values, see the <MNUserRoleType> type.
 * @since v1.0 
 * @deprecated Username and authProvider no longer used in Mobiquity Panel, have no effect in SDK state, use the -init or -initWithRoleType  initializers instead.
 */
- (instancetype) initWithUserName:(NSString *)username authProvider:(NSString *)authProvider roleType:(MNUserRoleType)roleType __attribute__((deprecated("Username and authProvider no longer used by the platform, use the -init initializer instead")));

/**
 * Init method. Designated initializer
 * @param roleType Role type, used to getting campaigns associated to beacons. For a list of possible values, see the <MNUserRoleType> type.
 * @since v1.0 
 */
- (instancetype) initWithRoleType:(MNUserRoleType)roleType;

@end
