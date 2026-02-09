#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int r1, c1, r2, c2;

int cal_val(int r, int c) {
	int k = max(abs(r), abs(c));
	int max_val = pow((2 * k + 1), 2);

	if (r == k)
		return max_val - (k - c);
	if (c == -k)
		return max_val - (2 * k) - (k - r);
	if (r == -k)
		return max_val - (4 * k) - (c + k);
	return max_val - (6 * k) - (r + k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;

	int max_val = 0;
	for (int i = r1; i <= r2; i++)
    	for (int j = c1; j <= c2; j++)
        	max_val = max(max_val, cal_val(i, j));

	int width = to_string(max_val).length();

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			printf("%*d ", width, cal_val(i, j));
		}
		printf("\n");
	}
}