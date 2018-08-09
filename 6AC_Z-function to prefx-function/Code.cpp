#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s = "";

vector<int> z;

vector<int> buildPrefixFunctionFromZFunction()
{
	vector<int> p = *new vector<int>(z.size());
	p.assign(z.size(), 0);
	for (int i = 1; i < z.size(); i++)
	{
		int t = z.size();
		for (int j = min(t - 1 - i, z[i] - 1); j >= 0; j--)
		{
			if (p[i + j] > 0)
				break;
			else
				p[i + j] = j + 1;

		}
	}
	return p;
}
int main()
{
	int N;

	cin >> N;

	z.assign(N, 0);

	cin.ignore(7777, '\n');

	for (int i = 0; i < N; i++)
	{
		cin >> z[i];
	}

	vector<int> ans = buildPrefixFunctionFromZFunction();

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}