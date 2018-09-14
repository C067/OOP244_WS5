//Name: Callum Dodge
//Date: June 14, 2016
//Workshop: Workshop 5 - In Lab
//Section: D

// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H


// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);

		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(Fraction& rhs);
	};

}
#endif // !FRACTION_H