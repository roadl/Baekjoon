#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
size_t max_f = 0;

vector<vector<int> > vec;

void solve()
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vec.resize(N);

	char c;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;

			if (c == 'Y')
				vec[i].push_back(j);
		}
	}
	
	for (int i = 0; i < N; i++) {
		vector<int> friends;

		friends = vec[i];

		for (int j: vec[i]) {
			for (int k: vec[j]) {
				if (find(friends.begin(), friends.end(), k) == friends.end()
						&& k != i) {
					friends.push_back(k);
				}
			}
		}

		max_f = max(max_f, friends.size());
	}

	cout << max_f << "\n";
}