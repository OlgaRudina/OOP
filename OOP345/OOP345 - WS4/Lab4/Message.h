#pragma once
#include <string>
#include <fstream>

using namespace std;

namespace w5{

class Message {

	string name, reply, msg;


public:

	//default constructor

	Message();

	//constructor (retrieves a record, parses and stores it)

	Message(std::ifstream& in, char c);

	//returns true if the object is in a safe empty state

	bool empty() const;

	//displays the Message objects within the container

	void display(std::ostream&) const;


};

}