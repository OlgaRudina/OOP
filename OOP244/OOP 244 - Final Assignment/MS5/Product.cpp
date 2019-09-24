#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Product.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace AMA {

	Product::Product(char type) {

		pType = type;
		pSku[0] = '\0';
		pAddressName = nullptr;
		pUnit[0] = '\0';
		pTaxStat = true;
		pBeforeTax = 0.0;
		pOnHand = 0;
		pNeeded = 0;
		//pError.isClear();
		//pError.clear();

	}

	Product::Product(const char* sku, const char* name_addr, const char* unit,bool taxStat, double beforeTax,  int onHand, int needed)
	{
		name(name_addr);

		strncpy(pSku, sku, max_sku_length);
		pSku[max_sku_length] = '\0';

		strncpy(pUnit, unit, max_unit_length);
		pUnit[max_unit_length] = '\0';
        pTaxStat = taxStat;
        pBeforeTax = beforeTax;
		pOnHand = onHand;
		pNeeded = needed;
		
		
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
		if (file.is_open()){

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
	}
		if (newLine == true)
		{
			file << '\n';
		}
		return file;
	}

	std::fstream&  Product::load(std::fstream& file) {

		char sku[max_sku_length];
		char name[max_name_length];
		char unit[max_unit_length];
		double price;
		int qty, needed;
		char tax;
		bool taxable;

		if (file.is_open())
		{
			file.getline(sku, max_sku_length, ',');
			sku[strlen(sku)] = '\0';

			file.getline(name, max_name_length, ',');
			name[strlen(name)] = '\0';

			file.getline(unit, max_unit_length, ',');
			unit[strlen(unit)] = '\0';

			file >> tax;

			if (tax == '1')
				taxable = true;
			else if (tax == '0')
				taxable = false;

			file.ignore();

			file >> price;
			file.ignore();

			file >> qty;
			file.ignore();

			file >> needed;
			file.ignore();

			*this = Product(sku, name, unit, taxable, price, qty, needed);
		}

		return file;

	};

	std::ostream&  Product::write(std::ostream& os, bool linear) const {
		
		if (!(pError.isClear()))

		{
			os << pError.message();
		}

		else if (linear)
			{
				os << setfill (' ') << setw(max_sku_length) << left << pSku << '|'
					<< setw(20) << left << pAddressName << '|'
					<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
					<< setw(4) << right << pOnHand << '|'
					<< setw(10) << left << pUnit << '|'
					<< setw(4) << right << pNeeded << '|';
			}

		else
			{
				os << " Sku: " << pSku << endl
					<< " Name (no spaces): " << pAddressName << endl
					<< " Price: " << pBeforeTax << endl;
				if (pTaxStat) {

					os << " Price after tax: " << cost() << endl;
				}

				else {

					os << " Price after tax: N/A" << endl;
				}

				os << " Quantity on Hand: " << pOnHand << ' ' << pUnit << endl
					<< " Quantity needed: " << pNeeded;
			}
             
		return os;

		
	};

	std::istream&  Product::read(std::istream& is) {


		char SKU[max_sku_length + 1];
		char addrName [max_name_length + 1];
		char unit[max_unit_length + 1];
		int onHand;
		int needed;
		double unit_price;
		char tax;
		bool taxState;
	
		cout << " Sku: ";
		is >> SKU;
		cin.ignore();

		cout << " Name (no spaces): ";
		is >> addrName;
		name(addrName);

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
				pError.message("Invalid Quantity Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
			{
				pError.message("Invalid Quantity Needed Entry");
			}
		}

		if (!is.fail()) //checks if there are no error messages, assign input in a temp object and copy assigned values to the current object
		{
			char tempType = this->pType;
			Product temp = Product(SKU, addrName, unit, taxState, unit_price, onHand, needed);
			*this = temp;
			this->pType = tempType;
		}

	    cin.ignore(1000, '\n');
		return is;
		
	};

	bool  Product::operator==(const char* name) const {

		return strcmp(name, pSku) == 0;
	};

	double  Product::total_cost() const {

		double taxed = pBeforeTax * TAX_RATE;
		double plusTax = pBeforeTax + taxed;

		return (pOnHand * plusTax);

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

	bool  Product::operator>(const iProduct& p) const {

		bool TF;

		if (strcmp(pAddressName, p.name()) > 0) {

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


	std::ostream& operator<<(std::ostream& os, const iProduct& p) {

		return p.write(os, true);
	};

	std::istream& operator>>(std::istream& is, iProduct& p) {

		p.read(is);
		return is;
	};

	double operator+=(double& total, const iProduct& p) {

		return total += p.total_cost();
	};

}

