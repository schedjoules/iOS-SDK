//
//  CalStoreSearchRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 11-03-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageRequest.h"

/*!
 @abstract Requests a Page with search results, either for a free-text search
		   or for a specific in-app productIdentifier.
 
 Use one of the designated initializers only.
 */
@interface CalStoreSearchRequest : CalStorePageRequest

@property (nonatomic, readonly, copy) NSString* searchQuery; // only available when requestWithSearchQuery:(locale:) has been called
@property (nonatomic, readonly, copy) NSString* searchProductIdentifier; // only available when requestWithSearchByProductIdentifier:(locale:) has been called

// Designated Initializers
+(instancetype)requestWithSearchQuery:(NSString*)query; // free-text search, uses the [CalStoreController sharedController].locale as a locale (country)
+(instancetype)requestWithSearchQuery:(NSString*)query locale:(NSString*)locale;

+(instancetype)requestWithSearchByProductIdentifier:(NSString*)productIdentifier; // In-App productIdentifier search, uses the [CalStoreController sharedController].locale as a locale (country)
+(instancetype)requestWithSearchByProductIdentifier:(NSString*)productIdentifier locale:(NSString*)locale;



+(instancetype)requestWithSearchForCalendarsByProductIdentifier:(NSString*)productIdentifier; // In-App productIdentifier search, uses the [CalStoreController sharedController].locale as a locale (country)
+(instancetype)requestWithSearchForCalendarsByProductIdentifier:(NSString*)productIdentifier locale:(NSString*)locale;

@end
