//
//  CalStoreStyledPageViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 03-03-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreBaseApiContentViewController.h"

@protocol CalStoreStyledPageViewControllerDelegate;

/**
 @abstract ViewController that shows a 'StyledPage'. A StyledPage uses custom UI (e.g. no tableview) to show the CalendarStore.
 
 @discussion In the future, this will allow client-apps to show customly styled UI for the CalendarStore. In version 1, this
			 ViewController can be presented to show a "landingspage" on iPad. This landingspage will show custom UI for popular
			 items and will present sub-pages modally as a formsheet.
 */
@interface CalStoreStyledPageViewController : CalStoreBaseApiContentViewController

@property (nonatomic, unsafe_unretained) id<CalStoreStyledPageViewControllerDelegate> delegate;


// Searching is provided by this searchBar. The user of this viewController is responsible for adding it to the UI, using addSubview: or any other means.
// If this view controller is presented in a UINavigationController, one way could be:
//		vc.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:vc.searchBar]
@property (nonatomic, strong) UISearchBar* searchBar; // Returns a default searchbar, if none set. When setting this property with a searchBar, its delegate will be overriden.

@end



@protocol CalStoreStyledPageViewControllerDelegate <NSObject>

@optional

// country changing
-(NSString*)styledPageViewController:(CalStoreStyledPageViewController*)viewController willChangeCountry:(NSString*)location; // return the new location (or nil to use the given location)
-(void)styledPageViewController:(CalStoreStyledPageViewController*)viewController didChangeCountry:(NSString*)location;

@end
