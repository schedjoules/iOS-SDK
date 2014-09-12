//
//  CalStoreCalendarBundle.h
//  CalendarStore
//
//  Created by SchedJoules on 28-06-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"

@class CalStoreIcon;
@class CalStoreSearchRequest;

/**
 @abstract A bundle of calendars, related to an in-app purchase.
 
 This model object is used in purchasing dialogs.
 */
@interface CalStoreCalendarBundle : CalStoreObject

@property (nonatomic, readonly) NSString* itemId;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) CalStoreIcon* icon;

// in-app purchase information
@property (nonatomic, readonly) NSString* productIdentifier;
@property (nonatomic, readonly) NSArray* relatedProductIdentifiers;

// the number of calendars in this bundle, if available, otherwise 0.
@property (nonatomic, readonly) NSUInteger numberOfCalendars;

-(BOOL)isEqualToCalendarBundle:(CalStoreCalendarBundle*)other;

@end


@interface CalStoreCalendarBundle (CalStoreCalendarsInBundleHelper)

-(CalStoreSearchRequest*)calendarsInBundleSearchRequest; // returns a searchRequest that can be used to load the CalStorePage that has a flat list of all the calendar items for this bundle.

@end