#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Product.h"

#define _CRT_SECURE_NO_WARNINGS

namespace AMA {

	Product::Product(char type) {

		pType = type;
		pSku[0] = '\0';
		pUnit[0] = '\0';
		pAddressName = nullptr;
		pOnHand = 0;
		pNeeded = 0;
		pBeforeTax = 0.0;
		pTaxStat = true;
		pError.isClear();

	}

	Product::Product(const char* sku, const char* name_addr, const char* unit, int onHand, bool taxStat, double beforeTax, int needed)
	{
	
		name(name_addr);

		strncpy(pSku, sku, max_sku_length);
		pSku[max_sku_length] = '\0';

		strncpy(pUnit, unit, max_unit_length);
		pUnit[max_unit_length] = '\0';

		pOnHand = onHand;
		pNeeded = needed;
		pBeforeTax = beforeTax;
		pTaxStat = taxStat;

	};

	Product::~Product() {

		delete[] pAddressName;
		pAddressName = nullptr;
	}


	Product::Product(const Product &p) { //Copy constructor

		if (!p.isEmpty()) {
			pAddressName = nullptr;
		    *this = p;
		}
	}

	void Product::name(const char* name_addr) {

	
			int lenght = strlen(name_addr);
			pAddressName = new char[lenght+1];

			for (int i = 0; i < lenght+1; ++i)
			{
				pAddressName[i] = name_addr[i];
			}

	}

	//returns the address of the C-style string that holds the name of the product.

	const char* Product::name() const {


		return(pAddressName[0] == '\0'|| pAddressName == nullptr ? nullptr : pAddressName);

	};

	//returns the address of the C-style string that holds the sku of the product.

	const char* Product::sku() const {

		return pSku;

	};

	//returns the address of the C-style string that holds the unit of the product.

	const char* Product::unit() const {

		return pUnit;

	};
	//returns the taxable status of the product.

	bool Product::taxed() const {

		return pTaxStat;
	};

	//returns the price of a single item of the product.

	double Product::price() const {

		return pBeforeTax;
	};

	//returns the price of a single item of the product plus any tax that applies to the product.

	double Product::cost() const {

		double cost;
		if (pTaxStat) {

			cost = (pBeforeTax + (pBeforeTax * TAX_RATE));
		}

		else {

			cost = pBeforeTax;
		}

		return cost;

	};

	//receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object.

	void Product::message(const char* error) {

		pError.message(error);

	};

	// returns true if the ErrorState object is clear; false otherwise.

	bool Product::isClear() const {

		return pError.isClear();

	};


	Product& Product::operator= (const Product &p) {

		if (this != &p) {

			pType = p.pType;

			strcpy(pSku, p.sku());
			strcpy(pUnit, p.unit());
			name(p.pAddressName);
			pOnHand = p.pOnHand;
			pNeeded = p.pNeeded;
			pBeforeTax = p.pBeforeTax;
			pTaxStat = p.pTaxStat;
			pError.message(p.pError.message());

		}

	
		return *this;

	};

	std::fstream& Product::store(std::fstream& file, bool newLine) const {

		file << pType;
		file << ",";
		file << sku();
		file << ",";
		file << name();
		file << ",";
		file << pUnit;
		file << ",";
		file << taxed();
		file << ",";
		file << price();
		file << ",";
		file << quantity();
		file << ",";
		file << qtyNeeded();

		if (newLine== true)
		{
			file << '\n';
		}
		return file;
	}

	std::fstream&  Product::load(std::fstream& file) {

		std::string field[8];

		for (int i = 0; i < 8; i++) {

			std::getline(file, field[i], ',');
		}

		Product tempProd = Product(field[1].c_str(), field[2].c_str(), field[3].c_str(), std::stoi(field[4]), std::stoi(field[5]), std::stoi(field[6]), std::stoi(field[7]));
		tempProd.pType = field[0][0];
		tempProd.message(field[8].c_str());

		*this = tempProd;
		return file;

	};

