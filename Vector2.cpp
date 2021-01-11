#include "Vector2.h"
#include <cmath>
Vector2::Vector2() { x = y = 0; }
Vector2::Vector2(double valueX, double valueY) { x = valueX, y = valueY; }
Vector2::Vector2(Vector2& v) { x = v.GetX(); y = v.GetY(); }
void Vector2::Zero() { x = y = 0; }
void Vector2::SetX(double value) { x = value; }
void Vector2::SetY(double value) { y = value; }
double Vector2::GetX() { return x; }
double Vector2::GetY() { return y; }
Vector2 Vector2::Normalize() {
	Vector2 res;
	double mod = sqrt(x*x + y*y);
	res.SetX(x / mod);
	res.SetY(y / mod);
	return res;
}
Vector2::~Vector2(){}

//Wide Function
double operator*(Vector2& a, Vector2& b) { return a.GetX() * b.GetX() + a.GetY() * b.GetY(); }
Vector2 operator+(Vector2& a, Vector2& b) {
	Vector2 res;
	res.SetX(a.GetX() + b.GetX());
	res.SetY(a.GetY() + b.GetY());
	return res;
}
Vector2 operator-(Vector2& a, Vector2& b) {
	Vector2 res;
	res.SetX(a.GetX() - b.GetX());
	res.SetY(a.GetY() - b.GetY());
	return res;
}


