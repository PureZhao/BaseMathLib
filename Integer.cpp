#include "Integer.h"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
Integer::Integer() {
	r = new int[20];
	length = 0;
	capacity = 20;
	flag = false;
}
Integer::Integer(int value) {
	if (value == 0) {
		r = new int[20];
		length = 0;
		capacity = 20;
		flag = false;
		return;
	}
	string s = to_string(value);
	capacity = s.length() + 100;
	flag = false;
	r = new int[capacity];
	int j = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != '-')
			r[j++] = (int)(s[i] - 48);
		else
			flag = true;
	}
	length = j;
}
Integer::Integer(long long value){
	if (value == 0) {
		r = new int[20];
		length = 0;
		capacity = 20;
		flag = false;
		return;
	}
	string s = to_string(value);
	capacity = s.length() + 100;
	flag = false;
	r = new int[capacity];
	int j = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != '-')
			r[j++] = (int)(s[i] - 48);
		else
			flag = true;
	}
	length = j;
}
Integer::Integer(float value) {
	if (value == 0) {
		r = new int[20];
		length = 0;
		capacity = 20;
		flag = false;
		return;
	}
	flag = false;
	string s = to_string(value);
	int n = s.find('.');
	capacity = n + 100;
	r = new int[capacity];
	length = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] != '-')
			r[length++] = (int)(s[i] - 48);
		else
			flag = true;
	}
}
Integer::Integer(double value) {
	if (value == 0) {
		r = new int[20];
		length = 0;
		capacity = 20;
		flag = false;
		return;
	}
	string s = to_string(value);
	int n = s.find('.');
	capacity = n + 100;
	r = new int[capacity];
	length = 0;
	flag = false;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] != '-')
			r[length++] = (int)(s[i] - 48);
		else
			flag = true;
	}
}
Integer::Integer(Integer& number) {
	capacity = number.DigitCount() + 100;
	length = number.DigitCount();
	flag = number.IsNagetive();
	r = new int[capacity];
	for (int i = 0; i < length; i++)
	{
		r[i] = number[i];
	}
}
Integer::~Integer() { delete[] r; }
int Integer::DigitCount() { return length; }
bool Integer::IsNagetive() { return flag; }
void Integer::SetNegative(bool negative) { flag = negative; }
Integer Integer::Absolute() {
	Integer res;
	for (int i = 0; i < length; i++)
	{
		res.Append(r[i]);
	}
	res.SetNegative(false);
	return res;
}
Integer Integer::Opposite() {
	Integer res;
	for (int i = 0; i < length; i++)
	{
		res.Append(r[i]);
	}
	res.SetNegative(!flag);
	return res;
}
void Integer::Append(int value) {
	if (value > 10 || value < 0) return;
	if (length + 1 >= capacity) {
		capacity += 100;
		int* temp = new int[capacity];
		for (int i = 0; i < length; i++)
		{
			temp[i] = r[i];
		}
		temp[length++] = value;
		delete[] r;
		r = temp;
	}
	else {
		r[length++] = value;
	}
}
int Integer::ToInt() {
	if (length == 0) return 0;
	Integer thisNumber;
	for (int i = 0; i < length; i++)
	{
		thisNumber.Append(r[i]);
	}
	thisNumber.SetNegative(flag);
	if (thisNumber > 2147483647) return 2147483647;
	if (thisNumber < -2147483648) return -2147483648;
	int* power = new int[10]{ 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
	int res = 0, start = length - 1;
	for (int i = start; i >= 0; i--)
	{
		res += (r[i] * power[i]);
	}
	if (flag) res = 0 - res;
	delete[] power;
	return res;
}
string Integer::ToString() {
	string res;
	Integer number;
	for (int i = 0; i < length; i++)
	{
		number.Append(r[i]);
	}
	number.SetNegative(flag);
	if (number == 0) return "0";
	if (number < 0) res += "-";
	for (int i = number.DigitCount() - 1; i >= 0; i--)
	{
		res += (char)(number[i] + 48);
	}
	return res;
}
Integer Integer::Power(int time) {
	if (length == 0) return 0;
	if (time == 0) return 1;
	if (time == 1) return GetThisNumber();
	if (time % 2 == 0) {
		Integer temp = Power(time / 2);
		return temp * temp;
	}
	else {
		return GetThisNumber() * Power(time - 1);
	}
}
Integer Integer::Sqrt() {
	if (length == 0) return 0;
	Integer x = GetThisNumber();
	if (x == 1) return 1;
	if (x < 0) return 0;
	Integer y(1);
	while (y * y * 100 < x) y *= 10;
	for (int i = y.DigitCount() - 1; i >= 0; i--)
	{
		Integer temp(10);
		temp = temp.Power(i);
		while ((y + temp) * (y + temp) <= x)
		{
			y += temp;
		}
	}
	return y;
}
void Integer::operator=(Integer number) {
	length = 0;
	for (int i = 0; i < number.DigitCount(); i++)
	{
		Append(number[i]);
	}
	SetNegative(number.IsNagetive());
}
void Integer::operator=(int number) {
	if (number == 0) {
		length = 0;
		return;
	}
	length = 0;
	string s = to_string(number);
	flag = false;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != '-')
			Append((int)(s[i] - 48));
		else
			flag = true;
	}
}
Integer Integer::operator+(Integer& number) {
	if (IsNagetive() == number.IsNagetive()) 
		return Addition(number);
	else
		return Substract(number);
}
Integer Integer::operator+(int number) {
	return GetThisNumber() + Integer(number);
}
void Integer::operator+=(Integer number) {
	Integer a = GetThisNumber() + number;
	length = 0;
	for (int i = 0; i < a.DigitCount(); i++)
	{
		Append(a[i]);
	}
	SetNegative(a.IsNagetive());
}
void Integer::operator+=(int number){
	Integer a = GetThisNumber() + Integer(number);
	length = 0;
	for (int i = 0; i < a.DigitCount(); i++)
	{
		Append(a[i]);
	}
	SetNegative(a.IsNagetive());
}
Integer Integer::operator-() {
	Integer res = GetThisNumber();
	res.SetNegative(!flag);
	return res;
}
Integer Integer::operator-(Integer& number) {
	if (flag != number.IsNagetive()) {
		Integer res(Addition(number));
		res.SetNegative(flag);
		return res;
	}
	else {
		return Substract(number);
	}
}
Integer Integer::operator-(int number) {
	return GetThisNumber() - Integer(number);
}
void Integer::operator-=(Integer& number) {
	Integer a = GetThisNumber() - number;
	length = 0;
	for (int i = 0; i < a.DigitCount(); i++)
	{
		Append(a[i]);
	}
	SetNegative(a.IsNagetive());
}
void Integer::operator-=(int number) {
	Integer a = GetThisNumber() - Integer(number);
	length = 0;
	for (int i = 0; i < a.DigitCount(); i++)
	{
		Append(a[i]);
	}
	SetNegative(a.IsNagetive());
}
Integer Integer::operator*(Integer& number) {
	Integer thisNumber = GetThisNumber();
	Integer res = Product(thisNumber.Absolute(), number.Absolute());
	if (thisNumber.IsNagetive() == number.IsNagetive()) 
		res.SetNegative(false);
	
	else 
		res.SetNegative(true);
	return res;
}
Integer Integer::operator*(int number) {
	return GetThisNumber() * Integer(number);
}
void Integer::operator*=(Integer& number) {
	Integer res = GetThisNumber() * number;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
void Integer::operator*=(int number) {
	Integer res = GetThisNumber() * Integer(number);
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
Integer Integer::operator/(Integer& number) {
	Integer thisNumber = GetThisNumber();
	Integer res = Division(thisNumber.Absolute(), number.Absolute());
	if (thisNumber.IsNagetive() == number.IsNagetive()) 
		res.SetNegative(false);
	else 
		res.SetNegative(true);
	return res;
}
Integer Integer::operator/(int number) {
	return GetThisNumber() / Integer(number);
}
void Integer::operator/=(Integer& number) {
	Integer res = GetThisNumber() / number;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
void Integer::operator/=(int number) {
	Integer res = GetThisNumber() / Integer(number);
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
Integer Integer::operator%(Integer& number) {
	Integer thisNumber = GetThisNumber();
	Integer res;
	res = Mod(GetThisNumber().Absolute(), number.Absolute());
	res.SetNegative(thisNumber.IsNagetive());
	return res;
}
Integer Integer::operator%(int number) {
	return GetThisNumber() % Integer(number);
}
void Integer::operator%=(Integer& number) {
	Integer res = GetThisNumber() % number;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
void Integer::operator%=(int number) {
	Integer res = GetThisNumber() % number;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
}
Integer Integer::operator++() {
	Integer res = GetThisNumber() + 1;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
	return res;
}
Integer Integer::operator++(int) {
	Integer ret(GetThisNumber());
	Integer thisNumber = GetThisNumber() + 1;
	length = 0;
	for (int i = 0; i < thisNumber.DigitCount(); i++)
	{
		Append(thisNumber[i]);
	}
	SetNegative(thisNumber.IsNagetive());
	return ret;
}
Integer Integer::operator--() {
	Integer res = GetThisNumber() - 1;
	length = 0;
	for (int i = 0; i < res.DigitCount(); i++)
	{
		Append(res[i]);
	}
	SetNegative(res.IsNagetive());
	return res;
}
Integer Integer::operator--(int) {
	Integer ret(GetThisNumber());
	Integer thisNumber = GetThisNumber() - 1;
	length = 0;
	for (int i = 0; i < thisNumber.DigitCount(); i++)
	{
		Append(thisNumber[i]);
	}
	SetNegative(thisNumber.IsNagetive());
	return ret;
}
int& Integer::operator[](int i) {
	if (i < 0) i = 0;
	if (i >= length) i = length - 1;
	if (i == -1) return r[0];
	return r[i];
}

//Friend
ostream& operator<<(ostream& os, Integer& number){
	if (number.DigitCount() == 0) {
		os << 0;
		return os;
	}
	if (number.IsNagetive()) 
		os << "-";
	for (int i = number.DigitCount() - 1; i >= 0; i--)
		os << number[i];
	return os;
}
istream& operator>>(istream& is, Integer& number) {
	string s;
	is >> s;
	if (s.empty()) {
		number = 0;
		return is;
	}
	int head = 0;
	while (!(s[head] >= 48 && s[head] <= 57)) head++;
	if (head == s.length()) {
		number = 0;
		return is;
	}
	int tail = head;
	while (tail + 1 < s.length() && (s[tail + 1] >= 48 && s[tail + 1] <= 57)) tail++;
	bool isAllZero = true;
	for (int i = head; i <= tail; i++)
	{
		if (s[i] != 0) isAllZero = false;
	}
	if (isAllZero) {
		number = 0;
		return is;
	}
	bool isNegative = (s[head - 1] == '-');
	while (s[head] == '0') head++;
	number = 0;
	for (int i = tail; i >= head; i--)
	{
		number.Append((int)(s[i] - 48));
	}
	number.SetNegative(isNegative);
	return is;
}

//Private
Integer Integer::Addition(Integer& number) {
	Integer res;
	res.SetNegative(flag);
	int i = 0, j = 0, m = length, n = number.DigitCount();
	bool process = false;
	while (i < m && j < n)
	{
		int value = r[i] + number[j] + (process ? 1 : 0);
		process = false;
		if (value >= 10) {
			process = true;
			value -= 10;
		}
		res.Append(value);
		i++;
		j++;
	}
	while (i < m)
	{
		int value = r[i] + (process ? 1 : 0);
		process = false;
		if (value >= 10) {
			process = true;
			value -= 10;
		}
		res.Append(value);
		i++;
	}
	while (j < n)
	{
		int value = number[j] + (process ? 1 : 0);
		process = false;
		if (value >= 10) {
			process = true;
			value -= 10;
		}
		res.Append(value);
		j++;
	}
	if (process) res.Append(1);
	return res;
}
Integer Integer::Substract(Integer& number) {
	Integer res;
	Integer a;
	for (int k = 0; k < length; k++)
		a.Append(r[k]);
	a.SetNegative(false);
	Integer b(number.Absolute());
	int i = 0, j = 0, m = a.DigitCount(), n = b.DigitCount();
	if (a == b) return res;
	if(a > b){
		res.SetNegative(flag);
		while (i < m && j < n)
		{
			int value = a[i] - b[j];
			if (value < 0) {
				a[i + 1]--;
				value += 10;
			}
			res.Append(value);
			i++;
			j++;
		}
		while (i < m)
		{
			int value = a[i];
			if (value < 0) {
				a[i + 1]--;
				value += 10;
			}
			res.Append(value);
			i++;
		}
	}
	else {
		res.SetNegative(!flag);
		while (i < m && j < n)
		{
			int value = b[j] - a[i];
			if (value < 0) {
				b[j + 1]--;
				value += 10;
			}
			res.Append(value);
			i++;
			j++;
		}
		while (j < n)
		{
			int value = b[j];
			if (value < 0) {
				b[j + 1]--;
				value += 10;
			}
			res.Append(value);
			j++;
		}
	}
	Integer finalRes;
	int pos = res.DigitCount() - 1;
	while (res[pos] == 0) pos--;
	for (int k = 0; k <= pos; k++)
	{
		finalRes.Append(res[k]);
	}
	finalRes.SetNegative(res.IsNagetive());
	return finalRes;
}
/* Product karatsuba */
void Integer::Divide(Integer& a, Integer& b, Integer& source, int half) {
	if (source.DigitCount() <= half) {
		a = 0;
		b = source;
		return;
	}
	else {
		for (int i = 0; i < half; i++)
		{
			b.Append(source[i]);

		}
		for (int i = half; i < source.DigitCount(); i++)
		{
			a.Append(source[i]);
		}
	}
}
Integer Integer::MultiTen(Integer& a, int time) {
	if (a == 0) return a;
	Integer b;
	for (int i = 0; i < time; i++)
	{
		b.Append(0);
	}
	for (int i = 0; i < a.DigitCount(); i++)
	{
		b.Append(a[i]);
	}
	return b;
}
Integer Integer::Product(Integer& num1, Integer& num2) {
	if (num1 == 0 || num2 == 0) return 0;
	if (num1 < 10 || num2 < 10) return num2.ToInt() * num1.ToInt();
	int half = (num1.DigitCount() > num2.DigitCount() ? num1.DigitCount() : num2.DigitCount()) / 2;
	//切分
	Integer a, b, c, d;
	Divide(a, b, num1, half);
	Divide(c, d, num2, half);
	//递归
	Integer z2 = Product(a, c);
	Integer z0 = Product(b, d);
	Integer z1 = Product(a + b, c + d) - z0 - z2;
	//末尾加0
	z2 = MultiTen(z2, 2 * half);
	z1 = MultiTen(z1, half);
	return z2 + z1 + z0;
}
/* Product karatsuba */
Integer Integer::Division(Integer& num1, Integer& num2) {
	if (num2 == 0) return 0;
	if (num1 == 0) return 0;
	if (num1 < num2) return 0;
	Integer res;
	int time = num1.DigitCount() - num2.DigitCount();
	Integer c = MultiTen(num2, time);
	while (num1 >= num2)
	{
		Integer quotient;
		while (num1 >= c)
		{
			num1 -= c;
			quotient++;
		}
		res += MultiTen(quotient, time);
		c = MultiTen(num2, time - 1);
		time--;
	}
	return res;
}
Integer Integer::Mod(Integer& num1, Integer& num2) {
	if (num2 == 0) return 0;
	if (num1 == 0) return 0;
	if (num1 < num2) return 0;
	Integer res;
	int time = num1.DigitCount() - num2.DigitCount();
	Integer c = MultiTen(num2, time);
	while (num1 >= num2)
	{
		while (num1 >= c)
		{
			num1 -= c;
		}
		c = MultiTen(num2, time - 1);
		time--;
	}
	return num1;
}
Integer Integer::GetThisNumber(){
	Integer thisNumber;
	for (int i = 0; i < length; i++)
	{
		thisNumber.Append(r[i]);
	}
	thisNumber.SetNegative(flag);
	return thisNumber;
}


//Wide
bool operator==(Integer& a, Integer& b) {
	if (a.IsNagetive() != b.IsNagetive()) return false;
	if (a.DigitCount() != b.DigitCount()) return false;
	int n = a.DigitCount();
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}
bool operator==(Integer& a, int b) {
	return a == Integer(b);
}
bool operator==(int a, Integer b) {
	return Integer(a) == b;
}
bool operator!=(Integer& a, Integer& b) {
	return !(a == b);
}
bool operator!=(Integer& a, int b) {
	return !(a == Integer(b));
}
bool operator!=(int a, Integer b) {
	return !(Integer(a) == b);
}
bool operator>(Integer& a, Integer& b) {
	if (a.IsNagetive() == false && b.IsNagetive() == true) return true;
	if (a.IsNagetive() == true && b.IsNagetive() == false) return false;
	if (a.IsNagetive() == false && b.IsNagetive() == false) {	//都为正数
		if (a.DigitCount() > b.DigitCount()) return true;
		if (a.DigitCount() < b.DigitCount()) return false;
		int n = a.DigitCount();
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] < b[i]) return false;
			if (a[i] > b[i]) return true;
		}
		return false;
	}
	if (a.IsNagetive() == true && b.IsNagetive() == true) {	//都为负数
		if (a.DigitCount() > b.DigitCount()) return false;
		if (a.DigitCount() < b.DigitCount()) return true;
		int n = a.DigitCount();
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] < b[i]) return true;
			if (a[i] > b[i]) return false;
		}
		return false;
	}
	return false;
}
bool operator>(Integer& a, int b) {
	return a > Integer(b);
}
bool operator>(int a, Integer& b) {
	return Integer(a) > b;
}
bool operator>=(Integer& a, Integer& b) {
	return !(a < b);
}
bool operator>=(Integer& a, int b) {
	return !(a < Integer(b));
}
bool operator>=(int a, Integer& b) {
	return !(Integer(a) < b);
}
bool operator<(Integer& a, Integer& b) {
	if (a == b) return false;
	if (a > b) return false;
	return true;
}
bool operator<(Integer& a, int b) {
	return a < Integer(b);
}
bool operator<(int a, Integer& b) {
	return Integer(a) < b;
}
bool operator<=(Integer& a, Integer& b) {
	return !(a > b);
}
bool operator<=(Integer& a, int b) {
	return !(a > Integer(b));
}
bool operator<=(int a, Integer& b) {
	return !(Integer(a) > b);
}