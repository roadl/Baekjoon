#include <iostream>

using namespace std;

int plus123(int n)
{
	if (n == 1)
		return 1; //1
	else if (n == 2)
		return 2; //2, 1 + 1
	else if (n == 3)
		return 4; //3, 2 + 1, 1 + 2, 1 + 1 + 1
	else
		return plus123(n - 1) + plus123(n - 2) + plus123(n - 3);
}

int main()
{
	int n, input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << plus123(input) << endl;
	}

	return 0;
}