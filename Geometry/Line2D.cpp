#include "Line2D.h"
#include <cmath>
Line2D::Line2D(){}
Line2D::Line2D(Point2D p1, Point2D p2):begin(p1),end(p2) {}
Line2D::Line2D(double x1, double y1, double x2, double y2) : begin(x1, y1), end(x2, y2) {}
void Line2D::SetBegin(double newX, double newY) { begin.Set(newX, newY); }
void Line2D::SetBegin(Point2D p) { begin.Set(p); }
void Line2D::SetEnd(double newX, double newY) { end.Set(newX, newY); }
void Line2D::SetEnd(Point2D p) { end.Set(p); }
double Line2D::GetLength() { return sqrt(pow(begin.GetX() - end.GetX(), 2) + pow(begin.GetY() - end.GetY(), 2)); }
Line2D::~Line2D() {}