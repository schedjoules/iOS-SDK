//
//  CalStoreInstallCalendarViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CalStorePageItemCalendar.h"
#import "CalStorePageItemHandlerDelegate.h"

/*!
	@abstract	A ViewController to install a purchased calendar.
 
	@discussion	This ViewController will allow the user to install an 
				already purchased CalStorePageItemCalendar object onto
				his iPhone.
 
				The CalStorePageItemCalendar object must have it's
				isPurchased property returning YES.
 
				CalStorePageItemParameterizedCalendar objects must
				have all their parameterValues set.
 
 
	@note		Use the designated constructor +[viewControllerWithCalendarItem:]
 
 */
@interface CalStoreInstallCalendarViewController : UINavigationController

@property (nonatomic, strong) CalStorePageItemCalendar* calendarItem; // calendarItem.isPurchased must be YES. Raises an Exception otherwise
@property (nonatomic, weak) id<CalStorePageItemHandlerDelegate> pageItemHandlerDelegate;

// calendarItem.isPurchased must be YES. Returns nil otherwise.
+(instancetype)viewControllerWithCalendarItem:(CalStorePageItemCalendar*)calendarItem;

@end
