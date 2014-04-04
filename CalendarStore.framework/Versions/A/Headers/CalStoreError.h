//
//  CalStoreError.h
//  CalendarStore
//
//  Created by SchedJoules on 29-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStoreDefines.h"

/*!
	@abstract NSError subclass for errors originating in the CalStore framework.
 
	@discussion CalStoreError are in the CalStoreErrorDomain domain.
 */
@interface CalStoreError : NSError

+(instancetype)errorWithCode:(NSInteger)code userInfo:(NSDictionary *)dict;

// non localized message for internal error message. If nil, no message is available.
@property (nonatomic, readonly) NSString* nonLocalizedMessage;

@end
