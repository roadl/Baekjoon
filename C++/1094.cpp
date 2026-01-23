#include <iostream>
#include <vector>

using namespace std;

int X;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> X;

	int n = 1, res = 0;

	while (n <= 64) {
		if (X &	n)
			res++;
		n = n << 1;
	}
	
	cout << res << endl;
}