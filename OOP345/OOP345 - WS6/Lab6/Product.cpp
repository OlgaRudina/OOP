#include "Product.h"
#include "TaxableProduct.h"
#include <iomanip>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace w6 {

	Product::Product(int id, double price) : p_id(id), p_price(price) {};

	double Product::getPrice() const {
		return p_price;
	}

	void Product::display(std::ostream& os) const {

		os << setw(10) << p_id
			<< setw(10) << fixed << setprecision(2) << p_price << ' ' << endl;
	}

	ostream& operator<<(std::ostream& os, const iProduct& oth)
	{
		oth.display(os);
		return os;
	}
	iProduct* readProduct(std::ifstream& is)
	{

		string line;
		getline(is, line);
		stringstream ss;

		if (!line.empty())
		{
			ss.str(line);

			std::vector<std::string> fields;

			std::string buf;
			while (ss >> buf)
				fields.push_back(buf);

			iProduct* oth;
			if (fields.size() == 3)
				oth = new TaxableProduct(stol(fields[0]), stod(fields[1]), fields[2].c_str()[0]);
			else
				oth = new Product(stol(fields[0]), stod(fields[1]));
			return oth;
		}
		else return nullptr;
	}
}