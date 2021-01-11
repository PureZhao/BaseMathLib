#include "Point2D.h"
#include <cmath>
Point2D::Point2D() { x = 0, y = 0; }
Point2D::Point2D(Point2D& p) {
	x = p.GetX();
	y = p.GetY();
}
Point2D::Point2D(double valX, double valY) { x = valX, y = valY; }
double Point2D::GetX() { return x; }
double Point2D::GetY() { return y; }
void Point2D::SetX(double newX) { x = newX; }
void Point2D::SetY(double newY) { y = newY; }
void Point2D::Set(double newX, double newY) { x = newX, y = newY; }
void Point2D::Set(Point2D p) { x = p.GetX(), y = p.GetY(); }
Point2D::~Point2D(){}


double DistanceBetweenTwoPoint(Point2D& p1, Point2D& p2) {
	return sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2));
}