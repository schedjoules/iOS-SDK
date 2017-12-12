//
//  SJMasterViewController.h
//  SampleCalendarApp
//
//  Created by SchedJoules on 11-02-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <UIKit/UIKit.h>
@import EventKit;
@import EventKitUI;

@interface SJMasterViewController : UITableViewController

-(IBAction)addEvent:(id)sender;
-(IBAction)openStore:(id)sender;
-(IBAction)changeCalendars:(id)sender;

@end
