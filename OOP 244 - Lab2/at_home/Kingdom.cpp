/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 27.05.2018
// Author Olga Rudina
// Student ID: 039949136
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
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

	void display(Kingdom kingdom[], int count)
	{
		int i;
		int total = 0;
		

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (i = 0; i < count; i++) {

			cout << i+1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
			total = total + kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}
}