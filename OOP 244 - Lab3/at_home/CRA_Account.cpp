
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sict {
	CRA_Account::CRA_Account()
	{
		inFName[0] = '\0';
		inGName[0] = '\0';
		inSin = 0;
		*inYear = 0;
		inNumYears = 0;
		*inBalance = 0;

	}

	void CRA_Account::set(int year, double balance) {

		if (0 != inSin && inNumYears < max_yrs) {
			inYear[inNumYears] = year;
			inBalance[inNumYears] = balance;
			inNumYears++;
		}

		else
		{
			inYear[inNumYears] = 0;
			inBalance[inNumYears] = 0;
			inNumYears = 0;
		}
	}


	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {


		bool valid;
		int sum = 0;
		int evens[4] = { (((sin / 10) % 10) * 2), (((sin / 1000) % 10) * 2), (((sin / 100000) % 10) * 2), (((sin / 10000000) % 10) * 2) }; //add first set of alternates to themselves
		int odds[4] = { (((sin / 100) % 10)), (((sin / 10000) % 10)), (((sin / 1000000) % 10)), (((sin / 100000000) % 10)) };
		for (int i = 0; i < 4; i++)
		{
			sum += ((((evens[i] / 1) % 10) + ((evens[i] / 10) % 10))); //add the digits of each evens sum
			sum += odds[i]; //odds sum + evens sum
		}

		int upTen = ((sum + 9) / 10) * 10; //Next highest integer multiple of 10

		if (((upTen - sum) == (sin / 1) % 10) && sin >= min_sin && sin <= max_sin)//check if the last digit == diffence
		{
			valid = true;
		}
		else
		{
			valid = false;
		}

		if (valid == true && '\0' != familyName && '\0' != givenName) {

			strcpy(inFName, familyName);
			strcpy(inGName, givenName);
			inSin = sin;
		}

		else {

			inFName[0] = '\0';
			inGName[0] = '\0';
			inSin = 0;

		}


	}


	bool CRA_Account::isEmpty() const {

		bool valid = inSin <= min_sin || inSin >= max_sin || '\0' == inFName[0] || '\0' == inGName[0];
		return valid;
	}

	void CRA_Account::display() const {


		if (0 != inSin || '\0' != inFName || '\0' != inGName)

		{
			cout << "Family Name: " << inFName << endl;
			cout << "Given Name : " << inGName << endl;
			cout << "CRA Account: " << inSin << endl;
			cout << fixed;
			cout.precision(2);

			for (int i = 0; i < max_yrs; i++)

			{
				if (inYear[i] == 0)
					break;

				else {

					cout << "Year (" << inYear[i] << ")";

					if (inBalance[i] > 2)

					{
						cout << " balance owing: " << inBalance[i] << endl;
					}

					else if (inBalance[i] < -2)

					{

						cout << " refund due: " << fabs(inBalance[i]) << endl;

					}

					else

					{
						cout << " No balance owing or refund due!" << endl;
					}
				}
			}

		}

		else

		{
			cout << "Account object is empty!" << endl;
		}
	}

}


