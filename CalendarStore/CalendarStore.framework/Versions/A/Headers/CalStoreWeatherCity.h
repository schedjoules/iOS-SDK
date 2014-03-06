//
//  CalStoreWeatherCity.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStoreWeatherCity.h"
#import "CalStoreObject.h"
@import CoreLocation;
@import MapKit;

@interface CalStoreWeatherCity : CalStoreObject

@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly) NSString* identifier;
@property (nonatomic, readonly, getter = isCluster) BOOL isCluster;

-(BOOL)isEqual:(id)object;
-(BOOL)isEqualToWeatherCity:(CalStoreWeatherCity*)result;

@end


@interface CalStoreWeatherCity (MapKit_Annotation) <MKAnnotation>

@property (nonatomic, readonly, copy) NSString* title;

@end