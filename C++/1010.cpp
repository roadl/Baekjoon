#include <iostream>
#include <vector>

using namespace std;

int T, N, K;

unsigned long long dp[31][31]= {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 31; i++)
		dp[0][i] = 1;

	for (int i = 1; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			for (int k = i - 1; k < j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	cin >> T;

	while (T--) {
		cin >> N >> K;

		cout << dp[N][K] << endl;
	}
}