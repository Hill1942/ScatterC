#include<iostream>

using namespace std;
class Complex
{
	private:
		double real;
		double imag;
	public:
		Complex();
		Complex(double, double);

		//overload "++ǰ��"
		Complex operator++();
		//overload "++����"
		Complex operator++(int);
		//overload "--ǰ��"
		Complex operator--();
		//overload "--����"
		Complex operator--(int);

		//overload "+"
		Complex operator+(Complex&);
		Complex operator+(double secondAddingNum);
		friend Complex operator+(double firstAddingNum, Complex& secondAddingNum);
		//overload "-"
		Complex operator-(Complex&);
		Complex operator-(double secondAddingNum);
		friend Complex operator-(double firstAddingNum, Complex& secondAddingNum);
		//overload "*"
		Complex operator*(Complex&);
		Complex operator*(double secondAddingNum);
		friend Complex operator*(double firstAddingNum, Complex& secondAddingNum);
		//overload "/"
		Complex operator/(Complex&);
		Complex operator/(double secondAddingNum);
		friend Complex operator/(double firstAddingNum, Complex& secondAddingNum);
		//overload ">>" and "<<"
		friend istream& operator>>(istream& input, Complex&);
		friend ostream& operator<<(ostream& output, Complex&);
};