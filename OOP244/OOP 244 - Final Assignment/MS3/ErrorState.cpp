#include <iostream>
#include "ErrorState.h"
#include <cstring>

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
		clear();
		_message = new char[strlen(str) + 1];
		strcpy(_message, str);
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