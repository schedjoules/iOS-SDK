//
//  CalStoreWeatherCalendarViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CalStorePageItemParameterizedCalendar.h"

/*!
	@abstract	ViewController that allows one to install a weather calendar.
 
	@discussion	A weather calendar is of type CalStorePageItemParameterizedCalendar and
				has it's isWeatherCalendar property returning YES. This ViewController
				guides the user to selecting appropriate options, such as a city,
				purchasing the in-app purchase and installing a calendar.
 */
@interface CalStoreWeatherCalendarViewController : UIViewController

@property (nonatomic, strong) CalStorePageItemParameterizedCalendar* parameterizedCalendar;

@end
