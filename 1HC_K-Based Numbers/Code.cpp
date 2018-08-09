#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ui64;

struct _pair
{
	ui64 zero;
	ui64 digit;

	_pair(int a = 0, int b = 0)
	{
		zero = a;
		digit = b;
	}
};

vector<_pair> vec;

int main()
{
	int N, K;

	cin >> N;
	cin >> K;

	vec.push_back(_pair(0, K - 1));
	for (int i = 1; i < N; i++)
	{
		vec.push_back(_pair(
			vec.at(i - 1).digit,
			vec.at(i - 1).digit * (K - 1) + vec.at(i - 1).zero * (K - 1)
		));
	}

	cout << vec.at(vec.size() - 1).digit + vec.at(vec.size() - 1).zero;

	return 0;
}