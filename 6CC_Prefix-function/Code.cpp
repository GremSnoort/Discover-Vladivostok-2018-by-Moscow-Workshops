#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > prefixFunction(string s)
{
	vector <int > p(s.size(), 0);

	for (int i = 1; i < s.size(); i++)
	{
		int k = p[i - 1];
		while (k > 0 && s[i] != s[k])
			k = p[k - 1];
		if (s[i] == s[k])
			k++;
		p[i] = k;
	}
	return p;
}

int main()
{
	string s = "";

	cin >> s;

	vector<int> P = prefixFunction(s);

	for (int i = 0; i < P.size(); i++)
	{
		cout << P[i] << " ";
	}

	return 0;
}