#ifndef ERRORSTATE_H
#define ERRORSTATE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace AMA {

	class ErrorState {

		char* _message;

	public:
		// constructors
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;

		// operator overloading
		ErrorState& operator=(const ErrorState& em) = delete;
		ErrorState& operator = (const char* em);
		
		// destructor
		virtual ~ErrorState();

		// functions

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
};
	//helper functions
	std::ostream& operator << (std::ostream& ostr, const ErrorState& errorMessage);
}

#endif 