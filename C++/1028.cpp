#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<string> map;
int dp[750][750][2];

void solve()
{
	int res = 0;

	for (int i = R - 1; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '0') {
				dp[i][j][0] = 0;
				dp[i][j][0] = 0;
				continue;
			}
			dp[i][j][0] = 1;
			dp[i][j][1] = 1;

			if (i + 1 < R && j - 1 >= 0)
				dp[i][j][0] += dp[i + 1][j - 1][0];
			if (i + 1 < R && j + 1 < C)
				dp[i][j][1] += dp[i + 1][j + 1][1];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '0')
				continue;

			int max = dp[i][j][0] < dp[i][j][1] ? dp[i][j][0] : dp[i][j][1];

			for (int k = max; k > res; k--) {
				int offset = k - 1;
				if (dp[i + offset][j + offset][0] >= k &&
					dp[i + offset][j - offset][1] >= k) {
					res = k;
					break;
				}
			}
		}
	}

	cout << res << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	string str;

	for (int i = 0; i < R; i++) {
		cin >> str;
		map.push_back(str);
	}

	solve();

	return 0;
}