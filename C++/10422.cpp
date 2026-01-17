#include <iostream>
#include <vector>

using namespace std;

int T;

unsigned long long dp[5001];
unsigned long long mod = 1000000007;

int main()
{
	cin >> T;

	dp[0] = 1;

	for (int i = 2; i <= 5000; i += 2)
	{
		for (int j = 2; j <= i; j += 2)
		{
			dp[i] += dp[j - 2] * dp[i - j];
			dp[i] %= mod;
		}
	}


	for (int i = 0; i < T; i++)
	{
		int temp;
		
		cin >> temp;

		cout << dp[temp] << endl;
	}

	return 0;
}