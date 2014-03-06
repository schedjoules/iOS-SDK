//
//  CalStorePageItemParameterizedCalendar.h
//  CalendarStore
//
//  Created by SchedJoules on 23-01-14.
//  Copyright (c) 2014 SchedJoules. All rights reserved.
//

#import "CalStorePageItemCalendar.h"
#import "CalStoreCalendarParameterOptions.h"

/*!
	@abstract	A parameterized calendar does not yet have a full url, but
				first needs a set of values for its parameters.
 
				For example, the weather calendar needs to have a CITY
				parameter to have a full url.
 
	@discussion	The url property does return nil, until values for
				all parameters have been supplied.  The non-complete
				url can be fetched as an NSString object using the
				-paramerizableUrl property.
 
				+ The set of all parameters that need to be supplied
				  can be fetched using the parameters property.
					
					E.g. 'rain', 'wind', 'city', 'language'
 
				+ Set properties using the allParametersValues dictionary
				  property our the -[setValue:forParameter:] message.
				  
					E.g. [item setValue:@"en_US" forParameter:'LANGUAGE']
	
 
				+ Some parameters have a fixed list of options the user 
				  can pick from; Use the parametersOptions property to
				  get a dictionary of parameters to CalStoreParameterOptions
				  objects, which hold information about the title and various
				  options possible for that particular parameter.
 
					E.g. 'wind' => {title: 'Vent',
									options: ['kmh' => 'Kilometre/heure', 'mph' => 'Miles/heure']}
 
				+ If parametersOptions is nil, use -[fetchParameterOptionsWithCompletionHandler:]
				  to fetch them asynchronously from the API server.
 
 
				+ To get a full URL for a ParameterizedCalendar, make sure you
				  have supplied values for all parameters:
					- parameters without options need to be supplied by the app (e.g. LANGUAGE, CITYID)
					- parameters with options can be picked by the user with appropriate UI
	
 */
@interface CalStorePageItemParameterizedCalendar : CalStorePageItemCalendar

// parameters to supply
@property (nonatomic, readonly) NSSet* parameters; // a set of the names of all parameters that MUST be supplied to get a full url


// setting parameter values
@property (nonatomic, copy) NSDictionary* allParametersValues; // set with an NSDictionary with values for all parameters mentioned in the parameters properties.
-(void)setValue:(id)value forParameter:(NSString *)key; // sets a single parameter


// convenience
@property (nonatomic, readonly) BOOL hasValuesForAllParameters; // YES iff all parameters have values

@end





typedef void(^CalStoreParametersOptionsCompletionHandler)(NSDictionary* parameterOptions, NSError* error);

/*!
	@abstract	Support for fetching options for the parameters.
	@discussion	Some parameters need to be picked by the user from a list of possible options.
				If parametersOptions is nil, use -[fetchParameterOptionsWithCompletionHandler:] to
				fetch the options from the API server. 
	
				You can cancel a parameterOptions fetch operation using -[cancelParametersOptionsFetch].
 */
@interface CalStorePageItemParameterizedCalendar (CalStore_ParametersOptions)


// an NSDictionary describing the possible values for parameters that have selectable options.
// If nil, use -[fetchParameterOptionsWithCompletionHandler:]
@property (nonatomic, readonly) NSDictionary* parametersOptions;

// Use to fetch parameterOptions when the parameterOptions property is nil.
-(void)fetchParametersOptionsWithCompletionHandler:(CalStoreParametersOptionsCompletionHandler)completionHandler;

// Only use if you don't use the [CalStoreController sharedController].authorizationToken as a token.
-(void)fetchParametersOptionsWithCompletionHandler:(CalStoreParametersOptionsCompletionHandler)completionHandler authorizationToken:(NSString*)authorizationToken;

// cancel an ongoing fetch operation.
-(void)cancelParametersOptionsFetch;
@property (nonatomic, readonly, getter = isFetchingParametersOptions) BOOL fetchingParametersOptions; // YES if a fetch operation is on-going.


// the URL where a JSON object can be found, describing possible values for the parameters. Normally, one uses the parameterOptions property.
@property (nonatomic, readonly) NSURL* parametersOptionsUrl;

@end
