#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void solve(vector<int> vec)
{
	double distance;
	int range;
	int r1, r2;

	r1 = vec[2] > vec[5] ? vec[2] : vec[5];
	r2 = vec[2] > vec[5] ? vec[5] : vec[2];

	distance = sqrt(pow(vec[0] - vec[3], 2) + pow(vec[1] - vec[4], 2));
	range = vec[2] + vec[5];

	if ((vec[0] != vec[3]) || (vec[1] != vec[4]))
	{
		if (distance >= r1)
		{
			if (distance < range)
				cout << "2" << endl;
			else if (distance == range)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else
		{
			if (distance + r2 == r1)
				cout << "1" << endl;
			else if (distance + r2 > r1)
				cout << "2" << endl;
			else
				cout << "0" << endl;
		}
	}
	else if (vec[2] == vec[5])
		cout << "-1" << endl;
	else
		cout << "0" << endl;
}

int main()
{
	int testNum;
	vector<int> vec;

	cin >> testNum;

	while (testNum--)
	{
		int n;

		n = 6;

		for (int i = 0; i < n; i++)
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