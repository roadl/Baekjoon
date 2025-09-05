#include <iostream>
#include <vector>

using namespace std;

int N;
int **map;
int **mark_map;

void mark(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N ||
		mark_map[x][y] != 0)
			return;

	mark_map[x][y] = 1;

	mark(x - 1, y);
	mark(x, y - 1);
	mark(x + 1, y);
	mark(x, y + 1);
}

int solve()
{
	int max = 1;
	int count;

	for (int k = 1; k < 100; k++) {
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] < k)
					mark_map[i][j] = 1;
				else
					mark_map[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mark_map[i][j] == 0) {
					mark(i, j);
					count++;
				}
			}
		}

		if (count > max)
			max = count;
	}
	return max;
}

int main()
{
	cin >> N;

	map = (int **)malloc((N + 1) * sizeof(int *));
	mark_map = (int **)malloc((N + 1) * sizeof(int *));

	for (int i = 0; i < N; i++) {
		map[i] = (int *)malloc((N + 1) * sizeof(int));
		mark_map[i] = (int *)malloc((N + 1) * sizeof(int));

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			mark_map[i][j] = 0;
		}
	}

	cout << solve() << endl;

	return 0;
}