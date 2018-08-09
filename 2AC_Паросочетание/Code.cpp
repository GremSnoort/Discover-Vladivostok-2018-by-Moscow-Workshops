#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

struct t_data
{
	int a;
	int b;

	t_data(int x = 0, int y = 0)
	{
		a = x;
		b = y;
	}
};

bool try_kuhn(int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {

	cin >> n >> k;

	cin.ignore(7777, '\n');

	for (int i = 0; i < n; i++)
	{
		g.push_back(*new vector<int>());

		while (true)
		{
			int tmp;

			cin >> tmp;

			if (tmp == 0)
				break;

			g[i].push_back(tmp - 1);
		}
	}

	mt.assign(k, -1);
	for (int v = 0; v<n; ++v) {
		used.assign(n, false);
		try_kuhn(v);
	}

	vector<t_data> RES;

	for (int i = 0; i < k; ++i)
		if (mt[i] != -1)
			RES.push_back(t_data(mt[i] + 1, i + 1));

	cout << RES.size() << endl;

	for (int i = 0; i < RES.size(); i++)
	{
		cout << RES[i].a << " " << RES[i].b << endl;
	}

	return 0;
}