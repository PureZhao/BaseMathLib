#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"

class Line2D
{
public:
	Line2D();
	Line2D(Point2D p1, Point2D p2);
	Line2D(double x1, double y1, double x2, double y2);
	void SetBegin(double newX, double newY);
	void SetBegin(Point2D p);
	void SetEnd(double newX, double newY);
	void SetEnd(Point2D p);
	double GetLength(); 
	~Line2D();

private:
	Point2D begin, end;
};

#endif 
