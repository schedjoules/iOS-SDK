//
//  CalendarStore.h
//  CalendarStore
//
//  Created by SchedJoules on 29-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Definitions
#import <CalendarStore/CalStoreDefines.h>

// controllers
#import <CalendarStore/CalStoreController.h>
#import <CalendarStore/CalStoreStoreKitController.h>
#import <CalendarStore/CalStoreEventKitController.h>

// view controllers
#import <CalendarStore/CalStoreInstallCalendarViewController.h>
#import <CalendarStore/CalStoreCalendarStoreViewController.h>
#import <CalendarStore/CalStoreWeatherCalendarViewController.h>
#import <CalendarStore/CalStoreBaseApiContentViewController.h>
#import <CalendarStore/CalStorePickCountryViewController.h>

// data model objects
#import <CalendarStore/CalStoreObject.h>
#import <CalendarStore/CalStoreIcon.h>
#import <CalendarStore/CalStorePage.h>
#import <CalendarStore/CalStorePageItem.h>
#import <CalendarStore/CalStorePageItemCalendar.h>
#import <CalendarStore/CalStorePageItemPage.h>
#import <CalendarStore/CalStorePageItemParameterizedCalendar.h>
#import <CalendarStore/CalStorePageSection.h>
#import <CalendarStore/CalStorePriceInfo.h>
#import <CalendarStore/CalStoreCalendarParameterOption.h>
#import <CalendarStore/CalStoreCalendarParameterOptions.h>

#import <CalendarStore/CalStoreWeatherCity.h>
#import <CalendarStore/CalStoreCountry.h>
#import <CalendarStore/CalStoreAvailableTranslation.h>

// requestors
#import <CalendarStore/CalStorePageRequest.h>
#import <CalendarStore/CalStoreWeatherCitiesWithinRegionRequest.h>
#import <CalendarStore/CalStoreSupportedCountriesRequest.h>

@import StoreKit;				// for In-App Purchases
@import EventKit;				// for EventKit tie-in
@import MapKit;					// for Weather Calendars search
@import CoreLocation;			// for Weather Calendars search.
@import MessageUI;				// for the 'Give feedback' functionality
@import SystemConfiguration;	// for Reachability networking code
@import QuartzCore;				// for custom control rendering
@import Accelerate;				// for image effect rendering