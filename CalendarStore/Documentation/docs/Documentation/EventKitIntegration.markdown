# EventKit Integration

## Overview
The CalendarStore framework loosely integrates with the EventKit framework. Calendars will be installed as *Subscribed Calendars* into the iOS system, which can be read using the EventKit framework. 

Different methods of installing calendars from the store are planned for future releases.


## EKEventStore Instance
Apps using EventKit usually have one EKEventStore instance they communicate with. Because the CalendarStore also might need an EKEventStore instance, it will try to create one if it doesn't have one. This is of course a waste of resources if the app already has such an instance. Therefore, it's possible to set the EKEventStore instance used by the CalendarStore framework using the `CalStoreEventKitController` class.

One can set the EKEventStore instance using

	[CalStoreEventKitController sharedController].eventStore = <#your EKEventStore instance here#>.
	
## Disable all EventKit integration
It's possible to stop the CalendarStore from using any EventKit objects, such as EKCalendar or EKEventStore. Set the `usesEventKit` property to `NO`:

	[CalStoreEventKitController sharedController].eventStore = NO;
	
	
## Checking if a CalStorePageItemCalendar is installed
Due to limitations of the EventKit framework in iOS, it's very hard for apps to tell if a specific EKCalendar is installed on the user's device: calendarIds, names might all change. This has influence on the `CalStorePageItemCalendar.installed` property.

`CalStorePageItemCalendar.installed` can return either YES, or NO:

- `YES` means that the EKCalendar that got installed still got found
- `NO` means that the EKCalendar was not found, this can have two reasons:
	- the EKCalendar is still installed but has a new id
	- the EKCalendar is no longer installed
  
So, one should only take `YES` as a reliable answer. This property should only be used for informational purposes.

## Responding to newly added EKCalendars
When the CalendarStore installs a new *Subscribed Calendar*, it tries to detect the matching `EKCalendar`. If it succeeded in doing so, a `kCalStoreEKCalendarSubscriptionInstalledNotification` is broadcasted.

The userInfo dictionary of the `NSNotification` will contain the following keys:

- `kCalStoreEKCalendarSubscriptionInstalledCalendarIdentifierKey` the calendarIdentifier of the EKCalendar that got installed
- `kCalStoreEKCalendarSubscriptionInstalledItemKey` the `CalStorePageItemCalendar` object that got installed, if available

#### Good User Experience: Make installed calendars visible
It's a good idea to observe `kCalStoreEKCalendarSubscriptionInstalledNotification` notifications and ensure that the just installed `EKCalendar` is added to your app's list of visible calendars. Otherwise, it might remain hidden and make the user question if the installation succeeded.



