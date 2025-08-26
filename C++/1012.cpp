#include <iostream>
#include <vector>

int m, n;

using namespace std;

void search_and_change(vector<vector<int> >& vec, int y, int x)
{
	if (y < 0 || x < 0 || y >= n || x >= m || vec[y][x] == 0)
		return ;
	vec[y][x] = 0;
	search_and_change(vec, y + 1, x);
	search_and_change(vec, y - 1, x);
	search_and_change(vec, y, x + 1);
	search_and_change(vec, y, x - 1);
}

void solve(vector<vector<int> > vec)
{
	int count = 0;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == 1)
			{
				search_and_change(vec, i, j);
				count++;
			}
		}
	}

	cout << count << endl;
}

int main()
{
	int testNum;
	vector<int> vec;

	cin >> testNum;

	while (testNum--)
	{
		int k;

		cin >> m >> n >> k;

		vector<vector<int> > arr(n, vector<int>(m));

		for (int i = 0; i < k; i++)
		{
			int x, y;

			cin >> x >> y;

			arr[y][x] = 1;
		}

		// for (vector<int> v: arr) {
		// 	for (int n: v) {
		// 		cout << n << " ";
		// 	}
		// 	cout << endl;
		// }

		solve(arr);

		arr.clear();
	}

	return 0;
}