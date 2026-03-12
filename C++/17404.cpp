#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int N;
int dp[1000][3][3];
vector<int> R, G, B;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	R.resize(N);
	G.resize(N);
	B.resize(N);

	for (int i = 0; i < N; i++)
		cin >> R[i] >> G[i] >> B[i];

	// 첫번째 집 R
	dp[0][0][0] = R[0];
	dp[0][1][0] = 1001;
	dp[0][2][0] = 1001;

	// 첫번째 집 G
	dp[0][0][1] = 1001;
	dp[0][1][1] = G[0];
	dp[0][2][1] = 1001;

	// 첫번째 집 B
	dp[0][0][2] = 1001;
	dp[0][1][2] = 1001;
	dp[0][2][2] = B[0];

	for (int start = 0; start < 3; start++) {
		for (int i = 1; i < N; i++) {
			dp[i][0][start] = min(dp[i - 1][1][start] + R[i], dp[i - 1][2][start] + R[i]);
			dp[i][1][start] = min(dp[i - 1][0][start] + G[i], dp[i - 1][2][start] + G[i]);
			dp[i][2][start] = min(dp[i - 1][0][start] + B[i], dp[i - 1][1][start] + B[i]);
		}
	}

	int ans = 1e9;

	for (int start = 0; start < 3; start++) {
		for (int end = 0; end < 3; end++) {
			if (start == end) continue;
			ans = min(ans, dp[N - 1][end][start]);
		}
	}

	cout << ans << endl;

	return 0;
}