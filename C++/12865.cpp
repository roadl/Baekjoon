#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
vector<int> dp;
vector<pair<int, int>> vec;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	dp.resize(K + 1);

	for (int i = 0; i < N; i++) {
		int weight, value;

		cin >> weight >> value;

		for (int j = K; j >= weight; j--)
			dp[j] = max(dp[j], dp[j - weight] + value);
	}

	cout << dp[K] << '\n';

	return 0;
}