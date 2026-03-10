#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int N;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	int left = 0, right = N - 1;
	int min = INT32_MAX;
	pair<int, int> res;

	while (left != right) {
		int sum = vec[left] + vec[right];
		int sum_abs = abs(sum);

		if (sum_abs < min) {
			res.first = left;
			res.second = right;
			min = sum_abs;
		}
		
		if (sum > 0)
			right--;
		else
			left++;
	}

	cout << vec[res.first] << " " << vec[res.second] << endl;

	return 0;
}