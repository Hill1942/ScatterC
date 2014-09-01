#include<iostream>
#include"Complex.h"

using namespace std;

Complex::Complex()
{
	real = 0;
	imag = 0;
}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
//overload "++前置"
Complex Complex::operator++()
{
	Complex temp;
	temp.real = ++real;
	temp.imag = imag;
	return temp;
}
//overload "++后置"
Complex Complex::operator++(int)
{
	Complex temp = (*this);
	real++;
	return temp;
}
//overload "--前置"
Complex Complex::operator--() 
{
	Complex temp;
	temp.real = --real;
	temp.imag = imag;
	return temp;
}
//overload "--后置"
Complex Complex::operator--(int)
{
	Complex temp = (*this);
	real--;
	return temp;
}
//overload "+"
Complex Complex::operator+(Complex& secondAddingNum)
{
	Complex temp;
	temp.real = real + secondAddingNum.real;
	temp.imag = imag + secondAddingNum.imag;
	return temp;
}
Complex Complex::operator+(double secondAddingNum)
{
	Complex temp;
	temp.real = real + secondAddingNum;
	temp.imag = imag;
	return temp;
}
Complex operator+(double firstAddingNum, Complex& secondAddingNum)
{
	Complex temp;
	temp.real = firstAddingNum + secondAddingNum.real;
	temp.imag = secondAddingNum.imag;
	return temp;
}
//overload "-"
Complex Complex::operator-(Complex& secondAddingNum)
{
	Complex temp;
	temp.real = real - secondAddingNum.real;
	temp.imag = imag - secondAddingNum.imag;
	return temp;
}
Complex Complex::operator-(double secondAddingNum)
{
	Complex temp;
	temp.real = real - secondAddingNum;
	temp.imag = imag;
	return temp;
}
Complex operator-(double firstAddingNum, Complex& secondAddingNum)
{
	Complex temp;
	temp.real = firstAddingNum - secondAddingNum.real;
	temp.imag = -secondAddingNum.imag;
	return temp;
}
//overload "*"
Complex Complex::operator*(Complex& secondAddingNum)
{
	Complex temp;
	temp.real = real * secondAddingNum.real - imag * secondAddingNum.imag;
	temp.imag = real * secondAddingNum.imag + imag * secondAddingNum.real;
	return temp;
}
Complex Complex::operator*(double secondAddingNum)
{
	Complex temp;
	temp.real = real * secondAddingNum;
	temp.imag = imag * secondAddingNum;
	return temp;
}
Complex operator*(double firstAddingNum, Complex& secondAddingNum)
{
	Complex temp;
	temp.real = firstAddingNum * secondAddingNum.real;
	temp.imag = firstAddingNum * secondAddingNum.imag;
	return temp;
}
//overload "/"
Complex Complex::operator/(Complex& secondAddingNum)
{
	Complex temp;
	double denominator;
	denominator = secondAddingNum.real * secondAddingNum.real + secondAddingNum.imag * secondAddingNum.imag;
	temp.real = (real * secondAddingNum.real + imag * secondAddingNum.imag) / denominator;
	temp.imag = (imag * secondAddingNum.real - real * secondAddingNum.imag) / denominator;
	return temp;
}
Complex Complex::operator/(double secondAddingNum)
{
	Complex temp;
	temp.real = real / secondAddingNum;
	temp.imag = imag / secondAddingNum;
	return temp;
}
Complex operator/(double firstAddingNum, Complex& secondAddingNum)
{
	Complex temp;
	double denominator;
	denominator = secondAddingNum.real * secondAddingNum.real + secondAddingNum.imag * secondAddingNum.imag;
	temp.real = firstAddingNum * secondAddingNum.real / denominator;
	temp.imag = -firstAddingNum * secondAddingNum.imag / denominator;
	return temp;
}

istream& operator>>(istream& input, Complex& inputNum)
{
	cout<<"input the real part and imaginary part of complex number: ";
	input>>inputNum.real>>inputNum.imag;
	return input;
}
ostream& operator<<(ostream& output, Complex& outputNum)
{
	output<<"("<<outputNum.real<<", "<<outputNum.imag<<")";
	return output;
}
