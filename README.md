# SchedJoules' CalendarStore Framework for iOS

## Introduction
This repository contains the CalendarStore framework for iOS. The CalendarStore framework gives you the possibilities to quickly integrate a working CalendarStore in your app with 3 lines of code or to build your own CalendarStore UI with SchedJoules's data.

See more at [http://www.schedjoules.com](http://www.schedjoules.com) . 

## Getting Started
 - Download CalendarStore.zip or checkout the repository
 - Read the Documentation at [http://schedjoules.github.io/iOS-SDK/](http://schedjoules.github.io/iOS-SDK/)
 - Examine the example app "SampleCalendarApp"
 
### And then:
 - Get an AuthorizationToken for your app
 - Integrate the SchedJoules CalendarStore.framework within 5 minutes in your own app
 - Add Automatically Renewable Subscriptions In-App Purchases to [Connect](https://github.com/schedjoules/iOS-SDK/blob/master/connect.md)
 - Happy users!!

## AuthorizationToken
You will need an AuthorizationToken to use the CalendarStore. Obtain one from support@schedjoules.com. 

## License & Copyright
You are allowed to use this framework, it's documentation, bundle resources and examples for the integration of the CalendarStore in your own app only.

**Copyright © SchedJoules 2016.**


## Version History

### 2.0.0
Introduction auto-renewable subscriptions to replace all In-App-Purchases.
Check the updated documention to make a smooth transition.

### 1.4
Added:
 - Intro walkthrough

### 1.3.3
Updated:
 - Settings headers

### 1.3.2
Updated:
 - Swedish & German translation

### 1.3.1
Added:
 - Finnish translation

### 1.3.0
Added:
 - 11 languages: pt, ko, nb, ru, da, es, it, ja, sv, zh, tr

### 1.2.5
Fixed:
 - German translation

### 1.2.4
Added:
 - separate country and language selector

Fixed:
 - solve iOS7 add swipe

### 1.2.3
Added:
 - add French and German

### 1.2.2
Added:
 - sales statistics support

### 1.2.1
Added:
 - Language options

Fixed:
 - Incorrect bar at the top of screen on ioS8 for price popup no longer shows up

### 1.2
Added:
 - price preview popup
 - store analytics (see the Analytics Programming Guide)
 - CalStoreCalendarBundle class to get information about an in-app purchase bundle
 
 Fixed:
 - some iOS8 bugs

### 1.1.2
Added:
 - CalStorePageItemHandlerDelegate protocol for overriding default actions
 - CalStoreCalendarStoreViewController, CalStoreStyledPageViewController, CalStoreWeatherViewController now all have a pageItemHandlerDelegate property
 - OverridingDefaultActions Programming Guide added to the documentation

### 1.1.1
Fixed:
 - A potential crashing bug on iOS5 has been fixed
 - Potentially Reachability duplicatr symbol issue has been resolved (thanks Alex!)
 - Should now work well with WyPopoverController

### 1.1
This release of the CalendarStore adds support for searching the store and an new iPad fullscreen store view. Fixes are included for reported issues and general enhancements.

#### NEW
- Added **Search** functionality via CalStoreSearchRequest and in CalStoreCalendarViewController
- Added **CalStoreStyledPageViewController** for showing custom UI "landing-pages" on iPad
- CalStoreCalendarViewController.**showsActionButtons** allows one to hide the country/restore buttons
- CalStoreCalendarViewControllerDelegate allows to override to showing new view controllers after selecting items
- CalStorePage.**pageType** and CalStorePage.**contentMode** added, to query pages about what kind of data they hold
- CalStorePageItem.**categoryName** added
- Added documentation guide about integrating with **EventKit**

##### CHANGED
- CalStoreWeatherCalendarViewController integrates the 'city' searchbar into the navigationbar on iOS7
- CalStoreWeatherCalendarViewController now extends below the navigationbar on iOS7, for correct blurring
- Introduced class CalStorePageItemPurchasable, holding shared purchasing information for "page" and "calendar" items
  - CalStorePageItemPage and CalStorePageItemCalendar now inherit from CalStorePageItemPurchasable
  - "Page" items now also have purchasing functionality, if canBePurchased is YES

#### FIXED
- Fixed an issue with CalStoreInstallCalendarViewController crashing due to an iOS7 race condition
- Fixed an issue with iOS7 incorrectly hiding the separator lines for the 'Restore Purchases' button
- CalStorePickCountryViewController performance enhancements during scrolling
- CalStoreCalendarViewController now honors the showsCloseButton property



### 1.0.0

- CalStoreCalendarStoreViewController will show the 'Close' button on each page it shows
- Fixed a crash when tapping on the (+)-button instead of the tablecell, when adding weather calendars
