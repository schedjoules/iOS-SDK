//
//  CalStorePageRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStorePage.h"

typedef void(^CalStorePageRequestCompletionHandler)(CalStorePage* page, NSError* error);
extern NSString* const kCalStoreStartPageItemId; // the item id of the starting page

/*!
	@abstract	Requests a Page from the CalendarStore, using
				a block-based API.
				- Create a  request using one of the convenience constructors, either
				  by itemId, URL or using a CalStorePageItemPage object.
				- fetch the page using fetchPageWithCompletionHandler:
 
				If an authorization token is not manually supplied, it will be taken from
				[CalStoreController sharedController].authorizationToken or from the
				CalStoreAuthorizationToken key in your Info.plist.
 
	@example
				CalStorePageItemPage* item = ....;
				CalStorePageRequest* request = [CalStorePageRequest requestWithItem:item];
				[request fetchPageWithCompletionHandler:^(CalStorePage* page, NSError* error){
					if(error != nil)
					{
						doSomethingWithPage(page);
					}
					else
					{
						NSLog(@"Error fetching page: %@", error);
					}
				}];
 */
@interface CalStorePageRequest : NSObject <NSCopying, NSMutableCopying>

@property (nonatomic, readonly) NSString* itemId; // the itemId, if available, for the page being fetched.
@property (nonatomic, readonly) NSURL* url; // the URL for the page being fetched

@property (nonatomic, strong) NSString* authorizationToken; // defaults to [CalStoreController sharedController].authorizationToken
@property (nonatomic, getter = isFetching, readonly) BOOL fetching; // YES if data is still being fetched

-(void)cancel; // cancels this requests
-(void)fetchPageWithCompletionHandler:(CalStorePageRequestCompletionHandler)completionHandler; // requests to fetch the page with
																							   // a completion handler


// convenience constructors.

// create a request for a page by its item_id, locale and location are taken from [CalStoreController sharedController]
+(instancetype)requestWithItemId:(NSString*)itemId;

// create a request for a page by its item_id, locale can be defined manually
+(instancetype)requestWithItemId:(NSString*)itemId locale:(NSString*)locale;

// create a request for a page by its url, the itemId property will be left empty.
+(instancetype)requestWithUrl:(NSURL*)url;

// creates a request for the start page, convenience for -[requestWithItemId:kCalStoreStartPageItemId];
+(instancetype)requestWithStartPage;

// creates a request for the start page, locale and location can be defined manually. Convenience for -[requestWithItemId:kCalStoreStartPageItemId locale:location:]
+(instancetype)requestWithStartPageWithLocale:(NSString*)locale location:(NSString*)location;


// creates a request for a page which returns the number of top items
+(instancetype)requestWithNumberOfTopItems:(NSUInteger)numberOfTopItems;
+(instancetype)requestWithNumberOfTopItems:(NSUInteger)numberOfTopItems locale:(NSString*)locale location:(NSString*)location;

// creates a request for a page which returns the number of new items
+(instancetype)requestWithNumberOfNewItems:(NSUInteger)numberOfNewItems;
+(instancetype)requestWithNumberOfNewItems:(NSUInteger)numberOfNewItems locale:(NSString*)locale;

// creates a request for ap age which returns the number of next items
+(instancetype)requestWithNumberOfUpcomingItems:(NSUInteger)numberOfUpcomingItems;
+(instancetype)requestWithNumberOfUpcomingItems:(NSUInteger)numberOfUpcomingItems locale:(NSString*)locale;

@end


@class CalStorePageItemPage;
@interface CalStorePageRequest (CalStorePageItemPage)

// CalStorePageItemPage objects refer to other CalStorePages. This convenience constructor creates
// a request for that other CalStorePage being refered to.
+(instancetype)requestWithPageItem:(CalStorePageItemPage*)itemPage;

@end
