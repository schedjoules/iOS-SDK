//
//  CalStoreCalendarParameterOption.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"

/*!
	@abstract	Represents a value that can be set for a specific parameter
				in the CalStoreParameterizedCalendar.
 
	@discussin	The title is a localized string that can be presented to the user.
				The value needs to be set as an option for the specific parameter.
 */
@interface CalStoreCalendarParameterOption : CalStoreObject

@property (nonatomic, strong) NSString* value;	// value for this option
@property (nonatomic, strong) NSString* title;	// localized title that can be presented to the user

@end
