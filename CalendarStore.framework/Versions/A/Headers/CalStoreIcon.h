//
//  CalStoreIcon.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreObject.h"


/*!
 @abstract		Model object for the Icons being used in the Calendar Store.
 
 @discussion	To get the UIImage* for this Icon, use the image property.
				If the image property is nil, use -[fetchImageWithCompletionHandler:].
 
				This class will cache icons for you.
 */
@interface CalStoreIcon : CalStoreObject

@property (nonatomic, readonly) NSURL* url;

@end



typedef void(^CalStoreImageCompletionHandler)(UIImage* image, NSError* error);

/*!
 @abstract	Provides UIImage loading for CalStoreIcon objects
 */
@interface CalStoreIcon (CalStore_Image)

// Functionality to fetch the image associated with the Icon.
//
// If the image has not yet been fetched from its internet URL, -[image] will return nil.
// In that case, use -[fetchImageWithCompletionHandler:] to start fetching the image and
// get a callback when it has completed.
//
// A fetch operation can be cancelled by calling cancelImageFetch.
//
@property (nonatomic, readonly) UIImage* image; // if nil, use fetchImageWithCompletionHandler:
@property (nonatomic, readonly, getter = isFetchingImage) BOOL fetchingImage;
-(void)fetchImageWithCompletionHandler:(CalStoreImageCompletionHandler)completionHandler;
-(void)cancelImageFetch;

@end
