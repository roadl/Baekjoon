#include <iostream>
#include <vector>
#include <string>

using namespace std;

int check(vector<string> vec, string s, int n)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (vec[i].compare(s) == 0)
			count++;
	}

	return count;
}

void solve(vector<string> vec, int n, int m, int k)
{
	vector<int> switch_on(m);

	int count, cur, max = 0;

	for (int i = 0; i < n; i++)
	{
		std::fill(switch_on.begin(), switch_on.end(), 0);
		count = 0;

		for (int j = 0; j < m; j++)
		{
			if (vec[i][j] == '0')
			{
				switch_on[j] = 1;
				count++;
			}
		}

		if (count <= k && (k - count) % 2 == 0)
		{
			cur = check(vec, vec[i], n);
			if (cur > max)
				max = cur;
		}

		//cout << i << ": " << count << " - " << cur << endl;
	}

	cout << max << endl;
}

int main()
{
	int n, m, k;

	cin >> n >> m;

	vector<string> vec;

	for (int i = 0; i < n; i++)
	{
		string s;

		cin >> s;

		vec.push_back(s);
	}

	cin >> k;

	// for (string s: vec)
	// {
	// 	cout << s << endl;
	// }

	// cout << k << endl;

	solve(vec, n, m, k);

	return 0;
}