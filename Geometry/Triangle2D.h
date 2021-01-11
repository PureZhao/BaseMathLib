#ifndef TRIANGLE2D_H
#define TRIANGLE2D_H
#include "Point2D.h"
class Triangle2D
{
public:
	Triangle2D();
	Triangle2D(Point2D p1, Point2D p2, Point2D p3);
	double GetLengthAB();
	double GetLengthAC();
	double GetLengthBC();
	double GetCosA();
	double GetCosB();
	double GetCosC();
	double GetArea();
	/*
	TriangleType divide by angle
		return 0 denotes acute triangle
		return 1 denotes right triangle
		return 2 denotes obtuse triangle
		return -1 denotes this is not a triangle
	*/
	int GetTriangleAngleType();

	/*
	TriangleType divide by side length
	return 0 denotes equilateral triangle
	return 1 denotes isosceles triangle
	return 2 denotes not isosceles(equilateral) triangle
	return -1 denotes this is not a triangle
	*/
	int GetTriangleSideType();
	double GetPerimeter();
	~Triangle2D();

private:
	Point2D a, b, c;
};

#endif // !TRIANGLE2D_H

