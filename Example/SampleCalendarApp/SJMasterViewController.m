//
//  SJMasterViewController.m
//  SampleCalendarApp
//
//  Created by SchedJoules on 11-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "SJMasterViewController.h"
#import <CalendarStore/CalendarStore.h> // CalendarStore: include the CalendarStore headers
@import EventKit;
@import EventKitUI;

@interface SJMasterViewController () <EKEventEditViewDelegate, EKCalendarChooserDelegate>

// DateFormatter
@property (nonatomic, strong) NSDateFormatter* dateFormatter; // used to format dates in the tableviewcells

// EventKit
@property (nonatomic, strong) EKEventStore* eventStore; // the eventstore we load events from
@property (strong) NSArray* events; // the upcoming events
@property (strong) NSArray* visibleCalendars; // the calendars that are visible to the user

@end

@implementation SJMasterViewController

-(void)dealloc
{
	// stop observing for the notifications we registered to
	[[NSNotificationCenter defaultCenter] removeObserver:self name:EKEventStoreChangedNotification object:self.eventStore];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kCalStoreEKCalendarSubscriptionInstalledNotification object:nil];
}


- (void)viewDidLoad
{
    [super viewDidLoad];
	
	// Initialize our dateFormatter with a nice, clean style of formatting
	self.dateFormatter = [NSDateFormatter new];
	self.dateFormatter.dateStyle = NSDateFormatterMediumStyle;
	self.dateFormatter.timeStyle = NSDateFormatterShortStyle;
	self.dateFormatter.doesRelativeDateFormatting = YES;
	
	[self liftOffEventKit];
}


#pragma mark - EventKit

-(void)liftOffEventKit
{
	// check if we have permission to use EventKit for Events
	EKAuthorizationStatus authorizationStatus = [EKEventStore authorizationStatusForEntityType:EKEntityTypeEvent];
	switch (authorizationStatus)
	{
		// if so, load the events
		case EKAuthorizationStatusAuthorized:
			[self loadEventStoreAndEvents];
			break;
		
		// if not, show a warning
		case EKAuthorizationStatusDenied:
		case EKAuthorizationStatusRestricted:
			[self showNoEventKitAccessWarning];
			break;
			
		// if unknown, ask for permission and act accordingly if permission was granted or not
		case EKAuthorizationStatusNotDetermined:
			self.eventStore = [EKEventStore new];
			[self.eventStore requestAccessToEntityType:EKEntityTypeEvent completion:^(BOOL granted, NSError* error){
				dispatch_async(dispatch_get_main_queue(), ^{
					if(granted)
						[self loadEventStoreAndEvents];
					else
						[self showNoEventKitAccessWarning];
				});
				
			}];
			break;
	}
}

-(void)loadEventStoreAndEvents
{
	// create the event store and start loading events
	self.eventStore = [EKEventStore new];
	self.visibleCalendars = [self.eventStore calendarsForEntityType:EKEntityTypeEvent];
	[self reloadEvents];
	
	// register _our_ eventstore as the one the CalendarStore framework should use
	[CalStoreEventKitController sharedController].eventStore = self.eventStore;
	
	// when the eventstore changes, we need to reload all events
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reloadEvents) name:EKEventStoreChangedNotification object:self.eventStore];
	
	// CalendarStore: Observe for notifications about when the CalendarStore installed a calendar: we can then make sure it is visible to the user also
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(storeInstalledCalendar:) name:kCalStoreEKCalendarSubscriptionInstalledNotification object:nil];
}

-(void)reloadEvents
{
	// We load one week of events ahead of now, in a background queue
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
		NSDate* startDate = [NSDate date]; // start at now
		NSDate* endDate = [startDate dateByAddingTimeInterval:7 * 24 * 60 * 60]; // one week ahead
		
		// load the events and sort them according to start date
		NSPredicate* predicate = [self.eventStore predicateForEventsWithStartDate:startDate endDate:endDate calendars:self.visibleCalendars];
		NSArray* loadedEvents = [self.eventStore eventsMatchingPredicate:predicate];
		self.events = [loadedEvents sortedArrayUsingSelector:@selector(compareStartDateWithEvent:)];
		
		// and reload the tableview on the main queue
		dispatch_async(dispatch_get_main_queue(), ^{
			[self.tableView reloadData];
		});
	});
}

