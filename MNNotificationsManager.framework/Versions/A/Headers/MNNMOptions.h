//
//  MNNMOptions.h
//  MNNotificationsManager
//
//  Created by Alberto Salas on 04/11/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A MNNMOptions instance provides a container for customization options that the developer can set-up to customize the runtime
 * operation of notificationsManager
 */
@interface MNNMOptions : NSObject

/**
 *  Stats - Custom dictionary composed of NSString keys and values to associate with usage stats
 *
 *  @since 1.0
 */
@property (nonatomic, strong) NSDictionary *statsTrackingValues;


@end
