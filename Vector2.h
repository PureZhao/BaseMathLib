#ifndef Vector2_H
#define Vector2_H

class Vector2
{
public:
	Vector2();
	Vector2(double valueX, double valueY);
	Vector2(Vector2& v);
	void Zero();
	void SetX(double value);
	void SetY(double value);
	double GetX();
	double GetY();
	Vector2 Normalize();
	~Vector2();

private:
	double x, y;
};
double operator*(Vector2& a, Vector2& b);
Vector2 operator+(Vector2& a, Vector2& b);
Vector2 operator-(Vector2& a, Vector2& b);
#endif