-(void)showNoEventKitAccessWarning
{
	UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"No Calendar Access" message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
	[alert show];
}

#pragma mark - CalendarStore Notifications
-(void)storeInstalledCalendar:(NSNotification*)notification
{
	// CalendarStore:
	
	// If we got this notification, the CalendarStore just installed a new EKCalendar to the system. We want to make sure
	// it is visible to the user, otherwise the user might not know where the events of his just installed calendar are.
	
	// First, we get the calendarIdentifier from the notification
	NSString* justInstalledCalendarIdentifier = notification.userInfo[kCalStoreEKCalendarSubscriptionInstalledCalendarIdentifierKey];
	if(justInstalledCalendarIdentifier != nil)
	{
		// Next, we get the EKCalendar for this calendarIdentifier from the eventStore
		EKCalendar* justInstalledCalendar = [self.eventStore calendarWithIdentifier:justInstalledCalendarIdentifier];
		if(justInstalledCalendar != nil)
		{
			// Finally, if the calendar is not yet in the list of visibleCalendars, add it to it
			if(![self.visibleCalendars containsObject:justInstalledCalendar])
			{
				self.visibleCalendars = [self.visibleCalendars arrayByAddingObject:justInstalledCalendar];
				
				// And of course, reload our list of events, so it matches with the visibleCalendars again
				[self reloadEvents];
			}
		}
	}
}


#pragma mark - EKEventEditViewDelegate Methods

- (void)eventEditViewController:(EKEventEditViewController *)controller didCompleteWithAction:(EKEventEditViewAction)action
{
	[controller dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - EKCalendarChooserDelegate Methods

// Called whenever the selection is changed by the user
- (void)calendarChooserSelectionDidChange:(EKCalendarChooser *)calendarChooser
{
	// the user changed the selection of calendars that are visible, so register their choices and reload the event
	self.visibleCalendars = [calendarChooser.selectedCalendars allObjects];
	
	// and reload the events, so the events list we have matches with the new list of visibleCalendars
	[self reloadEvents];
}


- (void)calendarChooserDidFinish:(EKCalendarChooser *)calendarChooser
{
	[calendarChooser dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Button Callbacks

-(IBAction)addEvent:(id)sender
{
	// show the 'Edit Event' screen from EventKit for a new, empty event
	EKEventEditViewController* vc = [[EKEventEditViewController alloc] init];
	vc.eventStore = self.eventStore;
	vc.editViewDelegate = self;
	[self presentViewController:vc animated:YES completion:nil];
}

-(IBAction)openStore:(id)sender
{
	// CalendarStore: Open the CalendarStore by presenting a CalStoreCalendarStoreViewController instance
	CalStoreCalendarStoreViewController* vc = [[CalStoreCalendarStoreViewController alloc] init];
	[self presentViewController:vc animated:YES completion:nil];
}

-(IBAction)changeCalendars:(id)sender
{
	// Create a calendar picker in which the user can select visible calendars
	EKCalendarChooser* vc = [[EKCalendarChooser alloc] initWithSelectionStyle:EKCalendarChooserSelectionStyleMultiple displayStyle:EKCalendarChooserDisplayAllCalendars entityType:EKEntityTypeEvent eventStore:self.eventStore];
	vc.selectedCalendars = [NSSet setWithArray:self.visibleCalendars];
	vc.delegate = self;
	vc.showsDoneButton = YES;
	
	// And wrap it inside a UINavigationController, so we can present it modally and will have a title bar.
	UINavigationController* navVc = [[UINavigationController alloc] initWithRootViewController:vc];
	[self presentViewController:navVc animated:YES completion:nil];
	
}


#pragma mark - Table View

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return self.events.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];

	// show the title and the startDate of the event in our cell
	EKEvent* event = self.events[indexPath.row];
	cell.textLabel.text = event.title;
	cell.detailTextLabel.text = [self.dateFormatter stringFromDate:event.startDate];
	cell.detailTextLabel.textColor = [UIColor grayColor];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	// when selected, open details about the event
	EKEventViewController* vc = [[EKEventViewController alloc] init];
	vc.hidesBottomBarWhenPushed = YES;
	vc.event = self.events[indexPath.row];
	vc.allowsEditing = YES;
	[self.navigationController pushViewController:vc animated:YES];
}

@end
