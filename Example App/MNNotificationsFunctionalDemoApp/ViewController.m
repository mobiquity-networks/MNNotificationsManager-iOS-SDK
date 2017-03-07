//
//  ViewController.m
//  MNNotificationsFunctionalDemoApp
//
//  Created by Jesus on 17/12/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//


#import "ViewController.h"
#import "MNNotificationsDelegate.h"

@interface ViewController ()

@property (nonatomic, strong) MNNotificationsDelegate *notificationsDelegate;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [MNManager sharedInstance].delegate = self.notificationsDelegate;
    [[MNManager sharedInstance] startSDK];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
