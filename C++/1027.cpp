#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int cal_view_building(const int n, const vector<int> vec)
{
	// 기울기의 최대치를 구해서 그거보다 높으면 count++, 최대치 갱신
	// 아니면 패스

	double max_slope = numeric_limits<double>::lowest();
	int count = 0;
	
	// cout << "cal " << n << endl;

	// 앞쪽
	for (int i = n - 1; i >= 0; i--)
	{
		double cur_slope = (vec[i] - vec[n]) / double(n - i);
		if (cur_slope > max_slope)
		{
			max_slope = cur_slope;
			count++;
		}
		// cout << i << ": " << cur_slope << endl;
	}

	max_slope = numeric_limits<double>::lowest();
	// 뒤쪽
	for (int i = n + 1; i < vec.size(); i++)
	{
		double cur_slope = (vec[i] - vec[n]) / double(i - n);
		if (cur_slope > max_slope)
		{
			max_slope = cur_slope;
			count++;
		}
		// cout << i << ": " << cur_slope << endl;
	}

	return count;
}

void solve(const vector<int> vec)
{
	int max = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		int temp = cal_view_building(i, vec);
		if (temp > max)
			max = temp;
	}

	cout << max << endl;
}

int main()
{
	int n;

	vector<int> vec;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;

		cin >> input;

		vec.push_back(input);
	}

	solve(vec);

	vec.clear();

	return 0;
}