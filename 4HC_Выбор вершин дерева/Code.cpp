
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

vector<vector<int>> tree;
vector<vector<int>> dp;

void dfs(int v)
{
	dp[v][0] = 0;
	dp[v][1] = 1;
	for (int to = 0; to < tree[v].size(); to++)
	{
		dfs(tree[v][to]);
		dp[v][0] += max(dp[tree[v][to]][0], dp[tree[v][to]][1]);
		dp[v][1] += dp[tree[v][to]][0];
	}
}

int main()
{
	cin >> N;

	tree.assign(N + 1, *new vector<int>());

	dp.assign(N + 1, *new vector<int>(2));

	for (int i = 1; i <= N; i++)
	{
		int tmp;

		cin >> tmp;
		tree[tmp].push_back(i);
	}

	dfs(tree[0][0]);
	int RES = max(dp[tree[0][0]][0], dp[tree[0][0]][1]);
	cout << RES;



	return 0;
}

