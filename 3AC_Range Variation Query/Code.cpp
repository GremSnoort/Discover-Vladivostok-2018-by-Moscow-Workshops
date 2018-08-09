#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long* t_min;
long long* t_max;

int INTMAX = 2147483646;

long long* init_sequence(int length)
{
	long long* seq = new long long[length];

	for (long long i = 1; i <= length; ++i) {
		seq[i - 1] = i * i % 12345 + i * i * i % 23456;

		//cout << seq[i-1] << ' ';
	}
	//cout << endl;

	return seq;
}

void build_min_tree(long long a[], int v, int tl, int tr) {
	if (tl == tr)
		t_min[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build_min_tree(a, v * 2, tl, tm);
		build_min_tree(a, v * 2 + 1, tm + 1, tr);
		t_min[v] = min(t_min[v * 2], t_min[v * 2 + 1]);
	}
}

int minimum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return INTMAX;
	if (l == tl && r == tr)
		return t_min[v];
	int tm = (tl + tr) / 2;
	return min(minimum(v * 2, tl, tm, l, min(r, tm)), minimum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update_min(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t_min[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update_min(v * 2, tl, tm, pos, new_val);
		else
			update_min(v * 2 + 1, tm + 1, tr, pos, new_val);
		t_min[v] = min(t_min[v * 2], t_min[v * 2 + 1]);
	}
}

void build_max_tree(long long a[], int v, int tl, int tr) {
	if (tl == tr)
		t_max[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build_max_tree(a, v * 2, tl, tm);
		build_max_tree(a, v * 2 + 1, tm + 1, tr);
		t_max[v] = max(t_max[v * 2], t_max[v * 2 + 1]);
	}
}

int maximum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return -INTMAX;
	if (l == tl && r == tr)
		return t_max[v];
	int tm = (tl + tr) / 2;
	return max(maximum(v * 2, tl, tm, l, min(r, tm)), maximum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update_max(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t_max[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update_max(v * 2, tl, tm, pos, new_val);
		else
			update_max(v * 2 + 1, tm + 1, tr, pos, new_val);
		t_max[v] = max(t_max[v * 2], t_max[v * 2 + 1]);
	}
}

int main()
{
	int k;
	cin >> k;

	vector<pair<int, int>> queries = *new vector<pair<int, int>>();
	int max_index = 0;
	for (int i = 0; i < k; ++i)
	{
		int l, r;
		cin >> l >> r;
		if (l < 0) {
			if (abs(l) > max_index) {
				max_index = abs(l) - 1;
			}
			queries.push_back(*new pair<int, int>(l, r));
		}
		else {
			if (r > max_index) {
				max_index = r - 1;
			}
			queries.push_back(*new pair<int, int>(l - 1, r - 1));
		}
	}

	int length = max_index + 1;
	long long* seq = init_sequence(length);
	t_min = new long long[4 * length];
	for (int i = 0; i < 4 * length; ++i) {
		t_min[i] = INTMAX;
	}

	t_max = new long long[4 * length];

	for (int i = 0; i < 4 * length; ++i) {
		t_max[i] = -INTMAX;
	}

	build_min_tree(seq, 1, 0, length - 1);
	build_max_tree(seq, 1, 0, length - 1);

	vector<int> result = *new vector<int>();
	for (auto query : queries) {
		int l = query.first,
			r = query.second;

		if (l >= 0) {
			int interval_max = maximum(1, 0, max_index, max(l, 0), min(r, max_index)),
				interval_min = minimum(1, 0, max_index, max(l, 0), min(r, max_index));
			result.push_back(interval_max - interval_min);
		}
		else {
			update_min(1, 0, max_index, abs(l) - 1, r);
			update_max(1, 0, max_index, abs(l) - 1, r);
		}
	}

	for (int res : result) {
		cout << res << '\n';
	}

	return 0;
}
