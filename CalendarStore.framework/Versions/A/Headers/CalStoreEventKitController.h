//
//  CalStoreEventKitController.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
@import EventKit;

/*!
	@abstract	Singleton object that links the CalendarStore to the EventKit framework.
 
	@discussion	The CalendarStore uses EventKit to show if calendars are installed by the user
				and to send notifications about when an EKCalendar has been added due to 
				an installation by the user.
 
				However, using EventKit is optional. To opt-out of using EventKit, call:
					[CalStoreEventKitController sharedController].useEventKit = NO;
 */
@interface CalStoreEventKitController : NSObject

+(instancetype)sharedController;
@property (nonatomic, strong) EKEventStore* eventStore;
@property (nonatomic, assign) BOOL useEventKit; // if NO, EventKit functionality will not be used

@end
