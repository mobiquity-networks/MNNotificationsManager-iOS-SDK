//
//  MNPMUserStat.h
//  MNProximityManager
//
//  Created by Alberto Salas on 11/11/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * MNPMUserStatType Enum
 *
 * @since v2.0 
 */
typedef NS_ENUM(NSUInteger, MNPMUserStatType) {
    
    /**
     * Local Notification Impression Stat
     * Require Campaign and Beacon/Geofence in value
     */
    MNPMUserStatTypeLocalNotificationImpression = 0,
    
    /**
     * Local Notification Clicked Stat
     * Require Campaign and Beacon/Geofence in value
     */
    MNPMUserStatTypeLocalNotificationClicked,
    
    /**
     * Advert Impression Stat
     * Require Advert, Campaign and Beacon/Geofence in value
     */
    MNPMUserStatTypeAdvertImpression,
    
    /**
     * CallToAction Clicked Stat
     * Require CallToAction, Ad, Campaign and Beacon/Geofence in value
     */
    MNPMUserStatTypeCallToActionClicked,
    
    /**
     * SDK Started
     * No attached value required
     */
    MNPMUserStatTypeStarted,
    
    /**
     * SDK Stopped
     * No attached value required
     */
    MNPMUserStatTypeStopped
};

static NSString* const MNPMUserStatValueCampaignKey = @"campaign";
static NSString* const MNPMUserStatValueBeaconKey = @"beacon";
static NSString* const MNPMUserStatValueBeaconRegionKey = @"beaconRegion";
static NSString* const MNPMUserStatValueGeofenceKey = @"geofence";
static NSString* const MNPMUserStatValueAdvertKey = @"advert";
static NSString* const MNPMUserStatValueCallToActionKey = @"callToAction";

@interface MNPMUserStatContext : NSObject

@property (nonatomic, assign, readonly) NSNumber *appState;

+ (instancetype) statContextWithAppState:(UIApplicationState)appState;

@end

@interface MNPMUserStat : NSObject

- (instancetype)initWithUserStatType:(MNPMUserStatType)userStatType value:(NSDictionary *)value;
+ (instancetype)userStatWithUserStatType:(MNPMUserStatType)userStatType value:(NSDictionary *)value;

- (instancetype)initWithUserStatCustomType:(NSString *)customStatType value:(NSDictionary *)value;
+ (instancetype)userStatWithUserStatCustomType:(NSString *)customStatType value:(NSDictionary *)value;

+ (instancetype)userStatWithUserStatType:(MNPMUserStatType)userStatType value:(NSDictionary *)value context:(MNPMUserStatContext *)context;

@end
