#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int s, N, K, R1, R2, C1, C2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	if (s == 0) {
		cout << "0\n";
		return 0;
	}

	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			int y = i, x = j;
			int cell = 0;
			int _min, _max;
			int line = pow(N, s);
			int n = K * pow(N, s - 1);
			_min = (line - n) / 2.0;
			_max = (line + n) / 2.0;
			// printf ("(%d, %d), line:%d\n", y, x, line);
			while (line > 1) {
				if (y >= _min && y < _max && x >= _min && x < _max) {
					cell = 1;
					break;
				}
				line /= N;
				y %= line;
				x %= line;
				_min /= N; _max /= N;
			}
			cout << cell;
		}
		cout << "\n";
	}
}