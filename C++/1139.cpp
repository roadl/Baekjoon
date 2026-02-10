#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

vector<int> lens;
vector<double> dp;

double max_area = 0.0;

double cal_area(int A, int B, int C)
{
	double p = (A + B + C) / 2.0;

	return sqrt(p * (p - A) * (p - B) * (p - C));
}

bool is_valid(int A, int B, int C) {
	return A < B + C;
}

void solve()
{
	for (int mask = 0; mask < dp.size(); mask++) {
		if (dp[mask] == -1) continue;
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i)) continue;
			for (int j = i + 1; j < N; j++) {
				if (mask & (1 << j)) continue;
				for (int k = j + 1; k < N; k++) {
					if (mask & (1 << k)) continue;
					
					if (!is_valid(lens[i], lens[j], lens[k]))
						continue;
					
					int next_mask = mask | (1 << i) | (1 << j) | (1 << k);

					dp[next_mask] = max(dp[next_mask], dp[mask] + cal_area(lens[i], lens[j], lens[k]));
				}
			}
		}
	}

	for (double n: dp)
		max_area = max(max_area, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	lens.resize(N, 0);
	dp.resize(1 << N, -1.0);
	dp[0] = 0;

	for (int i = 0; i < N; i++)
		cin >> lens[i];

	sort(lens.rbegin(), lens.rend());

	solve();

	cout << fixed;

	cout.precision(15);

	cout << max_area << "\n";
}