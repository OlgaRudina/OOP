#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#include <iostream>


using namespace std;
namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {

		char inFName[max_name_length];
		char inGName[max_name_length];
		int inSin;

	public:
		
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};

}




#endif