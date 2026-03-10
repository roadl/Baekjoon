#include <iostream>
#include <vector>

using namespace std;

vector<string> map(9);

void backtracking(int x, int y)
{
	if (x == 9) {
		if (y == 8) {
			for (int i = 0; i < 9; i++)
				cout << map[i] << endl;
			exit(0);
		}
			
		x = 0;
		y++;
	}

	if (map[y][x] != '0') {
		backtracking(x + 1, y);
		return ;
	}

	bool flag[10];

	for (int i = 0; i < 10; i++)
		flag[i] = true;

	for (int i = 0; i < 9; i++) {
		flag[map[y][i] - '0'] = false;
		flag[map[i][x] - '0'] = false;
		flag[map[(y / 3) * 3 + i / 3][(x / 3) * 3 + i % 3] - '0'] = false;
	}

	for (int i = 1; i < 10; i++) {
		if (flag[i]) {
			map[y][x] = i + '0';
			backtracking(x + 1, y);
			map[y][x] = '0';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
		cin >> map[i];

	backtracking(0, 0);

	return 0;
}