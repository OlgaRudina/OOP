// TODO: add file header comments here

// TODO: add header file guard here

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#include <iostream>

// TODO: declare your namespace here

namespace sict {
	// TODO: define the Passenger class here
	class Passenger
	{
		char inName[32];
		char inDest[32];

	public:
		Passenger();
		Passenger(const char* , const char* );
		bool isEmpty() const;
		void display() const;


	};


}
#endif