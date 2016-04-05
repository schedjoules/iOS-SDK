//
//  CalStoreColorConfiguration.h
//  CalendarStore
//
//  Created by  Tobias Reinsch on 15.03.16.
//  Copyright © 2016 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @abstract A set of colors to customize the CalendarStore.
 */
@interface CalStoreColorConfiguration : NSObject

//color palette
@property (nonatomic, strong) UIColor* _Nullable primaryColor;
@property (nonatomic, strong) UIColor* _Nullable primaryColorDark;
@property (nonatomic, strong) UIColor* _Nullable accentColor;
@property (nonatomic, strong) UIColor* _Nullable primaryBackgroundColor;
@property (nonatomic, strong) UIColor* _Nullable secondaryBackgroundColor;
@property (nonatomic, strong) UIColor* _Nullable accentBackgroundColor;
@property (nonatomic, strong) UIColor* _Nullable textColor;
@property (nonatomic, strong) UIColor* _Nullable inverseTextColor;

+(nonnull instancetype) defaultConfiguration;

@end