#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int C, N;
vector<pair<int, int> > vec;
int dp[2000];

/*
dp, 각 물품을 담냐 안담냐 해서 dp[C]의 최소값을 구한다
	- dp[0] = 0
	- for i = 0 ~ C
		for j = 0 ~ N - 1
			vec[i + vec[j.second]] = min(cur, next);
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> C >> N;

	fill_n(dp, 2000, -1);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		int t1, t2;
		
		cin >> t1 >> t2;
		vec.push_back({t1, t2});
	}

	int max_idx = 0;

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < N; j++) {
			int next_idx = i + vec[j].second;
			int next_value = dp[i] + vec[j].first;
			if (dp[i] == -1)
				continue;
			if (dp[next_idx] == -1)
				dp[next_idx] = dp[i] + vec[j].first;
			else
				dp[next_idx] = min(dp[next_idx], next_value);

			max_idx = max(max_idx, next_idx);
		}
	}

	int res = INT32_MAX;

	for (int i = C; i <= max_idx; i++) {
		if (dp[i] == -1)
			continue;
		res = min(res, dp[i]);
	}

	cout << res << "\n";
}