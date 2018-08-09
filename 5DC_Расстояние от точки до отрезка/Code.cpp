#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class tup {
public:
	double first;
	double second;

	tup(double a = 0, double b = 0) {
		first = a;
		second = b;
	}
};

double dot(tup v, tup w) {
	return v.first * w.first + v.second * w.second;
}

double len(tup v) {
	return sqrt(dot(v, v));
}

double distance(tup v, tup w) {
	tup diff = *new tup(v.first - w.first, v.second - w.second);
	return len(diff);
}

class segment {
public:
	tup p1;
	tup p2;

	segment(tup x, tup y) {
		p1 = x;
		p2 = y;
	}

	tup to_vec() {
		return *new tup(p2.first - p1.first, p2.second - p1.second);
	}

	double distance_to(tup p) {
		if (p1.first == p2.first && p1.second == p2.second) {
			return distance(p, p1);
		}

		tup v = to_vec();
		tup w = *new tup(p.first - p1.first, p.second - p1.second);

		double d = dot(v, w);
		if (d <= 0) {
			return distance(p, p1);
		}

		double d1 = dot(v, v);
		if (d1 <= d) {
			return distance(p, p2);
		}

		double b = d / d1;
		tup proj = *new tup(p1.first + b * v.first, p1.second + b * v.second);

		return distance(p, proj);
	}
};

int main() {
	double x, y;
	std::cin >> x >> y;
	tup p = *new tup(x, y);
	std::cin >> x >> y;
	tup p1 = *new tup(x, y);
	std::cin >> x >> y;
	tup p2 = *new tup(x, y);

	segment s = *new segment(p1, p2);

	std::cout << std::fixed;
	std::cout.precision(25);
	std::cout << s.distance_to(p);

	return 0;
}