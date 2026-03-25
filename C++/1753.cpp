#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

int N, M;
int S;

vector<int> dis;
vector<int> flag;
vector<vector<pair<int, int>>> nodes;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	cin >> S;

	dis.resize(N + 1, INT32_MAX);
	flag.resize(N + 1, false);
	nodes.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int n1, n2, cost;

		cin >> n1 >> n2 >> cost;

		nodes[n1].push_back({n2, cost});
	}

	dis[S] = 0;

	pq.push({0, S});

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > dis[now]) continue;

		for (auto &next: nodes[now]) {
			int nxt = next.first;
			int cost = next.second;

			if (dis[nxt] > dist + cost) {
				dis[nxt] = dist + cost;
				pq.push({dis[nxt], nxt});
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dis[i] != INT32_MAX)
			cout << dis[i] << '\n';
		else
			cout << "INF" << '\n';
	}

	return 0;
}