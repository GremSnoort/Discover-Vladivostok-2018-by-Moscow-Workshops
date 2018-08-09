#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> winners1;
vector<int> winners2;

void set(int N, int player, int winner)
{
	if (player == 1) {
		winners1[N] = winner;
	}
	else {
		winners2[N] = winner;
	}
}

int get(int N, int player)
{
	if (player == 1) {
		return winners1[N];
	}
	else {
		return winners2[N];
	}
}

int rec(int N, int player)
{
	if (N == 3)
		return 3 - player;
	else if (N == 1 || N == 2)
		return player;

	int winner = get(N, player);

	if (winner > 0) {
		return winner;
	}

	if (N % 3 == 0)
	{
		int d1 = rec(N - 1, 3 - player);
		int d2 = rec(N - 2, 3 - player);

		if (d1 == player || d2 == player) {
			set(N, player, player);
			return player;
		}
		else {
			set(N, player, 3 - player);
			return 3 - player;
		}
	}
	else if (N % 3 == 1)
	{
		int d1 = rec(N - 1, 3 - player);
		int d3 = rec(N - 3, 3 - player);

		if (d1 == player || d3 == player) {
			set(N, player, player);
			return player;
		}
		else {
			set(N, player, 3 - player);
			return 3 - player;
		}
	}
	else if (N % 3 == 2)
	{
		int d1 = rec(N - 1, 3 - player);
		int d2 = rec(N - 2, 3 - player);
		int d3 = rec(N - 3, 3 - player);

		if (d1 == player || d2 == player || d3 == player) {
			set(N, player, player);
			return player;
		}
		else {
			set(N, player, 3 - player);
			return 3 - player;
		}
	}
}

int main()
{
	int N;

	cin >> N;
	winners1 = *new vector<int>(N + 1);
	for (int i = 0; i < winners1.size(); ++i) {
		winners1[i] = 0;
	}

	winners2 = *new vector<int>(N + 1);

	for (int i = 0; i < winners2.size(); ++i) {
		winners2[i] = 0;
	}

	cout << rec(N, 1);

	return 0;
}