//
//  CalStorePageItem.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"
#import "CalStoreIcon.h"
#import "CalStoreDefines.h"

/*!
 @abstract	A PageItem is building block of each PageSection. It's either a link to 
			another Page or a Calendar.
 
			Each item has an itemId, a (localized) name and optionally an icon.
 
			The base class for each CalStorePageItem subclass, items are actually
			one of the concrete subclasses of this class.
 */
@interface CalStorePageItem : CalStoreObject

@property (nonatomic, readonly) NSString* itemId;
@property (nonatomic, readonly) NSString* name;	// localized

@property (nonatomic, readonly) CalStoreIcon* icon; // optional
@property (nonatomic, readonly) CalStoreCategory category;

// optional informative properties
@property (nonatomic, readonly) NSString* sport; // localized
@property (nonatomic, readonly) NSString* country; // localized
@property (nonatomic, readonly) NSString* season; // localized


-(BOOL)isEqualToPageItem:(CalStorePageItem*)other; // compares itemIds only

@end



// Convenience accessor to check the type of calendar
@interface CalStorePageItem (CalStore_Typing)

@property (nonatomic, readonly, getter = isWeatherCalendar) BOOL isWeatherCalendar;
@property (nonatomic, readonly, getter = isCalendar) BOOL isCalendar; // YES iff this item is a 'Calendar'
@property (nonatomic, readonly, getter = isPage) BOOL isPage; // YES iff this item is a 'Page'

@end
