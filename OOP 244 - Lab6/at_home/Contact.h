
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <iostream>

namespace sict {


	class Contact
	{

		char name[21];
		long long * phoneNumbers;
		int numberOfPhones;


	public:
		Contact();
		Contact(const char *inName, long long *phoneNum, int numOfPhones);
		~Contact();

		bool isEmpty() const;
		void display() const;

		bool isValid(const long long& phoneNumber) const;
		int digitsNum(long long phoneNumber) const;

		Contact(const Contact& rhs); 
		Contact& operator = (const Contact& rhs); 
		Contact& operator += (const long long& phoneNumber);
		
	};

}

int* toArray(int *temp, long long number, const int& digitsNum);


#endif