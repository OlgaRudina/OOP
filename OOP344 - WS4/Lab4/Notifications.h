#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w5 {

	class Notifications {

		int count;
		Message* message;

	public:

		//default constructor

		Notifications();

		//destructor

		~Notifications();

		//copy constructor

		Notifications(const Notifications& rhs);

		//copy assignment operator

		Notifications& operator=(const Notifications& rhs);

		//move constructor

		Notifications(Notifications&& rhs);

		//move assignment operator

		Notifications& operator=(Notifications&& rhs);

		//adds msg to the set

		void operator+=(const Message& rhs);

		//inserts the Message objects to the os output stream

		void display(std::ostream& os) const;


	};

}