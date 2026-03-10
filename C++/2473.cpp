#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

int N;
int res[3];

vector<int> vec;

ll sum;
ll _min = LLONG_MAX;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - 2; i++) {
		int left = i + 1, right = N - 1;

		while (left < right) {
			sum = (ll)vec[i] + vec[left] + vec[right];
			ll sum_abs = abs(sum);

			if (sum_abs < _min) {
				res[0] = i;
				res[1] = left;
				res[2] = right;
				_min = sum_abs;
			}

			if (sum > 0)
				right--;
			else
				left++;
		}
	}

	cout << vec[res[0]] << " " << vec[res[1]] << " " << vec[res[2]] << endl;

	return 0;
}