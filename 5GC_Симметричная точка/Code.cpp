
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
	double x;
	double y;

	Point(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
};

struct Line
{
	Point point_1;
	Point point_2;

	double A;
	double B;
	double C;

	Line(double x1, double y1, double x2, double y2)
	{
		point_1.x = x1;
		point_1.y = y1;

		point_2.x = x2;
		point_2.y = y2;

		A = point_1.y - point_2.y;
		B = point_2.x - point_1.x;
		C = point_1.x * point_2.y - point_2.x * point_1.y;
	}

	Line(double a, double b, double c)
	{
		A = a;
		B = b;
		C = c;
	}

	double getA()
	{
		return A;
	}

	double getB()
	{
		return B;
	}

	double getC()
	{
		return C;
	}
};

int main()
{
	double x1, y1, x2, y2;

	cin >> x1 >> y1;
	cin >> x2 >> y2;

	Line first = Line(x1, y1, x2, y2);

	cin >> x1 >> y1;

	Point point_ = Point(x1, y1);

	if (first.getA() * point_.x + first.getB() * point_.y + first.getC() == 0)
	{
		cout << -1;

		return 0;
	}

	Line second = Line(-first.getB(), first.getA(), (first.getB() * point_.x - first.getA() * point_.y));


	double Z = first.getA() * second.getB() - second.getA() * first.getB();

	if (Z != 0) //прямые пересекаются
	{
		double X = -((first.getC() * second.getB() - second.getC() * first.getB()) / Z);
		double Y = -((first.getA() * second.getC() - second.getA() * first.getC()) / Z);

		double new_x = X + X - point_.x;
		double new_y = Y + Y - point_.y;

		cout << fixed;
		cout.precision(28);
		cout << new_x << " " << new_y;

		return 0;
	}

	return 0;
}

