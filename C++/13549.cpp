#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, res = 100000;

void find(int n, int time)
{
	if (n <= N) {
		res = min(res, time + N - n);
		return;
	}
	
	if (n % 2 == 1) {
		find((n + 1) / 2, time + 1);
		find(n / 2, time + 1);
	} else find(n / 2, time);

	if (n / 2 < N)
		res = min(res, time + n - N);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	int next;

	if (K <= N) {
		cout << N - K << '\n';
		return 0;
	}

	if (N == 0) {
		N = 1;
		find (K, 1);
	} else find(K, 0);

	cout << res << endl;

	return 0;
}