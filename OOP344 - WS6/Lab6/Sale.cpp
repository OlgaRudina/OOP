#include <string>
#include <fstream>
#include <iomanip>
#include <string>
#include "Sale.h"
#include "Product.h"
using namespace std;

namespace w6 {

	Sale::Sale(const char* fn) {
		ifstream ifs(fn);
		iProduct* prod;

		// while not end of file, and the product returned is not an empty one
		// add to the list of products

		while (ifs.good() && (prod = readProduct(ifs)) != nullptr)
			productList.push_back(prod);
		}


	void Sale::display(std::ostream& os) const {
		os << setw(10) << "Product No"
			<< setw(10) << "Price"
			<< " Taxable" << endl;
		double total = 0;
		for (auto prod : productList)
		{
			prod->display(os);
			total += prod->getPrice();
		}
		os << setw(10) << "Total"
			<< fixed << setprecision(2) << setw(10) << total << endl;
	}
}