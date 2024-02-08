#include <iostream>

using namespace std;

int	zero;
int	one;
int save[41][2];

int fibonacci(int n) {
	int result;

    if (n == 0) {
        zero++;
        return 0;
    } else if (n == 1) {
		one++;
        return 1;
    } else if (save[n][0] != -1)
	{
		zero += save[n][0];
		one += save[n][1];
		return save[n][1];
	} else {
		result = fibonacci(n - 1) + fibonacci(n - 2);
		save[n][0] = zero;
		save[n][1] = one;
        return result;
    }
}

void solve(int n)
{
	fibonacci(n);

	cout << save[n][0] << " " << save[n][1] << endl;
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int i = 2; i < 41; i++)
	{
		save[i][0] = -1;
		save[i][1] = -1;
	}

	save[0][0] = 1;
	save[0][1] = 0;
	
	save[1][0] = 0;
	save[1][1] = 1;

	while (testNum--)
	{
		int n;

		cin >> n;

		solve(n);

		zero = 0;
		one = 0;
	}

	return 0;
}