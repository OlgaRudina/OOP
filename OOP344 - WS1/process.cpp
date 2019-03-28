#include <iostream>
#include "CString.h"
#include "process.h"

	void process(char * string, std::ostream& os)
	{
	    static int counter = 0;
		w1::CString str(string);
		os << counter++ << ": " << str << std::endl;
	}