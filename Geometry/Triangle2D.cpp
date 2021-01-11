#include "Triangle2D.h"
#include <cmath>

Triangle2D::Triangle2D() : a(0, 1), b(-1, 0), c(1, 0) {}
Triangle2D::Triangle2D(Point2D p1, Point2D p2, Point2D p3): a(p1), b(p2), c(p3) {}
double Triangle2D::GetLengthAB() { return DistanceBetweenTwoPoint(a, b); }
double Triangle2D::GetLengthAC() { return DistanceBetweenTwoPoint(a, c); }
double Triangle2D::GetLengthBC() { return DistanceBetweenTwoPoint(b, c); }
//cos=(a*b)|a|*|b|
double Triangle2D::GetCosA() {
	double AB[2], AC[2];
	AB[0] = b.GetX() - a.GetX();
	AB[1] = b.GetY() - a.GetY();
	AC[0] = c.GetX() - a.GetX();
	AC[1] = c.GetY() - a.GetY();
	double ABmultAC = AB[0] * AC[0] + AB[1] * AC[1];
	double modABmultmodAC = GetLengthAB() * GetLengthAC();
	return ABmultAC / modABmultmodAC;
}
double Triangle2D::GetCosB() {
	double BA[2], BC[2];
	BA[0] = a.GetX() - b.GetX();
	BA[1] = a.GetY() - b.GetY();
	BC[0] = c.GetX() - b.GetX();
	BC[1] = c.GetY() - b.GetY();
	double BAmultBC = BA[0] * BC[0] + BA[1] * BC[1];
	double modBAmultmodBC = GetLengthAB() * GetLengthBC();
	return BAmultBC / modBAmultmodBC;
}
double Triangle2D::GetCosC() {
	double CA[2], CB[2];
	CA[0] = a.GetX() - c.GetX();
	CA[1] = a.GetY() - c.GetY();
	CB[0] = b.GetX() - c.GetX();
	CB[1] = b.GetY() - c.GetY();
	double CAmultCB = CA[0] * CB[0] + CA[1] * CB[1];
	double modCAmultmodCB = GetLengthAC() * GetLengthBC();
	return CAmultCB / modCAmultmodCB;
}
double Triangle2D::GetArea() {
	double AB = GetLengthAB();
	double BC = GetLengthBC();
	double AC = GetLengthAC();
	double p = (AB + BC + AC) / 2.0;
	return sqrt(p*(p - BC)*(p - AC)*(p - AB));
	/*
		Helen formula
		S = sqrt[p(p - a)(p - b)(p - c)]
		p = (a + b + c) / 2

	*/
}
int Triangle2D::GetTriangleAngleType() 
{
	double cosa = GetCosA();
	double cosb = GetCosB();
	double cosc = GetCosC();
	if (cosa == 1.0 || cosb == 1.0 || cosc == 1.0) return -1;
	if (cosa == 0.0 || cosb == 0.0 || cosc == 0.0) return 1;
	if (cosa < 0 || cosb < 0 || cosc < 0) return 2;
	return 0;
}

int Triangle2D::GetTriangleSideType() {
	double cosa = GetCosA();
	double cosb = GetCosB();
	double cosc = GetCosC();
	if (cosa == 1.0 || cosb == 1.0 || cosc == 1.0) return -1;
	double AB = GetLengthAB();
	double BC = GetLengthBC();
	double AC = GetLengthAC();
	if (AB == BC && AC == BC && AB == AC) return 0;
	if ((AB == BC && AC == BC) || (AC == BC && AB == AC) || (AB == BC && AB == AC)) return 1;
	return 2;
}
double Triangle2D::GetPerimeter() {
	return GetLengthAC() + GetLengthAB() + GetLengthBC();
}
Triangle2D::~Triangle2D() {}