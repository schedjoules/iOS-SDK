# SchedJoules iOS CalendarStore.framework
With this framework you can easily integrate the SchedJoules Calendar Store in your iOS app, with only a couple lines of code. 

## Overview
The CalendarStore.framework contains both a high level UI  API as well as a low level object API. The high level API allows one to quickly integrate the Calendar Store into your app, while the low level API gives complete control over the data.

## Requirements

### iOS version
The CalendarStore will at least need iOS5 to function. Anything before iOS5 is not supported.

#### Weak Linking
If you need to support iOS5 in your app, you must **weak link** the UIKit framework.

### Xcode
Xcode 5 is required for the CalendarStore framework to work.

### Architectures
The CalendarStore framework supports the armv7, armv7s, arm64 and i386 (simulator), x86_64 (simulator) architectures. Armv6 is not supported.


### User Interface
The User Interface will adapt itself automatically to iOS6 style or iOS7+ style, depending on the user's iOS version.



## Getting Started
To get the CalendarStore.framework up and running, you need to add the Framework and the Bundle to your project and then set your AuthorizationToken.

### Framework
First, drag **CalendarStore.framework** into your project, under the "Frameworks" folder.

![Drag CalendarStore.framework into your project](Readme-Images/CalStore-AddFramework.png)
 
### Bundle
Next, drag **CalendarStore.bundle** into your project. This bundle contains the resources used by the Calendar Store.

![Drag CalendarStore.framework into your project](Readme-Images/CalStore-AddBundle.png)

### AuthorizationToken
Add your **own AuthorizationToken** to the project's Info.plist file under the `CalendarStoreAuthorizationToken` key. If you don't have an AuthorizationToken, you can request one via support@schedjoules.com . 

It's also possible to set your AuthorizationToken in code:

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{
		[CalStoreController sharedController].authorizationToken = <# Your AuthorizationToken Here #>;
	}

![Drag CalendarStore.framework into your project](Readme-Images/CalStore-AddAuthorizationToken.png)

### Set Feedback E-mail
Optionally, set the e-mailaddress that your users can send feedback to. If you don't set it, it will default to support@schedjoules.com. Add your own support e-mailaddress to the project's Info.plist file under the `CalendarStoreFeedbackEmailAddress` key. 

It's also possible to set your own support e-mailaddress in code:

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{
		[CalStoreController sharedController].authorizationToken = <# Your AuthorizationToken Here #>;
		[CalStoreController sharedController].feedbackEmailAddress = <# Your Support Email Here #>;
	}

### Done!
The CalendarStore.framework now successfully has been integrated into your project.

## In-App Purchases

### Enabling In-App Purchases for your App
Since The CalendarStore uses In-App purchases, you'll need to enable In-App Purchases for your app. You can read more on how to do so in Apple's Documentation on this subject: [https://developer.apple.com/library/ios/technotes/tn2259/_index.html](https://developer.apple.com/library/ios/technotes/tn2259/_index.html). 


### Uploading In-App Purchases for your App

#### Initial Upload
With your AuthorizationToken, you also got an **ITMSP** file. This file contains all In-App purchases for the Calendar Store  that need to be uploaded to Apple. By doubleclicking on the file, **Application Loader** will launch. 

1. Log in to Application Loader
2. Deliver your In-App purchases to the store
3. When Submitting an update of your app with the Calendar Store framework, make sure you'll also submit the In-App Purchases

For more info on Application Loader, see [https://itunesconnect.apple.com/docs/UsingApplicationLoader.pdf](https://itunesconnect.apple.com/docs/UsingApplicationLoader.pdf).

#### Updates for In-App Purchases
From time to time, SchedJoules will add or alter the In-App purchases in the CalendarStore. You will receive a new **ITMSP** file with new and changed In-App purchases, which you can deliver to iTunes Connect using **Application Loader**. After delivering the new In-App purchases, be sure to **Submit for Review** all new In-App purchases on iTunes Connect.


## Showing The CalendarStore, the easy way
All it takes to show the CalendarStore is 3 lines of code. First, include the CalendarStore.h header:

	#import <CalendarStore/CalendarStore.h>
	
Next, to launch the Store, present an instance of the CalStoreCalendarStoreViewController. The best place to do this is when a user taps on special "Launch Calendar Store" button.

	CalStoreCalendarStoreViewController* vc = [CalStoreCalendarStoreViewController calendarStoreViewController];
	[self presentViewController:vc animated:YES completion:nil];
	
## Going the Extra Mile: the Low-Level API
If you want more control over how the Calendar Store is displayed, you can use the low-level API of the Calendar Store. This API is also used by the `CalStoreCalendarStoreViewController` class. The low-level API exists of objects modelling the CalendarStore data. Check out the documentation on the `CalStorePage` and `CalStorePageRequest` classes to get started.
