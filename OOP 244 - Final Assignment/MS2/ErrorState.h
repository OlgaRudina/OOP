#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <ostream>

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