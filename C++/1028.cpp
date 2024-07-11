#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int r, c;

int **map;

int cal_possible_max(int i, int j)
{
	if (map[i][j] == 0)
		return 0;

	int right = c - j - 1;

	int hor = i / 2 + 1;
	int ver = (j < right ? j : right) + 1;
	
	return (hor < ver ? hor : ver);
}

bool check_dia(int i, int j, int expect)
{
	int k;
	int n = expect * 2 - 2;

	//cout << "check " << i << ", " << j << endl;

	for (int k = 1; k <= expect - 1; k++)
	{
		//cout << "[" << i -k << "]" << "[" << j - k << "], [" << i - k << "]"  << "[" << j + k << "]" << endl;
		if (!(map[i - k][j - k] == 1 && map[i - k][j + k] == 1))
			return false;
	}
	for (k --; k >= 0; k--) 
	{
		//cout << "[" << i - n + k << "]" << "[" << j - k << "], [" << i - n + k << "]"  << "[" << j + k << "]" << endl;
		if (!(map[i - n + k][j - k] == 1 && map[i - n + k][j + k] == 1))
			return false;
	}
	return true;
}

int check_max_dia(int i, int j, int max)
{
	int possible_max;

	possible_max = cal_possible_max(i, j);

	if (map[i][j] == 0)
		return 0;

	for (int a = possible_max; a > 1; a--)
	{
		if (a <= max)
			return 0;
		if (check_dia(i, j, a))
			return a;
	}
	
	return 1;
}

void solve()
{
	int max = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cur;

			cur = check_max_dia(i, j, max);
			//cout << cur << " ";
			if (cur > max)
				max = cur;
		}
		//cout << endl;
	}
	cout << max << endl;
}

int main()
{
	cin >> r;
	cin >> c;

	map = (int **)malloc(sizeof(int *) * r);
	for (int i = 0; i < r; i++)
	{
		map[i] = (int *)malloc(sizeof(int) * c);

		string str;

		cin >> str;

		for (int j = 0; j < str.length(); j++)
			map[i][j] = str[j] - '0';
	}

	// for (int i = 0; i < r; i++)
	// {
	// 	for (int j = 0; j < c; j++)
	// 	{
	// 		//solve_map[i][j] = 0;
	// 		cout << map[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	solve();

	return 0;
}