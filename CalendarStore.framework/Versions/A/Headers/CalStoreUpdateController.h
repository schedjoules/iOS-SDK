//
//  CalStoreUpdateController.h
//  CalendarStore
//
//  Created by SchedJoules on 11-06-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 This class provides a way to get notified of significant
 changes in the Calendar Store, so you could show appropriate UI
 in your application to notify the user about new content in the store.
 */
@interface CalStoreUpdateController : NSObject

// shared controller
+(instancetype)sharedController;


@property (nonatomic, readonly) NSUInteger numberOfNewItems;

@end
