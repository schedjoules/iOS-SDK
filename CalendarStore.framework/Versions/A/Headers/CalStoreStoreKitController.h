//
//  CalStoreStoreKitController.h
//  CalendarStore
//
//  Created by SchedJoules on 27-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStoreDefines.h"

typedef void(^CalStoreStoreKitCompletionHandler)(BOOL succeeded, NSError* error);

/*!
	@abstract	Controller that ties the CalendarStore into Apple's StoreKit framework
				for In-App purchases.
 
	@discussion	This controller allows the app to restore already made purchases using
				the -[restorePurchasesWithCompletionHandler:] method.
				When the isRestoring property changes, the
				kCalStoreRestoringPurchasesStatusChangedNotification is broadcasted.
 
				Apps can also check if In-App purchases are enabled on the device by
				checking if [CalStoreStoreKitController sharedController].canUsePurchases
				returns YES.
 
				When The StoreKitController changes the transaction status for a 
				CalStorePageItemCalendar object being purchased, the 
				kCalStoreOrderStatusChangedNotification notification is sent. The userInfo
				contains a kCalStoreOrderStatusChangedIdentifierKey with the identifier of the
				item that changed status.
 
				When the whole store gets refreshed, the `kCalStoreOrderStatusRefreshAllNotification`
				notification is sent. When receiving this notification, refresh all your UI so that
				changes can be reflected. This notification will be sent, for example, when in-app purchases
				are being synced in over iCloud.
 */
@interface CalStoreStoreKitController : NSObject

+(instancetype)sharedController;

// checking if purchases can be done
-(BOOL)canUsePurchases;

// restoring already ordered products
-(void)restorePurchasesWithCompletionHandler:(CalStoreStoreKitCompletionHandler)completionHandler;
@property (nonatomic, readonly, getter = isRestoring) BOOL restoring;


// If YES, iCloud will be used to sync purchasing information between two apps of the same vendor. See documentation on MultipleApps for more information.
@property (nonatomic, assign, getter = isiCloudSyncEnabled) BOOL iCloudSyncEnabled; // defaults to the Info.plist CalendarStoreiCloudSyncEnabled key value if available, otherwise to NO.

@end
