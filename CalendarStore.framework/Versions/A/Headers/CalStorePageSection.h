//
//  CalStorePageSection.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"

/*!
 @abstract	A Calendar Store Page exists of multiple sections. A section
			is a grouped part of the page, with a sub-title.
 
			A PageSection is also localized.
 
			A section holds CalStorePageItem objects, which hold the actual
			content of the PageSection.
 */
@interface CalStorePageSection : CalStoreObject

@property (nonatomic, readonly) NSString* name; // localized
@property (nonatomic, readonly) NSArray* items; // an array of CalStorePageItem objects

@end
