#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include"iProduct.h"

namespace w6 {
	class Sale {

	private:
		std::vector<iProduct*> productList;

	public:
		Sale(const char*);
		void display(std::ostream&) const;
	};
}