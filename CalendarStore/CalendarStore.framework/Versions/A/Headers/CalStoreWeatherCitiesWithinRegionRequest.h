//
//  CalStoreWeatherCitiesWithinRegionRequest.h
//  CalendarStore
//
//  Created by SchedJoules on 28-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CalStoreWeatherCity.h"
@import CoreLocation;
@import MapKit;

typedef void(^CalStoreWeatherCitiesWithinRegionRequestCompletionHandler)(NSArray* cities, NSError* error);

/*!
 @abstract Use to fetch cities within a region.
 */
@interface CalStoreWeatherCitiesWithinRegionRequest : NSObject

// properties
@property (nonatomic, readonly) MKCoordinateRegion region;
@property (nonatomic, readonly) CLLocationCoordinate2D northEastCoordinate;
@property (nonatomic, readonly) CLLocationCoordinate2D southWestCoordinate;

// initializers
+(instancetype)requestWithRegion:(MKCoordinateRegion)region;
+(instancetype)requestWithNorthEastCoordinate:(CLLocationCoordinate2D)northEast southWestCoordinate:(CLLocationCoordinate2D)southWest;


// fetching
@property (nonatomic, strong) NSString* authorizationToken; // defaults to [CalStoreController sharedController].authorizationToken
@property (nonatomic, getter = isFetching, readonly) BOOL fetching; // YES if data is still being fetched


-(void)cancel; // cancels this requests
-(void)fetchWithCompletionHandler:(CalStoreWeatherCitiesWithinRegionRequestCompletionHandler)completionHandler;

@end
