//
//  CalStorePageItemCalendar.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageItemPurchasable.h"

typedef void(^CalStoreFetchUrlCompletionHandler)(NSURL* url, NSError* error);

/*!
	@abstract	A PageItemCalendar is the item that actually can be installed
				by the user.
 */
@interface CalStorePageItemCalendar : CalStorePageItemPurchasable

// Call this to get the URL for this calendar, asynchronously. Be sure to handle errors.
// Should only be called when isPurchased is YES.
-(void)createUrlWithCompletionHandler:(CalStoreFetchUrlCompletionHandler)completionHandler;

// Call this to get the preview URL for this calendar, asynchronously. Be sure to handle errors.
// The preview URL can be used to show a preview of the events in this calendar, it does not
// necessarily has all the events of the real calendar.
-(void)createPreviewUrlWithCompletionHandler:(CalStoreFetchUrlCompletionHandler)completionHandler;

@end


/*!
 @abstract Convenience methods that tie into the CalStoreController.
 */
@interface CalStorePageItemCalendar (CalStore_StoreKitIntegration)

@property (nonatomic, readonly, getter = isInstalled) BOOL installed;

@end
