// TODO: add your headers here
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
using namespace sict;

namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {

		inName[0] = '\0';
		inDest[0] = '\0';
		inYear = 0;
		inMonth = 0;
		inDay = 0;


	};

	// TODO: implement the constructor with 2 parameters here

	Passenger::Passenger(const char* name, const char* dest) {

		if ('\0' != name && '\0' != dest) {

			strcpy(inName, name);
			strcpy(inDest, dest);
			inYear = 2017;
			inMonth = 7;
			inDay = 1;
		}

		else {
			inName[0] = '\0';
			inDest[0] = '\0';
			inYear = 0;
			inMonth = 0;
			inDay = 0;
		}

	}

	// TODO: implement the constructor with 5 parameters here

	Passenger::Passenger(const char* name, const char* dest, const int year, const int month, const int day) {

		if (name != nullptr && strlen(name) > 0 && dest != nullptr && strlen(dest) > 0 && year >= 2017 && year <= 2020 && month <= 12 && month > 0 && day > 0 && day <= 31) {

			strcpy(inName, name);
			strcpy(inDest, dest);
			inYear = year;
			inMonth = month;
			inDay = day;

		}

		else {

			inName[0] = '\0';
			inDest[0] = '\0';
			inYear = 0;
			inMonth = 0;
			inDay = 0;

		}


	}

	const char* Passenger::name() const {


		return inName;


	}

	// TODO: implement isEmpty query here

	bool Passenger::isEmpty() const {

		if ('\0' == inName[0] || '\0' == inDest[0])
		{
			return true;
		}

		else {

			return false;
		}

	}

	bool Passenger::canTravelWith(const Passenger& pass) const {

		bool YN = strcmp(pass.inDest, inDest) == 0 && pass.inDay == inDay && pass.inMonth == inMonth && pass.inYear == inYear;
			
			return YN;
}
	}

	// TODO: implement display query here

	void Passenger::display() const {

		cout << inName << " - " << inDest << " on " << inYear << "/";

		if (inMonth < 10) {

			cout << "0" << inMonth << "/";

			if (inDay < 10) {
				cout << "0" << inDay << endl;
			}
			else {
				cout << inDay << endl;
			}
		}
		else {
			cout << inMonth << inDay << endl;
		}
	}


    
