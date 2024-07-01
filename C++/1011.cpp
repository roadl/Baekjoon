#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void solve(vector<int> vec)
{
	int distance = vec[1] - vec[0];
	int i;

	int root = sqrt(distance);
	if (distance == pow(root, 2))
		cout << root * 2 - 1 << endl;
	else if (distance <= pow(root, 2) + root)
		cout << root * 2 << endl;
	else
		cout << root * 2 + 1 << endl;
}

int main()
{
	int testNum;
	vector<int> vec;

	cin >> testNum;

	while (testNum--)
	{
		for (int i = 0; i < 2; i++)
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