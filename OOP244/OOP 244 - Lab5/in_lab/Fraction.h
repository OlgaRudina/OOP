#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
#include <iostream>

namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		int num;
		int dnom;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		// TODO: declare the + operator overload

	};
}

#endif