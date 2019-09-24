#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Contact.h"

using namespace std;
using namespace sict;


Contact::Contact()
{
	*name = '\0';
	phoneNumbers = nullptr;
	numberOfPhones = 0;
}

Contact::~Contact()
{
	delete[] phoneNumbers;
	phoneNumbers = nullptr;
}

Contact::Contact(const char *inName, long long* phoneNum, int numOfPhones) {
	if (inName != nullptr) {
		if (isEmpty()) {
			strncpy(name, inName, 20);
			name[19] = '\0';
			numberOfPhones = numOfPhones;

			//TODO allocate dynamic memory
			if (numberOfPhones > 0) {
				long long *ptr = new long long[numberOfPhones];
				for (int i = 0; i < numberOfPhones; i++) {
					ptr[i] = phoneNum[i];
				}
				phoneNumbers = ptr;
			}
			else {
				phoneNumbers = nullptr;
			}
		}
		else {
			for (int i = 0; i < 21; i++) {
				name[i] = '\0';
			}
			phoneNumbers = nullptr;
			numberOfPhones = 0;
		}
	}
	else {
		for (int i = 0; i < 21; i++) {
			name[i] = '\0';
		}

		phoneNumbers = nullptr;
		numberOfPhones = 0;
	}
}
	
bool Contact::isValid(const long long& phoneNumber) const {

	bool TF = false;
	long long temp = phoneNumber;
	int digits = 0;
	int *phoneDig= nullptr;
	if (phoneNumber > 0) {

		digits = digitsNum(phoneNumber);

			if (digits == 11 || digits == 12) {

				phoneDig = new int[digits];
				toArray(phoneDig, temp, digits);
				if (phoneDig[digits-7] != 0 && phoneDig[digits-10] != 0 && (phoneDig[0] + phoneDig[digits - 11]) != 0) {
					TF = true;
				}

				delete[] phoneDig;
				phoneDig = nullptr;
			}
		}
	return TF;
	}
	



bool Contact::isEmpty() const {
	bool TF = false;
	if (name[0] != '\0') {
		TF = true;
	}
	else if (phoneNumbers != nullptr) {
		TF = true;
	}
	
	return TF;
}

int Contact::digitsNum(long long phoneNumber) const {
	

		int count = 0;
		while (phoneNumber) {
			count++;
			phoneNumber /= 10;
			// number of digits
		}

		return count;

}


int* toArray(int *temp, long long number, const int& digitsNum) {
	
	for (int i = digitsNum - 1; i >= 0; i--) {
		temp[i] = number % 10;
		number /= 10;
	}

	return temp;

}

void Contact::display() const {

	if (!isEmpty()) {
		cout << "Empty contact!" << endl;
	}

	else {
		cout << name << endl;
		if (numberOfPhones > 0) {

			for (int i = 0; i < numberOfPhones; i++) {

				int phoneDigits = digitsNum(phoneNumbers[i]);
				int* phone = new int[phoneDigits];

				toArray(phone, phoneNumbers[i], phoneDigits);

	
				if (phoneDigits == 11) {

					cout << "(+" << phone[0] << ") ";
					
					cout << phone[1] << phone[2] << phone[3] << " ";
					
					cout << phone[4] << phone[5] << phone[6] << "-" << phone[7] << phone[8] << phone[9] << phone[10] << endl;
				}

				else if (phoneDigits == 12) {

					cout << "(+" << phone[0] << phone[1] << ") ";
					 
					cout << phone[2] << phone[3] << phone[4] << " ";
					 
					cout << phone[5] << phone[6] << phone[7] << "-" << phone[8] << phone[9] << phone[10] << phone[11] << endl;
				}

			
				delete[] phone;
				phone = nullptr;
			}
		}
	}
}