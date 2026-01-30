#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> cranes;
vector<int> boxes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int t;

	for (int i = 0; i < N; i++) {
		cin >> t;
		cranes.push_back(t);
	}
	cranes.push_back(0);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> t;
		boxes.push_back(t);
	}

	sort(cranes.rbegin(), cranes.rend());
	sort(boxes.rbegin(), boxes.rend());

	if (cranes[0] < boxes[0]) {
		cout << "-1\n";
		return 0;
	}

	int max_cnt = 0;
	int cur_cnt = 0;
	int cur_crane = 0;

	for (int i = 0; i < M;) {
		if (boxes[i] <= cranes[cur_crane + 1]) {
			cur_crane++;
			i += cur_cnt;
			continue;
		}
		cur_cnt++;
		i += (cur_crane + 1);
	}

	cout << cur_cnt << "\n";
}