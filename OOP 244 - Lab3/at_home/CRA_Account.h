#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#include <iostream>


using namespace std;
namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {

		char inFName[max_name_length];
		char inGName[max_name_length];
		int inSin;
		int inYear[max_yrs];
		double inBalance[max_yrs];
		int inNumYears = 0;

	public:
		CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};

}




#endif