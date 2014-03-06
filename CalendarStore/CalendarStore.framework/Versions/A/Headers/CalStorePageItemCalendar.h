//
//  CalStorePageItemCalendar.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageItem.h"
#import "CalStorePriceInfo.h"

typedef void(^CalStoreFetchUrlCompletionHandler)(NSURL* url, NSError* error);

/*!
	@abstract	A PageItemCalendar is the item that actually can be installed
				by the user.
 */
@interface CalStorePageItemCalendar : CalStorePageItem

@property (nonatomic, readonly) NSString* identifier; // In-app purchase identifier

@property (nonatomic, readonly) NSSet* relatedIdentifiers; // In-app purchase identifiers for other apps of the same vendor
															 // nil if the vendor does not have any other apps.

// Call this to get the URL for this calendar, asynchronously. Be sure to handle errors.
// Should only be called when isPurchased is YES.
-(void)createUrlWithCompletionHandler:(CalStoreFetchUrlCompletionHandler)completionHandler;

@end


typedef void(^CalStoreOrderCompletionHandler)(BOOL succeeded, NSError* error);
extern NSString* const kCalStoreOrderStatusChangedNotification;
extern NSString* const kCalStoreOrderStatusChangedIdentifierKey;
extern NSString* const kCalStoreRestoringPurchasesStatusChangedNotification;

/*!
	@abstract Convenience methods that tie into the CalStoreController.
 */
@interface CalStorePageItemCalendar (CalStore_StoreKitIntegration)

@property (nonatomic, readonly, getter = isInstalled) BOOL installed;
@property (nonatomic, readonly, getter =  isPurchased) BOOL purchased;
@property (nonatomic, readonly, getter = isBeingPurchased) BOOL beingPurchased;

// purchase this item.
-(void)purchaseWithCompletionHandler:(CalStoreOrderCompletionHandler)completionHandler;

@end



typedef void(^CalStorePriceInfoCompletionHandler)(CalStorePriceInfo* priceInfo, NSError* error);

@interface CalStorePageItemCalendar (CalStore_PriceInfo)

@property (nonatomic, readonly) CalStorePriceInfo* priceInfo;
@property (nonatomic, readonly, getter = isFetchingPriceInfo) BOOL fetchingPriceInfo;
-(void)fetchPriceInfoWithCompletionHandler:(CalStorePriceInfoCompletionHandler)completionHandler;
-(void)cancelFetchingPriceInfo;

@end
