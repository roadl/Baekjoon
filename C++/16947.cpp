#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node {
	int num;
	int distance = -1;
	vector<struct node*> list;
} Node;
	
int N;	
vector<pair<int, int> > route;
vector<Node> nodes;
vector<int> visited;
queue<int> q;

int get_index(int num)
{
	for (int i = 0; i < N; i++)
		if (num == nodes[i].num)
			return i;
	return 0;
}

int bfs(int num, Node* node)
{
	while (!q.empty()) {
		int n = q.front();

		cout << num << "->" << n;

		q.pop();

		if (find(visited.begin(), visited.end(), n) != visited.end()) {
			return num;
		}
		else {
			for (auto temp: nodes[n - 1].list)
				q.push(temp->num);
		}
	}
}

// 자신이 순환선인지 확인
bool search(int start)
{
	Node* node = &nodes[start];

	if (node->distance == 0)
		return true;

	q = queue<int>();
	visited.clear();

	for (int i = 0; i < N; i++) {

	}
	
	for (auto n: node->list) {
		q.push(n->num);
		visited.push_back(n->num);
	}

	bfs(start, node);

	return false;
}

void solve()
{
	for (int i = 1; i <= N; i++) {
		Node n;

		n.num = i;
		n.list.clear();

		nodes.push_back(n);
	}

	for (auto r: route) {
		nodes[r.first - 1].list.push_back(&nodes[r.second - 1]);
		nodes[r.second - 1].list.push_back(&nodes[r.first - 1]);
	}

	for (auto n: nodes) {
		cout << "---" << n.num << "---" << endl;
		for (auto l: n.list) {
			cout << l->num << endl;
		}
	}
}

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t1, t2;

		cin >> t1;
		cin >> t2;

		route.emplace_back(t1, t2);
	}

	solve();

	return 1;
}