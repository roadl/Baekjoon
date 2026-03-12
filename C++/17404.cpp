#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int N;
unsigned int dp[1000][3][3];
int min_res;
int res;
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

	for (int i = 1; i < N; i++) {
		dp[i][0][0] = min(dp[i - 1][1][0] + R[i], dp[i - 1][2][0] + R[i]);
		dp[i][1][0] = min(dp[i - 1][0][0] + G[i], dp[i - 1][2][0] + G[i]);
		dp[i][2][0] = min(dp[i - 1][0][0] + B[i], dp[i - 1][1][0] + B[i]);

		dp[i][0][1] = min(dp[i - 1][1][1] + R[i], dp[i - 1][2][1] + R[i]);
		dp[i][1][1] = min(dp[i - 1][0][1] + G[i], dp[i - 1][2][1] + G[i]);
		dp[i][2][1] = min(dp[i - 1][0][1] + B[i], dp[i - 1][1][1] + B[i]);
		
		dp[i][0][2] = min(dp[i - 1][1][2] + R[i], dp[i - 1][2][2] + R[i]);
		dp[i][1][2] = min(dp[i - 1][0][2] + G[i], dp[i - 1][2][2] + G[i]);
		dp[i][2][2] = min(dp[i - 1][0][2] + B[i], dp[i - 1][1][2] + B[i]);
	}

	res = min(dp[N - 1][1][0], dp[N - 1][2][0]);
	min_res = min(dp[N - 1][0][1], dp[N - 1][2][1]);
	res = min(res, min_res);
	min_res = min(dp[N - 1][0][2], dp[N - 1][1][2]);
	res = min(res, min_res);

	cout << res << endl;

	return 0;
}