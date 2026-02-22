#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, C;

vector<int> vec;

bool check_d(int d)
{
	int cur = vec[0];
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (vec[i] - cur >= d) {
			cnt++;
			cur = vec[i];
			if (cnt == C)
				return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> C;

	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int lo = 1, hi = vec[N - 1] - vec[0];
	int res = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (check_d(mid)) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	cout << res << "\n";
}