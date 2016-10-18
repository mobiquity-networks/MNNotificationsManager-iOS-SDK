//
//  MNNotificationManagerDelegate.h
//  MNNotificationsManager
//
//  Created by Alberto Salas on 04/11/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MNProximityManagerDataTypes.h"
#import "MNNMGeoInfo.h"
#import "MNNMBeaconLocationSignal.h"
#import "MNNMGeofenceLocationSignal.h"

@class MNNotificationsManager;

/**
 * MNNotificationsManagerDelegate is the protocol to implement in order to respond to status events related to <MNNotificationsManager>. It's designed to inform about status changes in device systems used by Notifications Manager.
 *
 */
@protocol MNNotificationsManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that the authorization status for the application changed. See [CLLocationManagerDelegate locationManager:didChangeAuthorizationStatus:](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManagerDelegate_Protocol/CLLocationManagerDelegate/CLLocationManagerDelegate.html)
 *
 * @param notificationsManager The notificationsManager object reporting the event.
 *
 * @param status The new authorization status for the application. For a list of possible values, see the <MNNMAuthorizationStatus> type.
 *
 * @discussion This method is called whenever the application’s ability to use location services changes. Changes can occur because the user allowed or denied the use of location services for your application or for the system as a whole.
 *
 * @since v1.0
 */
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didChangeAuthorizationStatus:(MNPMAuthorizationStatus)status;

/**
 * Tells the delegate that the bluetooth status has changed. See [CBCentralManagerDelegate centralManagerDidUpdateState:](https://developer.apple.com/library/mac/documentation/CoreBluetooth/Reference/CBCentralManagerDelegate_Protocol/translated_content/CBCentralManagerDelegate.html)
 *
 * @param notificationsManager The notificationsManager object reporting the event.
 *
 * @param state The new bluetooth state. For a list of possible values, see the <MNNMBluetoothState> type.
 *
 * @since v1.0
 */
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didChangeBluetoothState:(MNPMBluetoothState)state;

/**
 * Tells the delegate that it has discovered geographical info of interest for the client in the current localization.
 *
 * @param notificationsManager The notificationsManager object reporting the event.
 *
 * @param geoInfo A MNNMGeoInfo instance object containing information about the found place of interest.
 *
 * @since v1.1
 *
 * @deprecated v1.2
 *
 */
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager didDiscoveredGeoInfo:(MNNMGeoInfo *)geoInfo __attribute((deprecated("use notificationsManager:beaconLocationSignal: instead")));

/**
 * Tells the delegate that it has discovered a location of interest for the client in the current localization.
 *
 * @param notificationsManager The notificationsManager object reporting the event.
 *
 * @param beaconLocation A MNNMBeaconLocation instance object containing information about the found place of interest.
 *
 * @since v1.2
 *
 */
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager beaconLocationSignal:(MNNMBeaconLocationSignal *)beaconLocationSignal;

/**
 * Tells the delegate that it has discovered a location of interest for the client in the current localization.
 *
 * @param notificationsManager The notificationsManager object reporting the event.
 *
 * @param geofenceLocationSignal A MNNMGeofenceLocation instance object containing information about the found place of interest.
 *
 * @since v1.3.0
 *
 */
- (void) notificationsManager:(MNNotificationsManager *)notificationsManager geofenceLocationSignal:(MNNMGeofenceLocationSignal *)geofenceLocationSignal;

@end