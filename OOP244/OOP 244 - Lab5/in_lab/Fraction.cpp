#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Fraction.h"

using namespace std;
using namespace sict;

	Fraction::Fraction() {

		num = 0;
		dnom = 0;

	}

// TODO: implement the two-argument constructor

	Fraction::Fraction(int a, int b) {

		if (a > 0 && b > 0) {

			num = a;
			dnom = b;
			reduce();
		}

		else {
			num = 0;
			dnom = 0;

		}

	}

	

	// TODO: implement the max query

	int Fraction::max() const {

		if (num > dnom) {

			return num;
		}

		else {

			return dnom;
		}



	}

	// TODO: implement the min query
	int Fraction::min() const {

		if (num > dnom) {
			return dnom;
		}
		else {
			return num;
		}


	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}


    // TODO: implement the reduce modifier

	void Fraction::reduce() {

		int x = gcd();
		num = num / x;
		dnom = dnom / x;

	}

    // TODO: implement the display query

	void Fraction::display() const {

		if (num !=0 && dnom!=0 && num!=dnom && num<dnom)
		{   
			cout << num << "/" << dnom; 
			
	}

		else if (dnom == 1) {
			cout << num;
		}


		else {
			cout << "no fraction stored";
		}

	}

    // TODO: implement the isEmpty query

	bool Fraction::isEmpty() const {

		if (num == 0 && dnom == 0) {

			return true;
		}

		else {
			return false;
		}
	}

    // TODO: implement the + operator

	Fraction Fraction::operator+(const Fraction& rhs) const {

		Fraction sum;
			sum.num = (num * rhs.dnom) + (dnom * rhs.num);
			sum.dnom = dnom * rhs.dnom;
		    return sum;
	}
