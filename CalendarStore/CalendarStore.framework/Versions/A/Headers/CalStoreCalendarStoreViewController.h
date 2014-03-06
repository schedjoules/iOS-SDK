//
//  CalStoreCalendarStoreViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CalStorePage;
@class CalStorePageRequest;

@protocol CalStoreCalendarStoreViewControllerDelegate;

@interface CalStoreCalendarStoreViewController : UINavigationController

@property (nonatomic, assign) BOOL showsCloseButton; // defaults to YES, will only show when not being a root view controller.
@property (nonatomic, unsafe_unretained) id<CalStoreCalendarStoreViewControllerDelegate> calendarStoreDelegate;


// initializors
+(instancetype)calendarStoreViewController; // shows the start page
+(instancetype)calendarStoreViewControllerWithPage:(CalStorePage*)page;
+(instancetype)calendarStoreViewControllerWithPageRequest:(CalStorePageRequest*)pageRequest;

@end


@protocol CalStoreCalendarStoreViewControllerDelegate <NSObject>

@optional

// called when the 'close' button is tapped. The delegate is responsible for dismissing the viewController
-(void)calendarStoreViewControllerDidClose:(CalStoreCalendarStoreViewController*)viewController;

// country changing
-(NSString*)calendarStoreViewController:(CalStoreCalendarStoreViewController*)viewController willChangeCountry:(NSString*)location; // return the new location (or nil to use the given location)
-(void)calendarStoreViewController:(CalStoreCalendarStoreViewController*)viewController didChangeCountry:(NSString*)location;

@end
