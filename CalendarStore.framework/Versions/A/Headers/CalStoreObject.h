//
//  CalStoreObject.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
	@abstract	Base-class for all CalStore Data Objects.
 
	@internally Data-dictionary methods are defined on the CalStorePrivate
				category, those should be used by subclasses.
 */
@interface CalStoreObject : NSObject <NSCopying>

@end
