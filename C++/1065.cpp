#include <iostream>
#include <vector>

using namespace std;

bool isHansu(int n) {
	int common;
	vector<int> v;

	if (n < 100)
		return true;

	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	common = v[0] - v[1];

	for (int i = 1; i < v.size() - 1; i++) {
		if (common != v[i] - v[i + 1])
			return false;
	}

	return true;
}

int main()
{
	int n, cnt = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		if (isHansu(i))
			cnt++;

	cout << cnt << endl;

	return 0;
}