## Version History

### 2.3.4
* Add subscription information in accordance with Apple's Schedule 2, Section 3.8(b) requirements for partner implementations

### 2.2.1
* Add subscription information in accordance with Apple's Schedule 2, Section 3.8(b) requirements

### 2.2.0
* Update UI conform iOS11

### 2.1.0
* Update intro screens
* Fix bug that prevented some users from subscribing to calendars after free trial period ended
* Fix bug that caused some users receiving erroneous notifications

### 2.0.1
Fixed missing isFetchingImage selector

### 2.0.0
Introduction auto-renewable subscriptions to replace all In-App-Purchases.

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
