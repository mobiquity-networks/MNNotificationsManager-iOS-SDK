//
//  MNUserTarget.h
//  MNProximityManager
//
//  Created by Alberto Salas on 14/04/14.
//  Copyright (c) 2014 Mobiquity Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString* const kMNUserAudienceGenderMale = @"M";
static NSString* const kMNUserAudienceGenderFemale = @"F";

static NSString* const kMNUserAudienceEducationCollege = @"CLL";
static NSString* const kMNUserAudienceEducationGradSchool = @"GS";
static NSString* const kMNUserAudienceEducationNoCollege = @"NCLL";

static NSString* const kMNUserAudienceEthnicityAfricanAmerican = @"AA";
static NSString* const kMNUserAudienceEthnicityAsian = @"AS";
static NSString* const kMNUserAudienceEthnicityCaucasian = @"CC";
static NSString* const kMNUserAudienceEthnicityHispanic = @"HP";

static NSString* const kMNUserAudienceIncomeUpTo30k = @"R_00_30";
static NSString* const kMNUserAudienceIncome30k60k = @"R_30_60";
static NSString* const kMNUserAudienceIncome60k100k = @"R_60_100";
static NSString* const kMNUserAudienceIncomeOver100k = @"R_100_";

static NSString* const kMNUserAudienceMaritalStatusSingle = @"SG";
static NSString* const kMNUserAudienceMaritalStatusMarried = @"MD";

/**
 * MNUserAudience models the user profile.
 */
@interface MNUserAudience : NSObject <NSCopying>

/**
 * User Age
 */
@property (nonatomic, strong) NSDate *birthday;

/**
 * User Genre
 */
@property (nonatomic, strong) NSString *gender;

/**
 * User Education
 */
@property (nonatomic, strong) NSString *education;

/**
 * User Ethnicity
 */
@property (nonatomic, strong) NSString *ethnicity;

/**
 * User Income
 */
@property (nonatomic, strong) NSString *income;

/**
 * User Kids
 */
@property (nonatomic, assign) NSUInteger kids;

/**
 * User Marital Status
 */
@property (nonatomic, strong) NSString *maritalStatus;

/**
 * User preferred language as a 639-1 ISO code. If not available under that spec,
 * use the 639-2 ISO code.
 */
@property (nonatomic, strong) NSString *language;

/**
 * An array of NSString objects representing custom tags to associate with the 
 * user.
 */
@property (nonatomic, strong) NSArray *tags;

@end
