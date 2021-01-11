#ifndef POINT2D_H
#define POINT2D_H
class Point2D
{
public:
	Point2D();
	Point2D(double valX, double valY);
	Point2D(Point2D& p);
	double GetX();
	double GetY();
	void SetX(double newX);
	void SetY(double newY);
	void Set(double newX, double newY);
	void Set(Point2D p);
	~Point2D();

private:
	double x, y;
};
double DistanceBetweenTwoPoint(Point2D& p1, Point2D& p2);
#endif // !POINT2D_H

