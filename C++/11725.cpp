#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<vector<int>> tree;
vector<int> res;
queue<int> q;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	tree.resize(N + 1);
	res.resize(N + 1, 0);
	res[1] = 1;

	for (int i = 0; i < N - 1; i++) {
		int n1, n2;

		cin >> n1 >> n2;

		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	q.push(1);

	while (!q.empty()) {
		int n = q.front();

		for (int i = 0; i < tree[n].size(); i++) {
			if (res[tree[n][i]] != 0)
				continue;
			res[tree[n][i]] = n;
			q.push(tree[n][i]);
		}

		q.pop();
	}

	for (int i = 2; i <= N; i++)
		cout << res[i] << '\n';

	return 0;
}