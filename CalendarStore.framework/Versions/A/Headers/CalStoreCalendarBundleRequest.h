//
//  CalStoreCalendarBundleRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 28-06-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CalStoreCalendarBundle;
typedef void(^CalStoreCalendarBundleRequestCompletionHandler)(CalStoreCalendarBundle* page, NSError* error);

/**
 @abstract Requests a CalendarBundle from the API, using a block based API.
 */
@interface CalStoreCalendarBundleRequest : NSObject  <NSCopying, NSMutableCopying>

@property (nonatomic, readonly) NSString* productIdentifier; // the productIdentifier for the bundle being fetched.


@property (nonatomic, strong) NSString* authorizationToken; // defaults to [CalStoreController sharedController].authorizationToken
@property (nonatomic, getter = isFetching, readonly) BOOL fetching; // YES if data is still being fetched


-(void)cancel; // cancels this requests
-(void)fetchCalendarBundleWithCompletionHandler:(CalStoreCalendarBundleRequestCompletionHandler)completionHandler; // requests to fetch the a calendarbundle with
																												   // a completion handler


// designated initializers
+(instancetype)requestWithProductIdentifier:(NSString*)productIdentifier; // locale = [CalStoreController sharedController].locale
+(instancetype)requestWithProductIdentifier:(NSString*)productIdentifier locale:(NSString*)locale;

@end