	std::ostream&  Product::write(std::ostream& os, bool linear) const {

		if (linear)
		{
			os << setw(max_sku_length) << left << pSku << '|'
				<< setw(20) << left << pAddressName << '|'
				<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
				<< setw(4) << right << pOnHand << '|'	
				<< setw(10) << left << pUnit << '|'
				<< setw(4) << right << pNeeded << '|';
		}

		else
		{
			os << "Sku: " << pSku << '|' << endl
				<< "Name: " << pAddressName << '|' << endl
				<< "Price: " << pBeforeTax << '|' << endl;
			if (pTaxStat) {

				os << "Price after tax: " << cost() << '|' << endl;
			}

			else {

				os << "N/A"
					<< '|' << endl;
			}

			os << "Quantity On hand: " << pOnHand << '|' << endl
				<< "Quantity needed: " << pNeeded << '|' << endl;
		}

		return os;
	};

	std::istream&  Product::read(std::istream& is) {

		char SKU[max_sku_length + 1];
		char name [max_name_length + 1];
		char unit[max_unit_length + 1];
		int onHand;
		int needed;
		double unit_price;
		char tax;
		bool taxState;
	
		cout << " Sku: ";
		is >> SKU;

		cout << " Name (no spaces): ";
		is >> name;

		cout << " Unit: ";
		is >> unit;

		cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'Y' || tax == 'y')

		{
			taxState = true;
		}

		else if (tax == 'N' || tax == 'n')
		{
			taxState = false;
		}

		else
		{
			is.setstate(std::ios::failbit);
			pError.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) {

			cout << " Price: ";
			is >> unit_price;
			if (is.fail())
			{
				pError.message("Invalid Price Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> onHand;
			if (is.fail())
			{
				pError.message("Invalid Qauntity Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
			{
				pError.message("Invalid Qauntity Needed Entry");
			}
		}

		if (!is.fail()) //checks if there are no error messages, assign input in a temp object and copy assigned values to the current object
		{
			Product temp = Product(SKU, name, unit, onHand, taxState, unit_price, needed);
			*this = temp;
		}
	
		return is;
	};

	bool  Product::operator==(const char* name) const {

		return strcmp(name, pSku) == 0;
	};

	double  Product::total_cost() const {

		double taxed = pBeforeTax * TAX_RATE;
		double plusTax = pBeforeTax + taxed;

		return static_cast<double>(pOnHand * plusTax);

	};

	void  Product::quantity(int units) {

		pOnHand = units;

	};

	bool  Product::isEmpty() const {

		if (pAddressName == nullptr && pType=='N' && pBeforeTax==0 && pNeeded==0 && pOnHand==0 && pSku[0] == '\0' && pTaxStat==true && pUnit[0]=='\0') {

			return true;
		}

		else {

			return false;
		}

	};

	int  Product::qtyNeeded() const {

		return pNeeded;

	};

	int  Product::quantity() const {

		return pOnHand;

	};

	bool  Product::operator>(const char* name) const {

		bool TF;

		if (strcmp(pSku, name) > 0) {

			TF = true;
		}

		else
		{
			TF = false;
		}

		return TF;
	};

	bool  Product::operator>(const Product& p) const {

		bool TF;

		if (strcmp(pAddressName, p.pAddressName) > 0) {

			TF = true;
		}

		else
		{
			TF = false;
		}

		return TF;

	};

	int  Product::operator+=(int addUnits) {
		if (addUnits > 0) {
			pOnHand += addUnits;
		}
		return pOnHand;

	};


	std::ostream& operator<<(std::ostream& os, const Product& p) {

		return p.write(os, true);
	};

	std::istream& operator>>(std::istream& is, Product& p) {

		p.read(is);
		return is;
	};

	double operator+=(double& total, const Product& p) {

		return total += p.total_cost();
	};

}

