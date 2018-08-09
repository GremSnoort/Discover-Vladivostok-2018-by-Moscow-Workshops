#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> Z;

vector<int> P;

void z_from_p()
{
	for (int i = 1; i < N; i++) // 1 этап.
		if (P[i])
			Z[i - P[i] + 1] = P[i];

	Z[0] = 0;

	if (Z[1]) // 2 этап.
		for (int i = 1; i < Z[1]; i++)
			Z[i + 1] = Z[1] - i;

	int t;
	for (int i = Z[1] + 1; i < N - 1; i++) // 3 этап.
	{
		t = i;
		if (Z[i] && !Z[i + 1])
			for (int j = 1; j < Z[i] && Z[i + j] <= Z[j]; j++)
			{
				Z[i + j] = min(Z[j], Z[i] - j);
				t = i + j;
			}
		i = t;
	}
}

int main()
{
	cin >> N;

	P.assign(N, 0);
	Z.assign(N, 0);

	cin.ignore(7777, '\n');

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}


	z_from_p();

	for (int i = 0; i < Z.size(); i++)
	{
		cout << Z[i] << " ";
	}

	return 0;
}