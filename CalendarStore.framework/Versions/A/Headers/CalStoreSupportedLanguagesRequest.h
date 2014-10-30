//
//  CalStoreSupportedLanguagesRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 22-10-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^CalStoreSupportedLanguagesRequestCompletionHandler)(NSArray* languages, NSError* error);

/*!
 @abstract  Use to fetch a list of available languages from the API.
 */
@interface CalStoreSupportedLanguagesRequest : NSObject

// creates a new request
+(instancetype)request; // default locale
+(instancetype)requestForLocale:(NSString*)locale;

// fetching
@property (nonatomic, strong) NSString* authorizationToken; // defaults to [CalStoreController sharedController].authorizationToken
@property (nonatomic, getter = isFetching, readonly) BOOL fetching; // YES if data is still being fetched


-(void)fetchWithCompletionHandler:(CalStoreSupportedLanguagesRequestCompletionHandler)completionHandler; // callback will be on main queue
-(void)cancel; // cancels this requests

@end
