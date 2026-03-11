#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ll;

int N;
ll B, C;
int arr[3];
ll sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> B >> C;

	if (C >= B) {
		for (int i = 0; i < N; i++) {
			cin >> arr[0];
			sum += arr[0] * B;
		}
		cout << sum << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> arr[i % 3];

		if (i < 2) continue;
		
		int n1 = arr[(i - 2) % 3];
		int n2 = arr[(i - 1) % 3];
		int n3 = arr[i % 3];

		int m;

		if (n2 > n3) {
			m = n2 - n3;
			m = min(m, n1);

			n1 -= m; n2 -= m; sum += m * (B + C);
		}

		m = min(n1, n2);
		m = min(m, n3);

		n1 -= m, n2 -= m, n3 -= m, sum += m * (B + 2 * C);

		m = min(n1, n2);

		n1 -= m; n2 -= m, sum += m * (B + C);

		sum += n1 * B, n1 = 0;

		arr[(i - 1) % 3] = n2;
		arr[i % 3] = n3;
	}

	int n1 = arr[(N - 2) % 3], n2 = arr[(N - 1) % 3];

	int m = min(n1, n2);

	n1 -= m; n2 -= m, sum += m * (B + C);

	sum += (n1 + n2) * B;

	cout << sum << endl;

	return 0;
}