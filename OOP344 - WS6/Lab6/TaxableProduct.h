#pragma once
#include <iostream>
#include "Product.h"

namespace w6 {

	class TaxableProduct : public Product {

		char p_tax;

	public:

		TaxableProduct(const int id, const double price, const char tax);
		double getPrice() const;
		void display(std::ostream&) const;

	};
}
