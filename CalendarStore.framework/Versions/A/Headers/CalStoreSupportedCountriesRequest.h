//
//  CalStoreSupportedCountriesRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 16-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^CalStoreSupportedCountriesRequestCompletionHandler)(NSArray* countries, NSError* error);

/*!
 @abstract  Use to fetch a list of available countries from the API.
 */
@interface CalStoreSupportedCountriesRequest : NSObject

// creates a new request
+(instancetype)request;

// fetching
@property (nonatomic, strong) NSString* authorizationToken; // defaults to [CalStoreController sharedController].authorizationToken
@property (nonatomic, getter = isFetching, readonly) BOOL fetching; // YES if data is still being fetched


-(void)fetchWithCompletionHandler:(CalStoreSupportedCountriesRequestCompletionHandler)completionHandler; // callback will be on main queue
-(void)cancel; // cancels this requests

@end
