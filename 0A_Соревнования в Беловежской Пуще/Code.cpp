#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

	int N, M, K;

	cin >> N >> M >> K;

	int FreePeoples = N + M - K;
	int PossibleAmountOfTeams = int(FreePeoples / 3);

	int Z;

	if (N<int(M / 2))
		Z = N;
	else
		Z = int(M / 2);

	int ANS;

	if (Z < PossibleAmountOfTeams)
		ANS = Z;
	else
		Z = PossibleAmountOfTeams;


	if (Z < 0)
		cout << 0;
	else
		cout << Z;


	return 0;
}