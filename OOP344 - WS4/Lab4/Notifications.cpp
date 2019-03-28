#include <iostream>
#include "Notifications.h"


namespace w5 {

	static const int MAX = 10;

		//default constructor

	    Notifications::Notifications() :count(0), message(new Message[MAX]) {};

		//destructor

		Notifications::~Notifications() {
		
			delete[] message;

		};

		//copy constructor

		Notifications::Notifications(const Notifications& rhs) :count(0), message(new Message[MAX]){
			
			count = rhs.count;

			for (int i = 0; i < count; i++) {

				message[i] = rhs.message[i];
			}

		};

		//copy assignment operator

		Notifications& Notifications::operator=(const Notifications& rhs) {
		
			if (this != &rhs) {

				if (!message) {

					message = new Message[MAX];
				}

				count = rhs.count;

				for (int i = 0; i < count; i++) {

					message[i] = rhs.message[i];
				}
			}

			return *this;
		};

		//move constructor

		Notifications::Notifications(Notifications&& rhs) :count(rhs.count), message(rhs.message) {
		
			rhs.count = 0;
			rhs.message = nullptr;
		
		};

		//move assignment operator

		Notifications& Notifications::operator=(Notifications&& rhs) {
		
			if (this != &rhs) {
				delete[] message;
				count = rhs.count;
				message = rhs.message;

				rhs.count = 0;
				rhs.message = nullptr;
			}
			return move(*this);

		};

		//adds msg to the set

		void Notifications::operator+=(const Message& rhs) {
		
			if (count < MAX) {

				message[count] = rhs;
				count++;
		}
		
		};

		//inserts the Message objects to the os output stream

		void Notifications::display(std::ostream& os) const {
		
			for (int i = 0; i < count; i++) {

				message[i].display(os);
		}
		};



}