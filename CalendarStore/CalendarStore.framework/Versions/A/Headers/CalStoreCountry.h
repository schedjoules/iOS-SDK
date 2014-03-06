//
//  CalStoreCountry.h
//  CalendarStore
//
//  Created by SchedJoules on 16-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"
#import "CalStoreIcon.h"

typedef void(^CalStoreCountryAvailableTranslationsCompletionHandler)(NSArray* availableTranslations, NSError* error); // CalStoreAvailableTranslation objects

/*!
	@abstract Information about a country supported by the Calendar Store.
 */
@interface CalStoreCountry : CalStoreObject

@property (nonatomic, readonly) NSString* countryId;
@property (nonatomic, readonly) NSString* iso3166Code;

@property (nonatomic, readonly) NSString* name; // not localized
@property (nonatomic, readonly) NSString* localizedName; // localized name

@property (nonatomic, readonly) CalStoreIcon* icon; // icon for this country

@property (nonatomic, readonly) NSArray* availableTranslations; // CalStoreAvailableTranslation objects, if nil, use fetchAvailableTranslationsWithCompletionHandler:

@end


/*!
 If availableTranslations is nil, use fetchAvailableTranslationsWithCompletionHandler: to fetch the availableTranslations async.
 */
@interface CalStoreCountry (CalStore_FetchAvailableTranslations)


@property (nonatomic, readonly, getter = isFetchingAvailableTranslations) BOOL fetchingAvailableTranslations; // YES iff fetchAvailableTranslationsWithCompletionHandler: is running

// use when the availableTranslations property is nil.
-(void)fetchAvailableTranslationsWithCompletionHandler:(CalStoreCountryAvailableTranslationsCompletionHandler)completionHandler;

// Only use if you don't use the [CalStoreController sharedController].authorizationToken as a token.
-(void)fetchAvailableTranslationsWithCompletionHandler:(CalStoreCountryAvailableTranslationsCompletionHandler)completionHandler authorizationToken:(NSString*)authorizationToken;
-(void)cancelAvailableTranslationsFetch; // cancels an ongoing fetch request for availableTranslations

@end
