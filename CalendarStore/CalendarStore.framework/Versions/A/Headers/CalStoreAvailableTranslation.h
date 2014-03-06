//
//  CalStoreAvailableTranslation.h
//  CalendarStore
//
//  Created by SchedJoules on 16-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"

/*!
 @abstract	Information about a translation. Currently only holds locale information.
 */
@interface CalStoreAvailableTranslation : CalStoreObject

@property (nonatomic, readonly) NSString* locale;

@end
