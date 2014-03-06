//
//  CalStorePriceInfo.h
//  CalendarStore
//
//  Created by SchedJoules on 30-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CalStorePriceInfo : NSObject <NSCopying>

@property (nonatomic, readonly) NSDecimalNumber* price;
@property (nonatomic, readonly) NSLocale* priceLocale;
@property (nonatomic, readonly) NSString* localizedDisplayPrice;

@end
