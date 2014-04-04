//
//  CalStorePickCountryViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 17-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreBaseApiContentViewController.h"
#import "CalStoreCountry.h"

typedef void(^CalStorePickCountryViewControllerCallback)(NSString* newSelectedCountryLocale);

/*!
 @abstract ViewController that allows the user to pick a country from the list of countries supported by the store.
 
 @discussion This is the Abstract Base Class of a Class Cluster. Creating an instance of this class
			 will return a concrete implementation. On iOS6 and beyond, a collectionview based viewcontroller
			 is used, while on iOS5 a tableview based implementation is used.
 */
@interface CalStorePickCountryViewController : CalStoreBaseApiContentViewController

@property (nonatomic, assign) BOOL showsCancelButton; // if YES, shows a cancel button which will dismiss or pop the viewcontroller. Defaults to YES.

@property (nonatomic, copy) NSString* selectedCountryIso3166Code; // set to the country that initially should be selected
@property (nonatomic, copy) CalStorePickCountryViewControllerCallback selectionDidChangeCallback; // will be called when an item is selected.

@end
