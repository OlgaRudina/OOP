#include <iomanip>
#include "Item.h"
#include "Utilities.h"

char Item::delimiter = '|';

unsigned int Item::field_width = 0;

Item::Item(const std::string& record) {

	Utilities extract;
	size_t next_pos = 0;
	bool more = true;

	name = extract.extractToken(record, next_pos, more);  //  Extracts tokens from string using a Utilities object.

	if (field_width < extract.getFieldWidth()) {  //  Resets field_width if the size of the token exceeds the current value
		field_width = extract.getFieldWidth();
	}

	//more is default true, and set to false within nextToken if the item string is at the end. 
	try {
		if (more) { serialNumber = stoi(extract.extractToken(record, next_pos, more)); }
		if (more) { Quantity = stoi(extract.extractToken(record, next_pos, more)); }
		if (more) { description = extract.extractToken(record, next_pos, more); }

	}
	catch (...) {
		throw std::string(record + " <-- *** no token found before the delimiter ***");
	}

}

const std::string& Item::getName() const {
	return name;
}

const unsigned int  Item::getSerialNumber() {

	return serialNumber++;
}

const unsigned int Item::getQuantity() {

	return Quantity;
};

void Item::updateQuantity() {

	if (Quantity > 0) {

		Quantity--;
	}

};


void Item::display(std::ostream& os, bool full) const {

	os << std::left << std::setfill(' ') << std::setw(field_width) << name << "[" <<
		std::right << std::setfill('0') << std::setw(CODE_WIDTH) << serialNumber << "]";
	if (full) {
		os << " Quantity " << std::left << std::setfill(' ') << std::setw(field_width) << Quantity <<
			" Description: " << std::left << std::setw(field_width) << description << std::endl;
	}
	os << std::endl;
};
