#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int cnt = 0;

vector<vector<int>> input;
vector<vector<int>> graph;
vector<int> res;
vector<int> counts;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	input.resize(M);

	for (int i = 0; i < M; i++) {
		int temp;

		cin >> temp;

		input[i].resize(temp);

		for (int j = 0; j < temp; j++)
			cin >> input[i][j];
	}

	graph.resize(N);
	counts.resize(N, 0);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < input[i].size() - 1; j++) {
			int cur = input[i][j] - 1, next = input[i][j + 1] - 1;
			graph[cur].push_back(next);
			counts[next]++;
		}
	}

	for (int i = 0; i < N; i++)
		if (counts[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int n = q.front();

		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i];
			counts[next]--;
			if (counts[next] == 0)
				q.push(next);
		}

		res.push_back(n + 1);
	
		q.pop();
	}

	if (res.size() != N) {
		cout << "0\n";
		return 0;
	}

	for (auto n: res)
		cout << n << endl;
	
	return 0;
}