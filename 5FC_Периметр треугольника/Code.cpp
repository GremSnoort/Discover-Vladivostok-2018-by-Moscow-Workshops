
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Line
{
	double A, B, C;

	Line(double a = 0, double b = 0, double c = 0)
	{
		A = a;
		B = b;
		C = c;
	}
};

pair<double, double> vector1;
pair<double, double> vector2;
pair<double, double> vector3;

double lenght1;
double lenght2;
double lenght3;

int main()
{
	double a, b, c;

	cin >> a >> b >> c;
	Line first = Line(a, b, c);

	cin >> a >> b >> c;
	Line second = Line(a, b, c);

	cin >> a >> b >> c;
	Line third = Line(a, b, c);

	double X_12 = 0;
	double Y_12 = 0;

	double X_13 = 0;
	double Y_13 = 0;

	double X_23 = 0;
	double Y_23 = 0;

	int Z_12 = first.A * second.B - second.A * first.B;
	if (Z_12 != 0) //1 & 2
	{
		X_12 = -((first.C * second.B - second.C * first.B) / Z_12);
		Y_12 = -((first.A * second.C - second.A * first.C) / Z_12);
	}

	int Z_13 = first.A * third.B - third.A * first.B;
	if (Z_13 != 0) //1 & 3
	{
		X_13 = -((first.C * third.B - third.C * first.B) / Z_13);
		Y_13 = -((first.A * third.C - third.A * first.C) / Z_13);
	}

	int Z_23 = second.A * third.B - third.A * second.B;
	if (Z_23 != 0) //2 & 3
	{
		X_23 = -((second.C * third.B - third.C * second.B) / Z_23);
		Y_23 = -((second.A * third.C - third.A * second.C) / Z_23);
	}

	vector1.first = X_13 - X_12;
	vector1.second = Y_13 - Y_12;

	vector2.first = X_23 - X_12;
	vector2.second = Y_23 - Y_12;

	vector3.first = X_13 - X_23;
	vector3.second = Y_13 - Y_23;

	lenght1 = sqrt(vector1.first * vector1.first + vector1.second * vector1.second);
	lenght2 = sqrt(vector2.first * vector2.first + vector2.second * vector2.second);
	lenght3 = sqrt(vector3.first * vector3.first + vector3.second * vector3.second);

	double result = lenght1 + lenght2 + lenght3;

	cout << fixed;
	cout.precision(9);
	cout << result;

	return 0;
}

