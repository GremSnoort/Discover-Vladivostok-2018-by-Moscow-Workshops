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

	Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
	{
		point_1.x = x1;
		point_1.y = y1;

		point_2.x = x2;
		point_2.y = y2;
	}

	double A()
	{
		return (point_1.y - point_2.y);
	}

	double B()
	{
		return (point_2.x - point_1.x);
	}

	double C()
	{
		return (point_1.x * point_2.y - point_2.x * point_1.y);
	}
};

int main()
{
	double x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	Line first = Line(x1, y1, x2, y2);

	cin >> x1 >> y1 >> x2 >> y2;

	Line second = Line(x1, y1, x2, y2);


	double Z = first.A() * second.B() - second.A() * first.B();

	if (Z != 0) //прямые пересекаются
	{
		double X = -((first.C() * second.B() - second.C() * first.B()) / Z);
		double Y = -((first.A() * second.C() - second.A() * first.C()) / Z);

		cout << 1 << endl;

		cout << fixed;
		cout.precision(9);
		cout << X << " " << Y;



		return 0;
	}
	else
	{
		double a = first.A() * second.C() - second.A() * first.C();
		double b = first.B() * second.C() - second.B() * first.C();

		if (a == 0 && b == 0)
		{
			cout << 2;

			return 0;
		}
		else
		{
			cout << 0;

			return 0;
		}
	}

	return 0;
}

