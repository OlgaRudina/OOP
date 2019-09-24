#include <iostream>
#include <cstring>

#include "ErrorState.h"


using namespace AMA;

namespace AMA {

ErrorState::ErrorState(const char* errorMessage) {

	_message = nullptr;

	if (errorMessage) {

		message(errorMessage);
	}


};

// operator overloading

ErrorState& ErrorState::operator = (const char* em) {

	message(em);
	return *this;

};

// destructor
ErrorState::~ErrorState() {

	delete[] _message;

};

// functions

void ErrorState::clear() {

	delete[] _message;
	_message = nullptr;

};

bool ErrorState::isClear() const {

	if (_message == nullptr) {

		return true;
	}

	else {

		return false;
	}

};

void ErrorState::message(const char* str) {
	if (str != nullptr) {
		if (_message != nullptr) 
		
		{
			//_message[0] = '\0';
			delete[] _message;
			_message = nullptr;
		}

		_message = new char[strlen(str) + 1];
		strncpy(_message, str, strlen(str));

		if (_message[strlen(str)] != '\0') 
		
		{
			_message[strlen(str)] = '\0';
		};
	}
	else {
		//_message = new char[1];
		//_message[0] = '\0';
		_message = nullptr;
	}
};

const char* ErrorState::message()const {

	return _message;

};

//helper functions
std::ostream& operator << (std::ostream& ostr, const ErrorState& errorMessage) {

	if (!errorMessage.isClear()) {

		ostr << errorMessage.message();
	
	}

	return ostr;
}

};