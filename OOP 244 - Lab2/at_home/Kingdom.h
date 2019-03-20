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

// TODO: header safeguards

#ifndef SICT_Kingdom_H_
#define SICT_Kingdom_H_

// TODO: sict namespace
namespace sict {
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};


	// TODO: declare the function display(...),
	//         also in the sict namespace

	void display(Kingdom &kingdom);
	void display(Kingdom kingdom[], int count);

}
#endif