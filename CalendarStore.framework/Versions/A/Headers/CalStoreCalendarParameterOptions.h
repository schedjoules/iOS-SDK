//
//  CalStoreCalendarParameterOptions.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"
#import "CalStoreCalendarParameterOption.h"

/*!
	@abstract	Represents a list of options for one parameter, from which the user can pick one value.
	@discussion	The parameter has a localized title and a list of possible values (with localized title as well)
				from which the user should pick one in an appropriate UI.
 */
@interface CalStoreCalendarParameterOptions : CalStoreObject

@property (nonatomic, readonly) NSString* title; // localized title that can be presented to the user
@property (nonatomic, readonly) NSArray* options; // array of CalStoreCalendarParameterOption objects that represents the values that can be picked for the parameter
@property (nonatomic, readonly) CalStoreCalendarParameterOption* defaultOption; // the option that is default for the user's current locale

-(NSString*)titleForOptionWithValue:(NSString*)value; // covnenience
-(NSArray*)allValues; // all the values for this parameter

@end
