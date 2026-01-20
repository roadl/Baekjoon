#include <iostream>
#include <vector>

using namespace std;

int N, a, b;

void solve(vector<int> vec)
{
	
}

int main()
{
	cin >> N >> a >> b;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int res = 1;

	while (true)
	{
		if (b % 2 == 0 && a == b - 1)
			break;

		a = (a + 1) / 2;
		b = (b + 1) / 2;
		res++;
	}

	cout << res << endl;
}