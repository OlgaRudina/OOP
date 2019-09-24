
#include "TaxableProduct.h"
#include <iomanip>

using namespace std;

namespace w6 {

	TaxableProduct::TaxableProduct(int id, double price, char tax) :Product(id, price), p_tax(tax) {};

	double TaxableProduct::getPrice() const {

		return Product::getPrice()* (p_tax == 'H' ? 1.13 : 1.08);

	};

	void TaxableProduct::display(std::ostream& os) const {

		os << setw(10) << p_id
		<< setw(10) << fixed << setprecision(2) << p_price
			<< ' ' << (p_tax == 'H' ? "HST" : "PST") << endl;

	};
}