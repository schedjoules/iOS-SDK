//
//  CalStorePageItemHandlerDelegate.h
//  CalendarStore
//
//  Created by SchedJoules on 02-05-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CalStorePageItem;
@class CalStorePageItemPage;
@class CalStorePageItemCalendar;
@class CalStorePageItemParameterizedCalendar;
@class CalStorePageItemPurchasable;
@class CalStoreWeatherCity;

typedef void(^CalStorePageItemHandlerDelegateCallback)(UIViewController* viewController);

/*!
 Delegate protocol for overriding behaviour in the standard UI classes.
 
 The standard UI view controllers (CalStoreCalendarStoreViewController, CalStoreWeatherViewController, CalStoreStyledPageViewController, etc)
 perform default actions when a user interacted with a CalStorePageItem via their UI. For example, when a user taps on an already
 purchased item, a CalStoreInstallCalendarViewController will be created and presented to install the calendar via EventKit.
 
 However, the default behaviour might not always be appropriate for apps. Some apps might want to install a calendar into 
 their own system. 
 CalStorePageItemHandlerDelegate makes it possible to override the default behaviour of these standard
 UI view controllers. This way, apps can take advantage of the UI that's already present, but still perform custom actions.
 
 Before invoking default behaviour after a user interacted with an item,
 pageItemHandlerDelegates get an opportunity to override that behavior on different levels:
	-shouldHandleItem:withCallback: allows to override any interaction
    - shouldShowViewController:forItem:withCallback: allows to override showing view controllers, after the default behaviour has been performed
    - the other methods allow overriding specific behaviour
 
 
 *Dynamically overriding*
 
 It's possible to determine at runtime if you want to override behaviour: returning YES will make the view controller
 invoke default behaviour, returning NO will stop any actions by the view controller.
 
 
 *Showing UIViewControllers*
 
 Custom implementations often want to show a custom view controller also. To do this, call the showViewControllerCallback() block
 with your custom view controller: `showViewControllerCallback(yourViewController)`. The standard UI viewcontroller will make sure
 it gets presented or pushed, depending on the type. UINavigationController subclasses will be presented, while others
 might get pushed or presented.
 
 */
@protocol CalStorePageItemHandlerDelegate <NSObject>

@optional

// general, return NO to stop any further processing for this item
-(BOOL)shouldHandleItem:(CalStorePageItem*)pageItem
		   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// showing view controllers. Called after the default behaviour, resulting in a viewcontroller had been invoked.
-(BOOL)shouldShowViewController:(UIViewController*)viewController
						forItem:(CalStorePageItem*)pageItem
				   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// navigating to a (sub)-page
-(BOOL)shouldNavigateToPageForItem:(CalStorePageItemPage*)pageItem
					  withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// navigate to a calendar.
// Currently, UI classes don't support navigating to calendars.
-(BOOL)shouldNavigateToCalendarForItem:(CalStorePageItemCalendar*)pageItem
						  withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;


// navigate to a weather view controller
-(BOOL)shouldNavigateToWeatherForItem:(CalStorePageItemParameterizedCalendar*)pageItem
						 withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// navigate to a view controller for a specific city
-(BOOL)shouldNavigateToWeatherCity:(CalStoreWeatherCity*)city
						   forItem:(CalStorePageItemParameterizedCalendar*)pageItem
					  withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// navigate to a view controller for an in-app product
-(BOOL)shouldNavigateToProductPageForItem:(CalStorePageItemPurchasable*)pageItem
							 withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// navigate to the preview screen for a calendar.
-(BOOL)shouldNavigateToPreviewForItem:(CalStorePageItemCalendar*)pageItem
						 withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// purchase an item. Should also handle installing an item after the purchase succeeded, when overriding.
-(BOOL)shouldPurchaseItem:(CalStorePageItemPurchasable*)pageItem
			 withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// install an item.
-(BOOL)shouldInstallCalendarForItem:(CalStorePageItemCalendar*)pageItem
					   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// should installs or purchase an item, depending on the item state.
-(BOOL)shouldInstallOrPurchaseCalendarForItem:(CalStorePageItemCalendar*)pageItem
								 withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// handle when an item is being purchased. Default does nothing
-(BOOL)shouldHandleBeingPurchasedForItem:(CalStorePageItemPurchasable*)pageItem
							withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// handle when an item is already installed. Default does nothing
-(BOOL)shouldHandleInstalledCalendarForItem:(CalStorePageItemCalendar*)pageItem
							   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// handle when an item got successfully installed. Default does nothing.
-(BOOL)shouldHandleSucceededCalendarInstallationForItem:(CalStorePageItemCalendar*)pageItem
										   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

// 'Install' a page. Typically presents the page inside a UINavigationController.
// Currently, UI classes don't support installing or purchasing pages.
-(BOOL)shouldInstallPageForItem:(CalStorePageItemPage*)pageItem
				   withCallback:(CalStorePageItemHandlerDelegateCallback)showViewControllerCallback;

@end
