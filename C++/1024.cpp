#include <iostream>
#include <vector>

/*
길이가 i일때
	- i가 홀수면 N / i가 x.0 형식이면 ok
	- i가 짝수면 N / i가 x.5 형식이면 ok
	
*/

using namespace std;

int N, L;

void check(int i) {
	int div = N / i;

	if (div + 1 < i / 2) {
		cout << "-1\n";
		exit(0);
	}

	if (i % 2 == 1 && div * i == N ||
			i % 2 == 0 && div * i + (i >> 1) == N) {
		div -= (i - 1) / 2;
		for (int j = 0; j < i; j++)
			cout << j + div << " ";
		exit(0);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;

	for (int i = L;i <= 100;i++)
		check(i);

	cout << "-1\n";

	return 0;
}