#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <string>
using namespace std;
class Integer
{
private:
	int* r;
	int length;
	int capacity;
	bool flag;

	Integer Addition(Integer& number);
	Integer Substract(Integer& number);
	/* Product karatsuba */
	Integer Product(Integer& num1, Integer& num2);
	Integer MultiTen(Integer& a, int time);
	void Divide(Integer& a, Integer& b, Integer& source, int half);
	/* Product karatsuba */
	Integer Division(Integer& num1, Integer& num2);
	Integer Mod(Integer& num1, Integer& num2);
	Integer GetThisNumber();
public:
	Integer();
	Integer(int value);
	Integer(long long value);
	Integer(float value);
	Integer(double value);
	Integer(Integer& number);
	~Integer();
	int DigitCount();
	bool IsNagetive();
	void SetNegative(bool negative);
	Integer Absolute();
	Integer Opposite();
	void Append(int value);
	int ToInt();
	string ToString();
	Integer Power(int time);
	Integer Sqrt();
	void operator=(Integer number);
	void operator=(int number);
	Integer operator+(Integer& number);
	Integer operator+(int number);
	void operator+=(Integer number);
	void operator+=(int number);
	Integer operator-(Integer& number);
	Integer operator-();
	Integer operator-(int number);
	void operator-=(Integer& number);
	void operator-=(int number);
	Integer operator*(Integer& number);
	Integer operator*(int number);
	void operator*=(Integer& number);
	void operator*=(int number);
	Integer operator/(Integer& number);
	Integer operator/(int number);
	void operator/=(Integer& number);
	void operator/=(int number);
	Integer operator%(Integer& number);
	Integer operator%(int number);
	void operator%=(Integer& number);
	void operator%=(int number);
	Integer operator++();
	Integer operator++(int);
	Integer operator--();
	Integer operator--(int);
	int& operator[](int i);

	friend ostream& operator<<(ostream& os, Integer& number);
	friend istream& operator>>(istream& is, Integer& number);

	
};

bool operator==(Integer& a, Integer& b);
bool operator==(Integer& a, int b);
bool operator==(int a, Integer b);
bool operator!=(Integer& a, Integer& b);
bool operator!=(Integer& a, int b);
bool operator!=(int a, Integer b);
bool operator>(Integer& a, Integer& b);
bool operator>(Integer& a, int b);
bool operator>(int a, Integer& b);
bool operator>=(Integer& a, Integer& b);
bool operator>=(Integer& a, int b);
bool operator>=(int a, Integer& b);
bool operator<(Integer& a, Integer& b);
bool operator<(Integer& a, int b);
bool operator<(int a, Integer& b);
bool operator<=(Integer& a, Integer& b);
bool operator<=(Integer& a, int b);
bool operator<=(int a, Integer& b);
#endif
