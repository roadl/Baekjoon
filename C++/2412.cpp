#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/*
1. a* 탐색
	- y좌표 먼저, x좌표 기준으로 정렬
	- 갈 수 있는 노드를 추가, visit 벡터 만들어서 체크
	- 딴 곳에서 더 적게 갈 수 있으면 숫자 초기화
	- 컨테이너 어떤거로?
	- 이동 횟수가 제일 적은거별로 queue에 담아놓고 다음에 빼서 쓰기
*/

typedef struct node
{
	int x;
	int y;
	int cnt = -1;
} Node;

int n, T;
// y, x, cnt
map<int, vector<int>> m;
queue<Node> cur_queue;

bool compare_first(const pair<const int, int> &p, int value)
{
	return p.first < value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> T;

	cur_queue.push({0, 0, 0});

	while (n--)
	{
		int x, y;

		cin >> x >> y;

		m[y].push_back(x);
	}

	for (auto &p : m)
		sort(p.second.begin(), p.second.end());

	while (!cur_queue.empty())
	{
		Node cur = cur_queue.front();

		cur_queue.pop();

		if (cur.y == T)
		{
			cout << cur.cnt << "\n";
			exit(0);
		}

		for (int i = cur.y - 2; i <= cur.y + 2; i++)
		{
			auto it = m.find(i);
			if (it == m.end())
				continue;

			auto &v = it->second;

			auto lo = lower_bound(v.begin(), v.end(), cur.x - 2);
			auto hi = upper_bound(v.begin(), v.end(), cur.x + 2);

			for (auto iter = lo; iter != hi; iter++)
				cur_queue.push({*iter, i, cur.cnt + 1});

			v.erase(lo, hi);
		}
	}

	cout << "-1" << "\n";
}