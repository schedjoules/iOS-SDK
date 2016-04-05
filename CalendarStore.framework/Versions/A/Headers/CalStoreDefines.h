//
//  CalStoreDefines.h
//  CalendarStore
//
//  Created by SchedJoules on 29-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

typedef NS_ENUM(NSUInteger, CalStoreCategory)
{
	CalStoreCategoryHoliday		= 1,
	CalStoreCategorySport		= 2,
	CalStoreCategoryWeather		= 3,
	CalStoreCategoryFinance		= 4,
	CalStoreCategoryOther		= 5,
};


typedef NS_ENUM(NSInteger, CalStoreDebugLevel)
{
	CalStoreDebugLevelNone		= -1, // no output
	CalStoreDebugLevelErrors	= 0,  // errors only
	CalStoreDebugLevelWarnings	= 1,  // errors and warnings only
	CalStoreDebugLevelAll		= 2,  // output as much debug info as needed
};


typedef NS_ENUM(NSUInteger, CalStorePageType)
{
	CalStorePageTypeRegular			= 0, // regular page
	CalStorePageTypeSearchResults	= 1, // page returned in results of a search
};

typedef NS_ENUM(NSUInteger, CalStoreContentMode)
{
	CalStoreContentModeProduction	= 0, // the content is for production, live mode
	CalStoreContentModeTesting		= 1, // the content is for testing purposes only
};

// ====================================
// Errors
// ====================================
extern NSString* const CalStoreErrorDomain;
extern const NSInteger CalStoreErrorAuthorizationTokenMissing;
extern const NSInteger CalStoreErrorAuthorizationTokenNotAccepted;
extern const NSInteger CalStoreErrorOSVersionNotSupported;
extern const NSInteger CalStoreErrorHttpRequest;
extern const NSInteger CalStoreErrorUrlNotAllParametersAreSupplied;

extern NSString* const CalStoreErrorHttpStatusCodeKey; // NSNumber (integerValue)

//=====================================
// posted when network activity started / stopped
//=====================================
extern NSString* const kCalStoreNetworkActivityStartedNotification;
extern NSString* const kCalStoreNetworkActivityStoppedNotification;


// ====================================
// AuthorizationToken
// ====================================
extern NSString* const kCalStoreCalendarStoreAuthorizationTokenKey; // Info.plist authorizationToken key, CalendarStoreAuthorizationToken



// ====================================
// Support EmailAddress
// ====================================
extern NSString* const kCalStoreCalendarStoreFeedbackEmailAddressKey; // Info.plist feedbackEmailAddress key, CalendarStoreFeedbackEmailAddress

// ====================================
// iCloud Support
// ====================================
extern NSString* const kCalStoreCalendarStoreiCloudSyncEnabled; // Info.plist iCloudSyncEnabled key, CalendarStoreiCloudSyncEnabled (BOOLEAN, YES/NO)


// ====================================
// Ordering
// ====================================
extern NSString* const kCalStoreOrderStatusChangedNotification;
extern NSString* const kCalStoreOrderStatusChangedIdentifierKey; // identifiers
extern NSString* const kCalStoreRestoringPurchasesStatusChangedNotification;
extern NSString* const kCalStoreOrderStatusRefreshAllNotification; // send when all data potentially has changed, do a full UI refresh

// ====================================
// Calendar Subscription Events.
// ====================================

// notification send when an calendar subscription has been installed
// and we recognized it as an EKCalendar, the userInfo
// will contain an Item and a CalendarIdentifier key holding the calendarIdentifier
// of the EKCalendar just installed.
extern NSString* const kCalStoreEKCalendarSubscriptionInstalledNotification;
extern NSString* const kCalStoreEKCalendarSubscriptionInstalledItemKey; // the key in the userInfo dictionary that points to the calendarItem just installed
extern NSString* const kCalStoreEKCalendarSubscriptionInstalledCalendarIdentifierKey; // the key in the userInfo dictionary for the EKCalendar.calendarIdentifier just installed
