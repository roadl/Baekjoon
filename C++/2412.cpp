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

typedef struct node {
	int x;
	int y;
	int cnt = -1;
} Node;

int n, T;
vector<Node> vec;
queue<Node> cur_queue;
queue<Node> next_queue;

bool compare_node(Node n1, Node n2)
{
	if (n1.y > n2.y)
		return true;
	if (n1.y == n2.y && n1.x > n2.x)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> T;

	cur_queue.push({0, 0, 0});

	for (int i = 0; i < n; i++) {
		Node input;
	
		cin >> input.x >> input.y;

		vec.push_back(input);
	}

	sort(vec.begin(), vec.end(), compare_node);

	// for (auto v: vec)
	// 	cout << v.x << ", " << v.y << endl;

	while (true) {
		while (!cur_queue.empty()) {
			Node cur = cur_queue.front();

			cur_queue.pop();

			if (cur.y == T) {
				cout << cur.cnt << "\n";
				exit(0);
			}

			for (auto v: vec) {
				if (abs(v.x - cur.x) <= 2 && abs(v.y - cur.y) <= 2
					&& (v.cnt == -1 || v.cnt > cur.cnt + 1)) {
						v.cnt = cur.cnt + 1;
						next_queue.push(v);
					}
			}
		}

		cur_queue = next_queue;
		while (!next_queue.empty())
			next_queue.pop();
	}
}