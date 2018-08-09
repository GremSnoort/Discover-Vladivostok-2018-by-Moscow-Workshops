#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> points = *new vector<pair<int, int>>(n + 1);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points[i] = *new pair<int, int>(x, y);
	}

	points[n] = points[0];

	double sum = 0;
	for (int i = 1; i < n + 1; ++i) {
		sum += (points[i].first - points[i - 1].first) * (points[i].second + points[i - 1].second);
	}

	cout << fixed;
	cout.precision(25);
	cout << abs(0.5 * sum);

	return 0;
}