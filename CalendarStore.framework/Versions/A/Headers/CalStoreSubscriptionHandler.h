//
//  CalStoreSubscriptionHandler.h
//  CalendarStore
//
//  Created by Tobias Reinsch on 24.06.15.
//  Copyright (c) 2015 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "CalStoreSubscription.h"
#import "CalStoreSubscriptionTransaction.h"

/**
 @abstract Manages the purchase, persistance and restoring of the subscription
 We take special care about registering the purchases on the server, as this is crucial for the user to get access to the service.
 */
@interface CalStoreSubscriptionHandler : NSObject

typedef void(^CalStoreSubscriptionCompletion)(BOOL success, NSError* error);
/**
 Returns the shared instance of the CalStoreSubscriptionHandler.
 */
+ (id)sharedHandler;

/**
 Returns the shared instance of the CalStoreSubscription that is used to control the access to the CalendarStore items.
 */
+ (id)sharedSubscription;

/**
 Stores the subscription on the device and iCloud.
 @param localOnly YES, if it should only store on the device and not iCloud.
 */
- (void) persistSubscription:(BOOL) localOnly;

/**
 Registes a subscription transaction on the backend, to unlock the calendar feed access for the user.
 */
- (void) registerPaymentTransactions:(NSArray<SKPaymentTransaction*>*) transactions Completion:(CalStoreSubscriptionCompletion)completion;

/**
 Queries the subscription configuration from the backend.
 */
- (void) querySubscriptionConfiguration:(CalStoreSubscriptionCompletion)completion;

/**
 Updates the productId of the subscription, after loading the subscription configuration.
 */
- (void) updateSubscriptionProductId:(NSString*) productIdentifier;

/**
 Queries the current subscription status from the backend.
 */
- (void) updateSubscriptionStatusWithCompletion:(CalStoreSubscriptionCompletion)completion;


// upload info
@property (nonatomic, assign) NSInteger numberOfUploadTries;
@property (nonatomic, copy) NSDate* lastFailedUploadDate;
@property (nonatomic, readonly) NSDate* nextUploadDate;
@property (nonatomic, assign) BOOL isUploading;
@property (nonatomic, retain) CalStoreSubscription* subscription;


@end
