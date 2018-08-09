#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > zFunction(int n, string s) {
	int l = -1, r = -1;
	vector <int > z(s.size(), 0);
	for (int i = 1; i < n; i++) {
		int k = 0;
		if (r >= i)
			k = min(z[i - l], r - i);
		while (i + k < n && s[i + k] == s[k])
			k++;
		z[i] = k;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

int main()
{
	string s = "";

	cin >> s;

	vector<int> Z = zFunction(s.size(), s);

	for (int i = 0; i < Z.size(); i++)
	{
		cout << Z[i] << " ";
	}

	return 0;
}