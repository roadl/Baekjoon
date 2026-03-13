#include <iostream>
#include <vector>

using namespace std;

int N, M;
int S, E;

vector<int> vec;

bool dp[2001][2001];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];
	
	for (int i = 0; i < N; i++)
		dp[i][i] = true;

	for (int i = 0; i < N - 1; i++)
		if (vec[i] == vec[i + 1])
			dp[i][i + 1] = true;

	for (int len = 3; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len - 1;
			if (vec[i] == vec[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}

	cin >> M;

	while (M--) {
		cin >> S >> E;

		cout << dp[S - 1][E - 1] << '\n';
	}

	return 0;
}