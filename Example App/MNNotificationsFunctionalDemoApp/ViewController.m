//
//  ViewController.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//


#import "ViewController.h"
#import "MNNotificationsManagerCustomDelegate.h"

@interface ViewController ()


@property (nonatomic, strong) MNNotificationsManagerCustomDelegate *notificationsDelegate;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self notificationsManagerInitialization];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}


- (void)notificationsManagerInitialization
{
    // We instance an especific object dedicated to act as the delegate to Notifications Manager main ob
    MNNotificationsManagerCustomDelegate *customDelegate = [[MNNotificationsManagerCustomDelegate alloc] init];

    // We instance the object containing the app key and secret needed to use the SDK
    MNAppKey *appKey = [[MNAppKey alloc] initWithAppKey:@"providedAppKey" andSecretKey:@"providedAppSecret"];
    
    // Here we could instance custom MNUser and MNNMOptions objects to provide additional information for the Notifications Manager operation
    
    // Notifications Manager asynchronous initialization
    [MNNotificationsManager notificationsManagerWithAppKey:appKey
                                                   options:nil
                                                      user:nil
                                                  delegate:customDelegate
                                         completionHandler:^(MNNotificationsManager *notificationsManager, NSError *error) {
                                             if (!error) {
                                                 // If initialization ended without errors, we start the SDK
                                                 [notificationsManager start];
                                                 // and keep strong references to the manager and its delegate object
                                                 self.notificationsManager = notificationsManager;
                                                 self.notificationsDelegate = customDelegate;
                                             } else {
                                                 NSLog(@"Error : %@",error.localizedDescription);
                                             }
                                         }];
    

}

@end
