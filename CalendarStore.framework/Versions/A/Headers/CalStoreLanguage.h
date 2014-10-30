//
//  CalStoreLanguage.h
//  CalendarStore
//
//  Created by SchedJoules on 22-10-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"

/*!
	@abstract Information about a language supported by the Calendar Store.
 */
@interface CalStoreLanguage : CalStoreObject

@property (nonatomic, readonly) NSString* languageId;
@property (nonatomic, readonly) NSString* iso6391Code;

@property (nonatomic, readonly) NSString* localizedName;

@end
