#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[3];
unsigned long long sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

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

			n1 -= m; n2 -= m; sum += m * 5;
		}

		m = min(n1, n2);
		m = min(m, n3);

		n1 -= m, n2 -= m, n3 -= m, sum += m * 7;

		m = min(n1, n2);

		n1 -= m; n2 -= m, sum += m * 5;

		sum += n1 * 3, n1 = 0;

		arr[(i - 1) % 3] = n2;
		arr[i % 3] = n3;
	}

	int n1 = arr[(N - 2) % 3], n2 = arr[(N - 1) % 3];

	int m = min(n1, n2);

	n1 -= m; n2 -= m, sum += m * 5;

	sum += n1 * 3 + n2 * 3;

	cout << sum << endl;

	return 0;
}