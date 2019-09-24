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

	};

	// TODO: implement the constructor with 2 parameters here

	Passenger::Passenger(const char* name, const char* dest) {

		if ('\0' != name && '\0' != dest) {

			strcpy(inName, name);
			strcpy(inDest, dest);
		}

		else {
			inName[0] = '\0';
			inDest[0] = '\0';
		}

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

	// TODO: implement display query here

	void Passenger::display() const {

		if (!isEmpty()) {

			cout << inName << " - " << inDest << endl;
		}

		else {

			cout << "No passenger!" << endl;
		}

	}
}

    
