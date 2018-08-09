
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

map<string, int> A;
map<string, int> B;


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

	int T;
	cin >> T;

	vector<string> RES = *new vector<string>();

	for (int test = 0; test < T; test++)
	{
		int N;

		cin >> N;

		n = 0; k = 0;

		A = *new map<string, int>();
		B = *new map<string, int>();

		g = *new vector < vector<int> >();

		for (int i = 0; i < N; i++)
		{
			string word_1;
			string word_2;

			cin >> word_1 >> word_2;

			if (A.find(word_1) == A.end())
			{
				A[word_1] = g.size();

				if (g.size() < A.size())
					g.push_back(*new vector<int>());


			}


			if (B.find(word_2) == B.end())
			{
				int tmp = B.size();
				B[word_2] = tmp;

			}

			g[A[word_1]].push_back(B[word_2]);

		}

		n = A.size();
		k = B.size();

		mt.assign(k, -1);
		for (int v = 0; v<n; ++v) {
			used.assign(n, false);
			try_kuhn(v);
		}

		int res = 0;

		for (int i = 0; i < k; ++i)
			if (mt[i] != -1)
				res += 1;

		int verticies_amount = A.size() + B.size();

		int original = verticies_amount - res;

		int ans = N - original;

		string ans_s = "Case #" + to_string(test + 1) + ": " + to_string(ans);

		RES.push_back(ans_s);
	}

	for (int i = 0; i<RES.size(); i++)
	{
		cout << RES[i] << endl;
	}



	return 0;
}
