/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 22.05.2018
// Author Olga Rudina
// Description
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

// TODO: the sict namespace

using namespace sict;
using namespace std;

namespace sict {
	// TODO:definition for display(...) 

	void display(Kingdom &kingdom)
	{
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}