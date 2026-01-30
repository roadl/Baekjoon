#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> cranes;
vector<int> boxes;
vector<bool> check;

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

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> t;
		boxes.push_back(t);
		check.push_back(false);
	}

	sort(cranes.begin(), cranes.end());
	sort(boxes.begin(), boxes.end());

	if (cranes[N - 1] < boxes[M - 1]) {
		cout << "-1\n";
		return 0;
	}

	int step = 1;
	int count = 0;

	while (true) {
		for (int i = cranes.size() - 1; i >= 0; i--) {
			for (int j = boxes.size() - 1; j >= 0; j--) {
				if (check[j] || boxes[j] > cranes[i])
					continue;
				check[j] = true;
				count++;
				break;
			}
		}

		if (count == M)
			break;

		step++;
	}

	cout << step << "\n";
}