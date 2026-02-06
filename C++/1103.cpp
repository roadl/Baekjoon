#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;

vector<string> map;
bool visited[51][51] = {0};
int dp[51][51] = {-1};
int res = 0;

void recur(int x, int y, int cnt) {
	if (y < 0 || y >= N || x < 0 || x >= M ||
		map[y][x] == 'H') {
		if (res < cnt)
			res = cnt;
		return;
	}

	if (dp[y][x] >= cnt)
		return;

	if (visited[y][x]) {
		cout << "-1\n";
		exit(0);
	}

	dp[y][x] = cnt;

	visited[y][x] = true;

	int offset = map[y][x] - '0';

	recur(x + offset, y, cnt + 1);
	recur(x - offset, y, cnt + 1);
	recur(x, y + offset, cnt + 1);
	recur(x, y - offset, cnt + 1);

	visited[y][x] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		map.push_back(str);
	}

	recur(0, 0, 0);

	cout << res << "\n";
}