# Sample Calendar App with CalendarStore integration

This is a small sample app that shows how to integrate the CalendarStore framework into an "actual" Calendar app. The app shows a list of upcoming EKEvent's in a UITableView and integrates with the CalendarStore. The app provides extensive documentation on

The app shows how to do the following things:

1. Integrate the CalendarStore.framework and CalendarStore.bundle in your app
2. Set your API key via code
3. Launch the CalendarStore ViewController
4. Set the debugLevel of the CalendarStore to get more logging info
5. Let the CalendarStore use an EKEventStore instance  
6. How to monitor for newly installed EKCalendar objects to make them directly visible to the user

Step 1 to 3 are the only necessary steps, step 5 and 6 are about going the extra mile for your users. In the source, look for comments starting with
	
	// CalendarStore: 

## Getting Started
In SJAppDelegate.h, provide your own `AuthorizationToken` in the line that is commented out. Uncomment the line to make it active:

	// [CalStoreController sharedController].authorizationToken = <# Your AuthorizationToken Here #>;
	
Contact us at support@schedjoules.com if you don't have an AuthorizationToken/API key. 
	

## Enable In-App Purchases Optionally

### BundleIdentifier
If you want to experiment with In-App purchases, you need to change the BundleIdentifier of this app to your own app's BundleIdentifier and use that In-App enabled provisioning profile. 

### In-App purchases
Add Automatically Renewable Subscriptions to iTunes Connect by following the [instructions](https://github.com/schedjoules/iOS-SDK/blob/master/connect.md). You will get an error if no In-App purchases are present.

### Test User
Create a test user on iTunes Connect for the In-App SandBox. Now, **log out of the App Store** on your device in Settings > iTunes & App Stores: tap on your username to log out. Finally, start purchasing an item in the CalendarStore and **log in with your test user**.

### Device Only
The In-App sandbox only works on an actual device, it **does not work in the Simulator**. 