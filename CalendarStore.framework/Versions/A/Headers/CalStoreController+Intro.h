//
//  CalStoreController+CalStoreController_Intro.h
//  CalendarStore
//
//  Created by SchedJoules on 23.02.15.
//  Copyright (c) 2015 SchedJoules. All rights reserved.
//

#import <CalendarStore/CalendarStore.h>

/*!
	@abstract	A CalendarStore category to hook in an walkthrough/intro for the user.
 
	@discussion	The CalStoreController_IntroIntro category extends the CalStoreController with a walkthrough which is presented as  modal viewController. Use presentModalIntroFromViewController to display the default content. Custom content can be provided with plist resource path in presentModalIntroFromViewController. Refer to the documentation.
 */
@interface CalStoreController (Intro)

/**
 * Launches the intro the first time the app starts.
 */
- (void) presentModalIntroFromViewController: (UIViewController *) viewController animated:(BOOL)animated;

/**
 * Launches the intro the first time the app starts.
 */
- (void) presentModalIntroFromViewController: (UIViewController *) viewController withPlistPath: (NSString *) plistPath animated:(BOOL)animated;

/**
 * Launches the intro the first time the app starts.
 */
- (void) presentModalIntroFromViewController: (UIViewController *) viewController animated:(BOOL)animated delayed:(double) delayInSeconds;

/**
 * Launches the intro the first time the app starts.
 */
- (void) presentModalIntroFromViewController: (UIViewController *) viewController withPlistPath: (NSString *) plistPath animated:(BOOL)animated delayed:(double) delayInSeconds;

/**
 * Call when the user finished the intro.
 */
+ (void) introDidFinish;

/**
 * Check if the user completed the intro.
 */
+ (BOOL) didUserCompleteIntro;

@end

