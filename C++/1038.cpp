#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> decresing_nums;

void add_num(long long n)
{
	// cout << "add " << n << endl;
	decresing_nums.push_back(n);

	for (int i = 0; i < (n % 10); i++)
	{
		add_num(n * 10 + i);
	}
}

void solve(int N)
{
	if (N >= 1023)
	{
		cout << "-1" << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
		add_num(i);

	sort(decresing_nums.begin(), decresing_nums.end());

	cout << decresing_nums[N] << endl;
}

int main()
{
	int N;

	cin >> N;

	// cout << is_decresing_num(9422) << endl;

	solve(N);

	return 0;
}