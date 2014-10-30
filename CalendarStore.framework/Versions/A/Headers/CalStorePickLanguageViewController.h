//
//  CalStorePickLanguageViewController.h
//  CalendarStore
//
//  Created by SchedJoules on 23-10-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreBaseApiContentViewController.h"

typedef void(^CalStorePickLanguageViewControllerCallback)(NSString* newSelectedLanguageLocale);

/*!
 @abstract ViewController that allows the user to pick a language from the list of languages supported by the store.
 */
@interface CalStorePickLanguageViewController : CalStoreBaseApiContentViewController

@property (nonatomic, assign) BOOL showsCancelButton; // if YES, shows a cancel button which will dismiss or pop the viewcontroller. Defaults to YES.

@property (nonatomic, copy) NSString* selectedLanguageIso6391Code; // set to the language that initially should be selected
@property (nonatomic, copy) CalStorePickLanguageViewControllerCallback selectionDidChangeCallback; // will be called when an item is selected.

@end
