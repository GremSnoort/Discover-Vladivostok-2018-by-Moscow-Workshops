#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>

using namespace std;

int len(pair<int, int> x, pair<int, int> y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int sign(double cos) {
	if (cos == 0) return 0;
	else return cos > 0 ? 1 : -1;
}

int main() {
	vector<pair<int, int>> points = *new vector<pair<int, int>>(3);

	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		points[i] = *new pair<int, int>(x, y);
	}

	int a2 = len(points[0], points[1]),
		b2 = len(points[1], points[2]),
		c2 = len(points[2], points[0]);

	double a = sqrt(a2),
		b = sqrt(b2),
		c = sqrt(c2);

	int sign1 = sign((b2 + c2 - a2) / (2 * b*c)),
		sign2 = sign((a2 + c2 - b2) / (2 * a*c)),
		sign3 = sign((a2 + b2 - c2) / (2 * a*b));

	string res = "";
	if (sign1 == 0 || sign2 == 0 || sign3 == 0) res = "RIGHT";
	if (sign1 > 0 && sign2 > 0 && sign3 > 0) res = "ACUTE";
	if (sign1 < 0 || sign2 < 0 || sign3 < 0) res = "OBTUSE";

	cout << res;

	return 0;
}