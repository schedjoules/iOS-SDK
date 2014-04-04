//
//  CalStorePage.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"




/*!
	@abstract	Pages are the foundation of the API. Pages are the scaffolds of the views
				your users will interact with. You need to add the UX and UI for the pages.
				
				Pages are localised so all items on the page that can be translated will be 
				shown translated.
 
				You can request pages from the API using the CalStorePageRequest object.
 */
@interface CalStorePage : CalStoreObject

@property (nonatomic, readonly) NSString* itemId;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSString* appSubscriptionIdentifier; // optional

@property (nonatomic, readonly) CalStorePageType pageType; // the type of results this page holds
@property (nonatomic, readonly) CalStoreContentMode contentMode; // content mode of this page, e.g. testing or production

@property (nonatomic, readonly) NSArray* sections; // array of CalStorePageSection objects

@end
