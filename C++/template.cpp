#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> vec)
{
	
}

int main()
{
	int testNum;
	vector<int> vec;

	cin >> testNum;

	while (testNum--)
	{
		int n;

		cin >> n;

		for (int i; i < n; i++)
		{
			int input;

			cin >> input;

			vec.push_back(input);
		}

		solve(vec);

		vec.clear();
	}

	return 0;
}