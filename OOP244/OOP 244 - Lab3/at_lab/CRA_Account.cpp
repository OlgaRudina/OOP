
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sict {


	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	
		
		if (sin <= max_sin && sin >= min_sin) {
			strcpy(inFName, familyName);
			strcpy(inGName, givenName);
			inSin = sin;
		}

		else {
			strcpy(inFName, "NoName");
			strcpy(inGName, "NoName");
			sin = 0;
		}

	}

	bool CRA_Account::isEmpty() const{

		bool valid = inSin <= min_sin || inSin >= max_sin;
		return valid;
	}

	void CRA_Account::display() const {
		
		
		if (inSin <= max_sin && inSin >= min_sin) {
			cout << "Family Name: " << inFName << endl;
			cout << "Given Name : " << inGName << endl;
			cout << "CRA Account: " << inSin << endl;
		}

		else
		{
			cout << "Account object is empty!" << endl;
		}
	}
}



