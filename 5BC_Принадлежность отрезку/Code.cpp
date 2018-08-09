#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> point;
pair<int, int> one;
pair<int, int> two;

pair<int, int> x_range;
pair<int, int> y_range;

int main()
{
	cin >> point.first >> point.second >> one.first >> one.second >> two.first >> two.second;

	if (one.first < two.first)
	{
		x_range.first = one.first;
		x_range.second = two.first;
	}

	else
	{
		x_range.first = two.first;
		x_range.second = one.first;
	}

	if (one.second < two.second)
	{
		y_range.first = one.second;
		y_range.second = two.second;
	}

	else
	{
		y_range.first = two.second;
		y_range.second = one.second;
	}

	if (point.first < x_range.first || point.first > x_range.second || point.second < y_range.first || point.second > y_range.second)
	{
		cout << "NO";
		return 0;
	}

	int A = one.second - two.second;
	int B = two.first - one.first;
	int C = one.first * two.second - two.first * one.second;

	if (point.first * A + point.second * B + C == 0)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}

