
#define _CRT_SECURE_NO_WARNINGS
#include "CString.h"
#include <cstring>
#include <iostream>

int STORED = 3;

namespace w1 {

	CString::CString() : MAX{ 0 }, _str{ '\0' }
	{

	}

	CString::CString(const char* string) : MAX{ STORED }
	
	{
		if (string == '\0') {

			_str[0] = '\0';
		}

		else
		{
			strncpy(_str, string, MAX);
			_str[MAX] = '\0';
		}
	
	};

	void CString::display(std::ostream & os) const
	
	{
			os << _str;
	};

	//•	a helper non-friend operator that inserts the stored 
	//string into the left ostream operand.  
	//This operator prefaces the string with the number of the insertion and increment that number
std::ostream& operator<<(std::ostream& os, const CString& string)
{
	string.display(os);
	return os;
}
}