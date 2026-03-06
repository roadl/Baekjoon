#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<string> map;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int sqr_max = 0;
	map.resize(N);

	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = sqr_max + 1; i + k < N && j + k < M; k++) {
				if (map[i][j] == map[i + k][j] && 
					map[i][j] == map[i][j + k] &&
					map[i][j] == map[i + k][j + k])
					sqr_max = k;
			}
		}
	}

	cout << (sqr_max + 1) * (sqr_max + 1) << endl;

	return 0;
}