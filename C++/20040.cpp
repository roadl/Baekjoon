#include <iostream>
#include <vector>

using namespace std;

int N, M;
int id = 0;
int res = 0;

vector<int> nodes;

int find(int n) 
{
	if (nodes[n] != n)
		nodes[n] = find(nodes[n]);
	return nodes[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		nodes.push_back(i);

	for (int i = 0; i < M; i++) {
		int n1, n2;

		cin >> n1 >> n2;

		if (res != 0)
			continue;

		int r1 = find(n1);
		int r2 = find(n2);

		if (r1 == r2)
			res = i + 1;
		else
			nodes[r1] = r2;
	}
	
	cout << res << endl;

	return 0;
}