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
@protocol CalStorePageItemHandlerDelegate;

@protocol CalStoreCalendarStoreViewControllerDelegate;

@interface CalStoreCalendarStoreViewController : UINavigationController

@property (nonatomic, assign) BOOL showsCloseButton; // defaults to YES, will only show when not being a root view controller.
@property (nonatomic, assign) BOOL showsActionButtons; // defaults to YES, will show controls for Restoring Purchases, Changing Countries and more.

@property (nonatomic, weak) id<CalStoreCalendarStoreViewControllerDelegate> calendarStoreDelegate;
@property (nonatomic, weak) id<CalStorePageItemHandlerDelegate> pageItemHandlerDelegate;


// initializors
+(instancetype)calendarStoreViewController; // shows the start page
+(instancetype)calendarStoreViewControllerWithPage:(CalStorePage*)page;
+(instancetype)calendarStoreViewControllerWithPageRequest:(CalStorePageRequest*)pageRequest;

@end


@class CalStorePageItem;
@protocol CalStoreCalendarStoreViewControllerDelegate <NSObject>

@optional

// called when the 'close' button is tapped. The delegate is responsible for dismissing the viewController
-(void)calendarStoreViewControllerDidClose:(CalStoreCalendarStoreViewController*)calendarStoreViewController;

// country changing
-(NSString*)calendarStoreViewController:(CalStoreCalendarStoreViewController*)calendarStoreViewController willChangeCountry:(NSString*)location; // return the new location (or nil to use the given location)
-(void)calendarStoreViewController:(CalStoreCalendarStoreViewController*)calendarStoreViewController didChangeCountry:(NSString*)location;

// language changing
-(NSString*)calendarStoreViewController:(CalStoreCalendarStoreViewController*)calendarStoreViewController willChangeLanguage:(NSString*)language; // return the new language (or nil to use the given language)
-(void)calendarStoreViewController:(CalStoreCalendarStoreViewController*)calendarStoreViewController didChangeLanguage:(NSString*)language;

// Called when a CalStorePageItem is selected by the user and a ViewController will be 'shown' (either presented or pushed). Return YES to invoke default behavior or NO if you
// want to take over showing the viewController or item.
-(BOOL)calendarStoreViewController:(CalStoreCalendarStoreViewController*)calendarStoreViewController shouldPresentViewController:(UIViewController*)viewController afterSelectingItem:(CalStorePageItem*)pageItem;

@end
