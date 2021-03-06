// Generated by Apple Swift version 4.1 (swiftlang-902.0.48 clang-902.0.37.1)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR __attribute__((enum_extensibility(open)))
# else
#  define SWIFT_ENUM_ATTR
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import CoreLocation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="MNNotifications",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSCoder;

SWIFT_CLASS("_TtC15MNNotifications8MNBeacon")
@interface MNBeacon : NSObject <NSCoding>
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * _Nonnull)aCoder;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end

@class MNBeaconSignal;
@class MNVenue;
@class MNPOI;

SWIFT_CLASS("_TtC15MNNotifications22MNBeaconLocationSignal")
@interface MNBeaconLocationSignal : NSObject
@property (nonatomic, strong) MNBeaconSignal * _Nullable beacon;
@property (nonatomic, strong) MNVenue * _Nullable venue;
@property (nonatomic, copy) NSArray<MNPOI *> * _Nullable nearPOIs;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class MNProximity;

SWIFT_CLASS("_TtC15MNNotifications14MNBeaconSignal")
@interface MNBeaconSignal : NSObject
@property (nonatomic, copy) NSString * _Nullable uuid;
@property (nonatomic, copy) NSString * _Nullable regionId;
@property (nonatomic, strong) MNProximity * _Nullable proximity;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15MNNotifications12MNCustomVars")
@interface MNCustomVars : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end

@class NSNumber;
enum MNEducation : NSInteger;
enum MNIncomeRange : NSInteger;
enum MNGender : NSInteger;
enum MNMaritalStatus : NSInteger;
enum MNEthnicity : NSInteger;

SWIFT_CLASS("_TtC15MNNotifications14MNDemographics")
@interface MNDemographics : NSObject <NSCoding>
@property (nonatomic, strong) NSNumber * _Nullable numberOfKids;
@property (nonatomic) enum MNEducation education;
@property (nonatomic) enum MNIncomeRange income;
@property (nonatomic) enum MNGender gender;
@property (nonatomic) enum MNMaritalStatus maritalStatus;
@property (nonatomic) enum MNEthnicity ethnicity;
@property (nonatomic, copy) NSString * _Nullable birthday;
@property (nonatomic, copy) NSString * _Nullable lang;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNumberOfKids:(NSNumber * _Nullable)numberOfKids education:(enum MNEducation)education income:(enum MNIncomeRange)income gender:(enum MNGender)gender maritalStatus:(enum MNMaritalStatus)maritalStatus ethnicity:(enum MNEthnicity)ethnicity birthday:(NSString * _Nullable)birthday lang:(NSString * _Nullable)lang OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * _Nonnull)aCoder;
@end

typedef SWIFT_ENUM(NSInteger, MNEducation) {
  MNEducationCollege = 0,
  MNEducationGrad_SCHOOL = 1,
  MNEducationNon_COLLEGE = 2,
  MNEducationNot_SET = 3,
};

typedef SWIFT_ENUM(NSInteger, MNEthnicity) {
  MNEthnicityAsian = 0,
  MNEthnicityAfrican_AMERICAN = 1,
  MNEthnicityCausasian = 2,
  MNEthnicityHispanic = 3,
  MNEthnicityNot_SET = 4,
};

typedef SWIFT_ENUM(NSInteger, MNGender) {
  MNGenderMale = 0,
  MNGenderFemale = 1,
  MNGenderNot_SET = 2,
};

typedef SWIFT_ENUM(NSInteger, MNIncomeRange) {
  MNIncomeRangeRange_$0_$30000 = 0,
  MNIncomeRangeRange_$30001_$60000 = 1,
  MNIncomeRangeRange_$60001_$100000 = 2,
  MNIncomeRangeRange_$100001_ = 3,
  MNIncomeRangeNot_SET = 4,
};

@protocol MNNotificationsDelegate;
@class UILocalNotification;

SWIFT_CLASS("_TtC15MNNotifications9MNManager")
@interface MNManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) MNManager * _Nonnull sharedInstance;)
+ (MNManager * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, strong) id <MNNotificationsDelegate> _Nullable delegate;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
- (void)startSDK;
- (void)setDemographicsWithDemographics:(MNDemographics * _Nonnull)demographics;
- (MNDemographics * _Nullable)getDemographics SWIFT_WARN_UNUSED_RESULT;
- (void)setCustomVarsWithCustomVars:(NSDictionary<NSString *, NSString *> * _Nonnull)customVars;
- (NSDictionary<NSString *, NSString *> * _Nullable)getCustomVars SWIFT_WARN_UNUSED_RESULT;
- (void)setTagsWithTags:(NSArray<NSString *> * _Nonnull)tags;
- (NSArray<NSString *> * _Nullable)getTags SWIFT_WARN_UNUSED_RESULT;
- (void)disabledSDK;
- (void)enabledSDK;
- (void)processLocalNotificationWithNotification:(UILocalNotification * _Nonnull)notification;
- (BOOL)isMNNotificationWithNotification:(UILocalNotification * _Nonnull)notification SWIFT_WARN_UNUSED_RESULT;
- (void)blacklistBeaconUUIDsWithBeaconUUIDs:(NSArray<NSString *> * _Nonnull)beaconUUIDs;
- (NSArray<NSString *> * _Nullable)getBeaconUUIDBlacklist SWIFT_WARN_UNUSED_RESULT;
@end

typedef SWIFT_ENUM(NSInteger, MNManagerErrorCodes) {
  MNManagerErrorCodesPlist_ERROR = 0,
  MNManagerErrorCodesLocation_SERVICES_ERROR = 1,
  MNManagerErrorCodesDeeplink_ERROR = 2,
  MNManagerErrorCodesGeneric_ERROR = 3,
};

typedef SWIFT_ENUM(NSInteger, MNMaritalStatus) {
  MNMaritalStatusMarried = 0,
  MNMaritalStatusSingle = 1,
  MNMaritalStatusNot_SET = 2,
};

@class NSError;

SWIFT_PROTOCOL("_TtP15MNNotifications23MNNotificationsDelegate_")
@protocol MNNotificationsDelegate
@optional
- (void)mnManagerDidRangeBeaconWithBeaconLocationSignal:(MNBeaconLocationSignal * _Nonnull)beaconLocationSignal;
- (void)mnManagerDidChangeAuthorizationStatusWithStatus:(CLAuthorizationStatus)status;
- (void)mnManagerDidPowerOffBluetooth;
- (void)mnManagerDidFailWithErrorWithError:(NSError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC15MNNotifications5MNPOI")
@interface MNPOI : NSObject
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15MNNotifications11MNProximity")
@interface MNProximity : NSObject <NSCoding>
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * _Nonnull)aCoder;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15MNNotifications7MNVenue")
@interface MNVenue : NSObject
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
