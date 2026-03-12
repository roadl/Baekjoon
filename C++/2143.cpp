#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int T, N, M;
map<ll, ll> map_a;
map<ll, ll> map_b;
vector<int> vec;

void top_down(ll sum, int left, int right, bool is_left_child, bool is_a)
{
	if (is_a)
		map_a[sum]++;
	else
		map_b[sum]++;

	if (left == right)
		return;

	if (is_left_child)
		top_down(sum - vec[right], left, right - 1, true, is_a);
	top_down(sum - vec[left], left + 1, right, false, is_a);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	cin >> N;

	ll sum = 0;

	for (int i = 0; i < N; i++) {
		int n;

		cin >> n;

		sum += n;
		vec.push_back(n);
	}

	top_down(sum, 0, N - 1, true, true);

	vec.clear();

	cin >> N;

	sum = 0;

	for (int i = 0; i < N; i++) {
		int n;

		cin >> n;

		sum += n;
		vec.push_back(n);
	}

	top_down(sum, 0, N - 1, true, false);

	ll res = 0;

	for (auto iter: map_a)
		res += iter.second * map_b[T - iter.first];

	cout << res << endl;

	return 0;
}