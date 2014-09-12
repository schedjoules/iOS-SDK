//
//  CalStoreController.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStoreDefines.h"

/*!
	@abstract	Singleton controller for the Calendar Store.
				The controller manages "global" data and integrates
				with StoreKit.
 
	@discussion
				Since all API request need an authorizationToken,
				the controller manages it. All CalStore API classes will
				use this controller's authorizationToken, unless another
				authorization token is specifically provided.
 
				The authorization token can be added to the Info.plist
				under the 'CalendarStoreAuthorizationToken' key, or 
				can be supplied in code using the setAuthorizationToken:
				setter.
 
 
				FeedbackEmailAddress
				The UI classes of the CalendarStore provides a 'Give feedback' 
				link on the bottom of the screen. This will open up an e-mailform
				for the user to send an e-mail to, with diagnostics information.
				To customize this e-mailaddress, set the CalendarStoreFeedbackEmailAddress
				in your app's Info.plist to the e-mailaddress you want, or
				set it in code via the setFeedbackEmailAddress: setter.
 */
@interface CalStoreController : NSObject

@property (nonatomic, strong) NSString* authorizationToken; // defaults to CalendarStoreAuthorizationToken from the Main bundle's Info.plist
@property (nonatomic, strong) NSString* locale; // the locale used for the Calendar Store, ISO 639-1 code, or en_US (style). Defaults to current locale
@property (nonatomic, strong) NSString* location; // the location used for the Calendar Store, ISO_3166 code. Defaults to current locale.
												  // setting the location will persist accross sessions.

@property (nonatomic, strong) NSString* feedbackEmailAddress; // defaults to CalendarStoreFeedbackEmailAddress from the  Main bundle's Info.plist, if defined, otherwise to 'support@schedjoules.com'.

+(CalStoreController*)sharedController;

@end


/**
 Analytics functionality.
 */
@interface CalStoreController (CalStoreAnalytics)

@property (nonatomic, assign) BOOL optoutFromAnalytics; // if YES, anonymized analytics for the store will not be tracked. Defaults to NO.

@end


/**
 Debugging functionality.
 */
@interface CalStoreController (CalStoreDebugging)

@property (nonatomic, assign) CalStoreDebugLevel debugLevel; // defaults to CalStoreDebugLevelNone
@property (nonatomic, readonly) NSString* libraryVersion; // the version of the library

@end
