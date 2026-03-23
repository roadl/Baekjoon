#include <iostream>
#include <cmath>

using namespace std;

int N;
int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 3; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		int R, G, B;

		cin >> R >> G >> B;

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
	}

	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << '\n';

	return 0;
}