#ifndef RODUCT_H
#define PRODUCT_H
#include <iostream>
#include "ErrorState.h"

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

namespace AMA {
	const int max_sku_length = 7;					// Maximum number of characters in a sku (stock keeping unit)
	const int max_unit_length = 10;				// Maximum number of characters in a sku (stock keeping unit)
	const int max_name_length = 75;				// Maximum number of characters in the users name descriptor for a product length
	const double TAX_RATE = 0.13;				// The current tax rate

	class Product {
		char pType;
		char pSku[max_sku_length + 1];
		char pUnit[max_unit_length + 1];
		char *pAddressName;
		int pOnHand;
		int pNeeded;
		double pBeforeTax;
		bool pTaxStat;
		ErrorState pError;

	protected:

		void name(const char* nameAddress);    //function receives the address of a C-style null-terminated string that holds the name of the product
		const char* name() const;  //returns the address of the C-style string that holds the name of the product.
		const char* sku() const;   //returns the address of the C-style string that holds the sku of the product.
		const char* unit() const;  //returns the address of the C-style string that holds the unit of the product.
		bool taxed() const;        //returns the taxable status of the product.
		double price() const;      //returns the price of a single item of the product.
		double cost() const;       //returns the price of a single item of the product plus any tax that applies to the product.
		void message(const char*); //receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object.
		bool isClear() const;      // returns true if the ErrorState object is clear; false otherwise.

	public:

		Product(char type = 'N');
		Product(const char* sku, const char* name_addr, const char* unit, int onHand = 0, bool taxStat = true, double beforeTax = 0, int needed = 0);
		Product(const Product &p);
		Product& operator= (const Product &p);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* name_addr) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* name_addr) const;
		bool operator>(const Product& p) const;
		int operator+=(int addUnits);
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}

#endif