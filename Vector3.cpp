#include "Vector3.h"
#include <cmath>
Vector3::Vector3() { x = y = z = 0; }
Vector3::Vector3(double valueX, double valueY, double valueZ) { x = valueX, y = valueY, z = valueZ; }
Vector3::Vector3(Vector3& v) { x = v.GetX(), y = v.GetY(), z = v.GetZ(); }
double Vector3::GetX() { return x; }
double Vector3::GetY() { return y; }
double Vector3::GetZ() { return z; }
void Vector3::Zero() { x = y = z = 0; }
void Vector3::SetX(double value) { x = value; }
void Vector3::SetY(double value) { y = value; }
void Vector3::SetZ(double value) { z = value; }
Vector3 Vector3::Normalize() {
	Vector3 res;
	double mod = sqrt(x*x + y*y + z*z);
	res.SetX(x / mod);
	res.SetY(y / mod);
	res.SetZ(z / mod);
	return res;
}
Vector3::~Vector3(){}

//Wide Function
double operator*(Vector3& a, Vector3& b) {
	return a.GetX()*b.GetX() + a.GetY()*b.GetY() + a.GetZ()*b.GetZ();
}
Vector3 operator/(Vector3& a, Vector3& b) {
	//(a1,a2,a3)x(b1,b2,b3)=(a2b3-a3b2,a3b1-a1b3,a1b2-a2b1)
	Vector3 res;
	res.SetX(a.GetY()*b.GetZ() - a.GetZ()*b.GetY());
	res.SetY(a.GetZ()*b.GetX() - a.GetX()*b.GetZ());
	res.SetZ(a.GetX()*b.GetY() - a.GetY()*b.GetX());
	return res;
}
Vector3 operator+(Vector3& a, Vector3& b) {
	Vector3 res;
	res.SetX(a.GetX() + b.GetX());
	res.SetY(a.GetY() + b.GetY());
	res.SetZ(a.GetZ() + b.GetZ());
	return res;
}
Vector3 operator-(Vector3& a, Vector3& b) {
	Vector3 res;
	res.SetX(a.GetX() - b.GetX());
	res.SetY(a.GetY() - b.GetY());
	res.SetZ(a.GetZ() - b.GetZ());
	return res;
}