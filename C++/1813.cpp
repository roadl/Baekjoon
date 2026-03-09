#include <iostream>
#include <map>

using namespace std;

int N;
map<int, int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		
		cin >> input;

		m[input]++;
	}

	for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
		if (iter->first == iter->second) {
			cout << iter->first << endl;
			return 0;
		}
		if (iter->first == 0) {
			cout << "-1\n";
			return 0;
		}
	}

	cout << "0\n";

	return 0;
}