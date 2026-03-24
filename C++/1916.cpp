#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

int N, M;
int S, E;

vector<int> dis;
vector<int> flag;
vector<vector<pair<int, int>>> nodes;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	dis.resize(N + 1, INT32_MAX);
	flag.resize(N + 1, false);
	nodes.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int n1, n2, cost;

		cin >> n1 >> n2 >> cost;

		nodes[n1].push_back({n2, cost});
	}

	cin >> S >> E;

	dis[S] = 0;

	while (S != 0) {
		flag[S] = true;

		int a;

		for (int i = 0; i < nodes[S].size(); i++) {
			int next = nodes[S][i].first;
			int cost = nodes[S][i].second;

			dis[next] = min(dis[next], dis[S] + cost);
		} 

		S = 0;

		for (int i = 1; i <= N; i++)
			if (dis[i] < dis[S] && !flag[i])
				S = i;
	}

	cout << dis[E] << endl;

	return 0;
}