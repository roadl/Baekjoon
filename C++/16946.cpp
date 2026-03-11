#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, id;

vector<string> input_map;
queue<pair<int, int>> q;
pair<int, int> cnt_map[1000][1000];

void dfs(int y, int x)
{
	if (x < 0 || x >= M || y < 0 || y >= N ||
		input_map[y][x] != '0')
		return;

	q.push({y, x});
	input_map[y][x] = '2';
	dfs(y - 1, x);
	dfs(y + 1, x);
	dfs(y, x - 1);
	dfs(y, x + 1);
}

void cal_res(int y, int x, int* sum, vector<int>& ids)
{
	if (x < 0 || x >= M || y < 0 || y >= N ||
		input_map[y][x] == '1')
		return;
	
	int id = cnt_map[y][x].second;

	if (find(ids.begin(), ids.end(), id) != ids.end())
		return;
	
	ids.push_back(id);
	*sum += cnt_map[y][x].first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;

		input_map.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (input_map[i][j] == '0') {
				dfs(i, j);
				int cnt = q.size();
				while (!q.empty()) {
					pair<int, int> p = q.front();
					cnt_map[p.first][p.second].first = cnt;
					cnt_map[p.first][p.second].second = id;
					q.pop();
				}
				id++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (input_map[i][j] != '1') {
				cout << '0';
				continue;
			}

			int sum = 1;
			vector<int> ids;

			cal_res(i - 1, j, &sum, ids);
			cal_res(i + 1, j, &sum, ids);
			cal_res(i, j - 1, &sum, ids);
			cal_res(i, j + 1, &sum, ids);

			cout << sum % 10;
		}
		cout << endl;
	}

	return 0;
}