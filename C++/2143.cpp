#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int T, N, M;
map<int, int> map_a;
map<int, int> map_b;
vector<int> vec;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	cin >> N;

	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += vec[j];
			map_a[sum]++;
		}
	}

	cin >> N;

	vec.clear();
	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += vec[j];
			map_b[sum]++;
		}
	}
	
	ll res = 0;

	for (auto iter: map_a)
		res += (ll)iter.second * map_b[T - iter.first]; 

	cout << res << '\n';

	return 0;
}