#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

/*
1. Prim
	- 아무 노드나 선택, 트리에 포함되지 않은 가장 가중치가 작은 간선 선택
	- 반복
*/

int V, E;
int cnt;
long long dis = 0;

vector<priority_queue<pair<int, int>,
	vector<pair<int, int>>, greater<pair<int, int>>>> tree;
vector<bool> visited;

// 현재 visited에 있는 노드의 간선 확인
// 도착 노드도 visited에 포함 돼 있으면 삭제 제일 가중치가 낮은 엣지만 확인
// 가장 낮은 가중치끼리 비교해서 제일 낮은애로 선택, 연결

bool contain(int node) {
	if (find(visited.begin(), visited.end(), node) == visited.end())
		return false;
	return true;
}

void prim() {
	while (cnt != V) {
		int next_dis = INT32_MAX;
		int next_node = visited[0];

		for (int i = 1; i <= V; i++) {
			if (!visited[i])
				continue;
			auto &q = tree[i];
			while (!q.empty() && visited[q.top().second])
				q.pop();
			if (!q.empty() && q.top().first < next_dis) {
				next_dis = q.top().first;
				next_node = q.top().second;
			}
		}
		visited[next_node] = true;
		dis += next_dis;
		cnt++;
	}

	cout << dis << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	int n1, n2, n3;
	tree.resize(V + 1);
	visited.resize(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> n1 >> n2 >> n3;

		tree[n1].push({n3, n2});
		tree[n2].push({n3, n1});
	}

	for (int i = 0; i < V + 1; i++)
		visited[i] = false;

	visited[1] = true;
	cnt++;

	prim();

	return 0;
}