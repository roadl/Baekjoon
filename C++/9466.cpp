#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T, N, cnt;

vector<int> students(100001);
vector<int> counts(100001, 0);
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T) {
		int cnt = 0;

		cin >> N;

		fill(counts.begin(), counts.end(), 0);

		for (int i = 1; i <= N; i++) {
			cin >> students[i];
			counts[students[i]]++;
		}

		for (int i = 1; i <= N; i++)
			if (counts[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int n = q.front();

			cnt++;

			if (--counts[students[n]] == 0)
				q.push(students[n]);
		
			q.pop();
		}

		cout << cnt << endl;

		T--;
	}

	return 0;
}