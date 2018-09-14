//Name: Callum Dodge
//Date: June 14, 2016
//Workshop: Workshop 5 - In Lab
//Section: D

// TODO: insert header files
#include "Fraction.h"

// TODO: continue the namespace
#include <iostream>
using namespace std;
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = -1;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nu, int denom) {
		
		if (nu >= 0 && denom >= 0) {
			numerator = nu;
			denominator = denom;
			reduce();
		}
		else {
			numerator = 0;
			denominator = -1;
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		int result;

		if (numerator > denominator) {
			result = numerator;
		}
		else {
			result = denominator;
		}

		return result;
	}

	// TODO: implement the min query
	int Fraction::min() const {
		int result;

		if (numerator < denominator) {
			result = numerator;
		}
		else {
			result = denominator;
		}

		return result;
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
		int g_c_d = gcd();

		numerator = numerator / g_c_d;
		denominator = denominator / g_c_d;
	
	}

	// TODO: implement the display query
	void Fraction::display() const {

		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else {
			if (denominator != 1) {
				cout << numerator << "/" << denominator;
			}
			else {
				cout << numerator;
			}
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool result;

		if (numerator == 0 || denominator == -1) {
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction tmp;

		if (!(isEmpty() || rhs.isEmpty())) {
			tmp.numerator = denominator * rhs.numerator + numerator * rhs.denominator;
			tmp.denominator = denominator * rhs.denominator;
		}

		return tmp;

	}

	//Overloading the * operator to multiply the two fractions.
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction tmp;

		tmp = *this;

		if (!(isEmpty() || rhs.isEmpty())) {
			tmp.numerator = rhs.numerator * numerator;
			tmp.denominator = rhs.denominator * denominator;
		}

		return tmp;
	}

	//Overloading the == operator to see if both fractions are equal.
	bool Fraction::operator==(const Fraction& rhs) const {
		
		bool result;

		if (!(isEmpty() || rhs.isEmpty())) {

			if (numerator == rhs.numerator && denominator == rhs.denominator) {
				result = true;
			}
			else {
				result = false;
			}
		}
		else {
			result = false;
		}

		return result;
	}

	//Overloading the != operator to see if both fractions are not equal.
	bool Fraction::operator!=(const Fraction& rhs) const {

		bool result;
		if (!(isEmpty() || rhs.isEmpty())) {

			if (!operator==(rhs)) {
				result = true;
			}
			else {
				result = false;
			}
		}
		else {
			result = false;
		}

		return result;
	}

	//Overloading the += operator to add two fractions.
	Fraction Fraction::operator += ( Fraction& rhs) {

		*this = *this + rhs;
		reduce();

		return *this;
	}
}