#pragma once
#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6 {

	class Product : public iProduct {

	protected:

		int p_id;
		double p_price;

	public:
	
		Product(int id, double price);
		double getPrice() const;
		void display(std::ostream&) const;

	};

	};