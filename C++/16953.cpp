#include <iostream>
#include <vector>

using namespace std;

unsigned long long A, B;

void recur(unsigned long long A, int depth)
{
	// cout << "A: " << A << ", depth: " << depth << endl;
	if (A == B)
	{
		cout << depth << endl;
		exit(0);
	}
	if (A > B)
		return;
	recur(A * 2, depth + 1);
	recur(A * 10 + 1, depth + 1);
}

int main()
{
	cin >> A >> B;

	recur(A, 1);

	cout << -1 << endl;

	return 0;
}