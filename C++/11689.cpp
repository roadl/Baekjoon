#include <iostream>
#include <vector>

using namespace std;

long long N;
long long res;
vector<long long> vec;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	res = N;

	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			vec.push_back(i);
			while (N % i == 0) N /= i;
		}
	}

	for (int i = 0; i < vec.size(); i++)
		res -= res / vec[i];

	if (N > 1)
		res -= res / N;

	cout << res << '\n';

	return 0;
}