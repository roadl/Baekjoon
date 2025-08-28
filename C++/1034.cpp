#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<string> vec, int n, int m, int k)
{
	
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

	for (string s: vec)
	{
		cout << s << endl;
	}

	cout << k << endl;

	solve(vec, n, m, k);

	return 0;
}