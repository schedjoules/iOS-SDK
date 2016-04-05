//
//  CalStoreSubscription.h
//  CalendarStore
//
//  Created by Tobias Reinsch on 12.05.15.
//  Copyright (c) 2015 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStorePageItemPurchasable.h"

/**
 The main class for handling the subscription status and purchase workflow.
 There is only instance per app, that manages the access to the CalendarStore items. To get the shared instance use [CalStoreSubscriptionHandler sharedSubscription]
 
 */
@interface CalStoreSubscription : CalStorePageItemPurchasable

extern NSString* const kCalStoreOwnAppSubscriptionProductIdentifierKey;
extern NSString* const kCalStoreOwnAppSubscriptionPurchaseDateKey;
extern NSString* const kCalStoreOwnAppSubscriptionExpirationDateKey;
extern NSString* const kCalStoreOwnAppSubscriptionIdKey;
extern NSString* const kCalStoreOwnAppSubscriptionStatusKey;
extern NSString* const kCalStoreOwnAppSubscriptionUserIdKey;
extern NSString* const kCalStoreOwnAppSubscriptionTransactionIdsKey;
extern NSString* const kCalStoreOwnAppSubscriptionFreeTrialEnabledKey;
extern NSString* const kCalStoreOwnAppSubscriptionLocalizedUpgradeButtonTextKey;
extern NSString* const kCalStoreOwnAppSubscriptionLocalizedPriceInfoKey;


extern NSString* const kCalStoreSubscriptionUpdatedNotification;



/**
 The possible subscription statuses.
 */
enum CSSubscriptionStatus : NSUInteger {
    CSSubscriptionStatusNotPurchased = 404,
    CSSubscriptionStatusPurchasing = 102,
    CSSubscriptionStatusActive = 200,
    CSSubscriptionStatusExpired = 4402,
    CSSubscriptionStatusUnknown = 0
};

/**
 The unique id that identifies a subscripion on the backend. There is only one subscription and therefore one subscriptionId per user.
 This is used to get and update the subscription status hand in hand with the backend.
 */
@property (nonatomic, retain) NSString*         subscriptionId;

/**
 The date when the subscription was purcahsed the last time.
 */
@property (nonatomic, retain) NSDate*           purchaseDate;

/**
 The date when the subscription will expire and the user will loose access to his subscribed calendars.
 */
@property (nonatomic, retain) NSDate*           expirationDate;

/**
 The user id, which is calculated on the client side for each app (re-) installation.
 */
@property (nonatomic, retain) NSString*         userId;

/**
 All transactionIds of the intial purchase, subsequential renewals and restored transactions.
 */
@property (nonatomic, retain) NSArray*          transactionIds;

/**
 YES, if there is a free trial available for the user.
 */
@property (nonatomic, assign) BOOL              freeTrialEnabled;

/**
 The number of days before a user gets charged after enabling the subscription.
 */
@property (nonatomic, assign) NSUInteger        freeTrialDurationInDays;

/**
 The button/action text to encourage users to buy a subscription.
 */
@property (nonatomic, retain) NSString*         localizedUpgradeButtonText;

/**
 The localized price info to display for the user, prior to the subscription purchase.
 */
@property (nonatomic, retain) NSString*         localizedPriceInfo;

/**
 The current status of the app subscription. This is used for access handling of the CalendarStore items.
 */
@property (nonatomic, assign, readonly) enum CSSubscriptionStatus subscriptionStatus;


-(id)initWithProductId:(NSString*) productIdentifier;
    
- (NSUInteger) remainingDays;
- (NSUInteger) remainingMinutes;
- (BOOL) isActive;


@end