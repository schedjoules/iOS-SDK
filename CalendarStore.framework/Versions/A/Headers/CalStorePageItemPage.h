//
//  CalStorePageItemPage.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageItemPurchasable.h"
#import "CalStorePageRequest.h"


/*!
	@abstract	An item that links to another Page. The url property contains
				the full URL to the Page being linked to.
 
				Use the -[pageRequest] to get a request for the linked-to Page.
 */
@interface CalStorePageItemPage : CalStorePageItemPurchasable

@property (nonatomic, readonly) NSURL* url; // url

@end



@interface CalStorePageItemPage (CalStoreHelper)

-(CalStorePageRequest*)pageRequest; // returns a pageRequest that can be used to load the CalStorePage that this item points to.

@end