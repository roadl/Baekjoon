#include <iostream>
#include <vector>

using namespace std;

int N;

int arr[1000001] = {0};
bool num[1000001] = {0};
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int input;

		cin >> input;

		num[input] = true;
		vec.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; vec[i] * j <= 1000000; j++) {
			if (!num[vec[i] * j]) continue;
			arr[vec[i]]++;
			arr[vec[i] * j]--;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[vec[i]] << " ";
	}

	return 0;
}