#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1. 각 정점에서 다른 정점으로 가는 길이 bfs 탐색
	- 무조건 인접 노드가 1개인 정점이 있나? 순환트리일수도 있음 아님
	- visited 쓰면서 거리 확인
	- 모든 노드에서 거리를 체크하면 timeout
		- 끝 노드에서 거리를 체크해야 함
		- 임의의 노드에서 거리를 체크했을떄 제일 먼 노드는 반드시 지름의 끝점
		- dfs 두번 실행
*/

int V;
unsigned long long max_dis = 0;
int max_node;
vector<vector<pair<int, unsigned long long>>> tree;
vector<bool> visited;

void dfs(int cur_node, unsigned long long cur_dis) {
	visited[cur_node] = true;

	for (auto n: tree[cur_node]) {
		if (!visited[n.first])
			dfs(n.first, cur_dis + n.second);
		else if (max_dis < cur_dis) {
			max_dis = cur_dis;
			max_node = cur_node;
		}
	}

	visited[cur_node] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V;
	tree.resize(V + 1);
	visited.resize(V + 1, false);

	while (V--) {
		int n;

		cin >> n;

		int u = 0;
		unsigned long long w = 0;
	
		while (true) {
			cin >> u;
			if (u == -1)
				break;
			cin >> w;

			tree[n].push_back({u, w});
		}
	}

	dfs(1, 0);
	dfs(max_node, 0);

	cout << max_dis << "\n";
}