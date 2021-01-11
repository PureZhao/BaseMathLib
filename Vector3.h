#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	Vector3();
	Vector3(double valueX, double valueY, double valueZ);
	Vector3(Vector3& v);
	double GetX();
	double GetY();
	double GetZ();
	void Zero();
	void SetX(double value);
	void SetY(double value);
	void SetZ(double value);
	Vector3 Normalize();
	~Vector3();

private:
	double x, y, z;
};

double operator*(Vector3& a, Vector3& b);
Vector3 operator/(Vector3& a, Vector3& b);
Vector3 operator+(Vector3& a, Vector3& b);
Vector3 operator-(Vector3& a, Vector3& b);
#endif // !VECTOR3_H

