#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 1. 방문하면서 ++시켜서 확인
// 2^15면 1024 * 32 = 3만언저리 시간 통과 가능
// 2. 규칙 찾아서 계산
// 칸 방문 순서는 정해져잇음
// 칸을 1/4 씩 나눠서 확인하기

void solve(int N, int r, int c)
{
	int half;
	int ans = 0;

	while (N > 0)
	{
		half = pow(2, N - 1);

		if (c >= half)
		{
			c -= half;
			ans += 1 * pow(4, N - 1);
		}

		if (r >= half)
		{
			r -= half;
			ans += 2 * pow(4, N - 1);
		}
		
		N--;
	}

	cout << ans << endl;
}

int main()
{
	int N, r, c;

	cin >> N >> r >> c;

	solve(N, r, c);

	return 0;
}