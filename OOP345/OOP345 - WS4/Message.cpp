#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w5 {

	//default constructor

	Message::Message() {};

	//constructor (retrieves a record, parses and stores it)

	Message::Message(std::ifstream& in, char c) {

		name.clear();
		reply.clear();
		msg.clear();

		string line;

		getline(in, line, c);

		int count = 0;

		// get username

		while (count < line.size() && line[count] != ' ') {

			name += line[count++];
		}

		count++;

		//get responder name

		if (count < line.size() && line[count] == '@') {

			count++;
			while (count < line.size() && line[count] != ' ') {

				reply += line[count++];
			}

			count++;
		}

		//get the message 

		while (count < line.size()) {

			msg += line[count++];
		}

	};

	//returns true if the object is in a safe empty state

	bool Message::empty() const {
	
		return msg.empty();
	};

	//displays the Message objects within the container

	void Message::display(std::ostream& os) const {
	
		os << "Message" << endl;
		os << " User : " << name << endl;
		if (!reply.empty()) {

			os << " Reply : " << reply << endl;
		}

		os << " Tweet : " << msg << endl << endl;
	};

}
