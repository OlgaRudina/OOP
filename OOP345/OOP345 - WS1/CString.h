#pragma once
#include <iostream>

namespace w1 {
	
	
	class CString {
        const int MAX;
		char _str[10];

	public:
		CString();
		CString(const char* string);
		void display(std::ostream & os) const;

	};

	std::ostream& operator<<(std::ostream& os, const CString& string);
}
