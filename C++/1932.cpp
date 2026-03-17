#include <iostream>
#include <cmath>

using namespace std;

int N;

int dp[500][500] = {0};

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> dp[i][j];

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j <= i - 1; j++)
			dp[i - 1][j] += max(dp[i][j], dp[i][j + 1]);

	cout << dp[0][0] << '\n';

	return 0;
}