//
//  CalStorePageItemPurchasable.h
//  CalendarStore
//
//  Created by SchedJoules on 10-03-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageItem.h"
#import "CalStorePriceInfo.h"

/*!
 Abstract Base Class for items that _can be_ purchasable.
 
 Has methods to request pricing info, in-app productIdentifiers,
 purchasing status flags.
 
 Use the canBePurchased property to see if an item can actually
 be purchased using the in-app purchasing system.
 */
@interface CalStorePageItemPurchasable : CalStorePageItem

@property (nonatomic, readonly) NSString* productIdentifier; // In-app purchase identifier

@property (nonatomic, readonly) NSSet* relatedProductIdentifiers; // In-app purchase identifiers for other apps of the same vendor
																  // nil if the vendor does not have any other apps.

@end



// notifications send out if purchasing information changes
typedef void(^CalStoreOrderCompletionHandler)(BOOL succeeded, NSError* error);
extern NSString* const kCalStoreOrderStatusChangedNotification;
extern NSString* const kCalStoreOrderStatusChangedIdentifierKey;
extern NSString* const kCalStoreRestoringPurchasesStatusChangedNotification;


/*!
 @abstract Convenience methods that tie into the CalStoreController.
 */
@interface CalStorePageItemPurchasable (CalStore_StoreKitIntegration)

@property (nonatomic, readonly, getter =  isPurchased) BOOL purchased; // YES if the item is already purchases
@property (nonatomic, readonly, getter = isBeingPurchased) BOOL beingPurchased; // YES iff the item is in the process of being purchased
@property (nonatomic, readonly, getter = canBePurchased) BOOL canBePurchased; // not all purchasable items can actually be purchased, due to them not having a valid productIdentifier

// purchase this item.
-(void)purchaseWithCompletionHandler:(CalStoreOrderCompletionHandler)completionHandler;

@end



typedef void(^CalStorePriceInfoCompletionHandler)(CalStorePriceInfo* priceInfo, NSError* error);

/*!
 @abstract PriceInfo Methods
 */
@interface CalStorePageItemPurchasable (CalStore_PriceInfo)

@property (nonatomic, readonly) CalStorePriceInfo* priceInfo;
@property (nonatomic, readonly, getter = isFetchingPriceInfo) BOOL fetchingPriceInfo;
-(void)fetchPriceInfoWithCompletionHandler:(CalStorePriceInfoCompletionHandler)completionHandler;
-(void)cancelFetchingPriceInfo;

@end
