#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> primes;

void get_prime(int n) {
	vector<bool> is_prime(n + 1, true);

	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i * i <= n; i++)
		if (is_prime[i])
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;

	for (int i = 2; i <= n; i++)
		if (is_prime[i])
			primes.push_back(i);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	get_prime(N);

	int left = 0, right = 0;
	int sum = 0;
	int res = 0;

	while (true) {
		if (sum == N)
			res++;
		if (sum >= N) {
			sum -= primes[left];
			left++;
		} else {
			if (right == primes.size())
				break;
			sum += primes[right];
			right++;
		}
	}

	cout << res << endl;

	return 0;
}