//
//  CalStoreSubcriptionPurchaseViewController.h
//  CalendarStore
//
//  Created by  Tobias Reinsch on 10.03.16.
//  Copyright © 2016 SchedJoules. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CalStoreSubscriptionIntro;

@interface CalStoreSubcriptionPurchaseViewController : UIViewController

typedef void(^CalStoreSubscriptionIntroCallback)(BOOL canceled);
typedef void(^CalStoreSubscriptionPurchaseCallback)(BOOL canceled, BOOL success, NSError* error);

+ (CalStoreSubcriptionPurchaseViewController*) showFromViewController:(UIViewController *)viewController withCallback:(CalStoreSubscriptionPurchaseCallback)callback;

@end


/**
 @abstract Required protocol for custom purchase intros.
 */
@protocol CalStoreSubscriptionIntro

+(UIViewController*) introWithCallback:(CalStoreSubscriptionIntroCallback) introCallback;

@end