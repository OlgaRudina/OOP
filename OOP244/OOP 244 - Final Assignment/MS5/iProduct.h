#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <iostream>
#include <fstream>

namespace AMA
{
	class iProduct
	{
	public:

		virtual ~iProduct() {};
		// insert the Product records into the fstream object
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;

		// extract iProduct records from the fstream object.
		virtual std::fstream& load(std::fstream& file) = 0;

		// insert the iProduct record for the current object into the ostream object
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;

		// extract the iProduct record for the current object from the istream object
		virtual std::istream& read(std::istream& is) = 0;

		// return true if the string is identical to the stock keeping unit of an iProduct record; false otherwise.
		virtual bool operator==(const char*) const = 0;

		// return the cost of a single unit of an iProduct with taxes included
		virtual double total_cost() const = 0;

		// return the name of the iProduct
		virtual const char* name() const = 0;

		// set the number of units available.
		virtual void quantity(int) = 0;

		//return the number of units of an iProduct that are needed.
		virtual int qtyNeeded() const = 0;

		// return the number of units of an iProduct that are currently available
		virtual int quantity() const = 0;

		// return the updated number of units currently available.
		virtual int operator+=(int) = 0;

		// return true if the current object is greater than the referenced iProduct object
		virtual bool operator>(const iProduct&) const = 0;
	};

	// insert the iProduct record for the referenced object into the ostream object
	std::ostream& operator<<(std::ostream& os, const iProduct& p);

	// extract the iProduct record for the referenced object from the istream object
	std::istream& operator>>(std::istream& is, iProduct& p);

	// will add the total cost of the iProduct object to the double received and return the updated value of the double
	double operator+=(double& total, const iProduct& p);

	// Return the address of a Product object
	iProduct* CreateProduct();

	// return the address of a Perishable object
	iProduct* CreatePerishable();
}

#endif //AMA_IPRODUCT_H