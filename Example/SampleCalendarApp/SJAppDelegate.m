//
//  SJAppDelegate.m
//  SampleCalendarApp
//
//  Created by SchedJoules on 11-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "SJAppDelegate.h"
#import <CalendarStore/CalendarStore.h>

@implementation SJAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	self.window.tintColor = [UIColor redColor];
	
	// CalendarStore: set the debug level to log as much as possible. This is an optional step, we only
	// recommend doing in debug builds.
#if _DEBUG
	[CalStoreController sharedController].debugLevel = CalStoreDebugLevelAll;
#endif// _DEBUG
	
	
#warning FILL IN YOUR OWN AUTHORIZATION TOKEN HERE
	// CalendarStore: we let the framework use our own AuthorizationToken here.
	// [CalStoreController sharedController].authorizationToken = <# Your AuthorizationToken Here #>;
	
	
#warning ADD YOUR OWN SUPPORT E-MAILADDRESS HERE, OPTIONALLY
	// CalendarStore: we let the framework use our own support e-mailaddress here.
	// [CalStoreController sharedController].feedbackEmailAddress = <# Your Support EmailAddress Here #>;
	
    return YES;
}
							
@end
