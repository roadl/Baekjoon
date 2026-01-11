#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 1. 방문하면서 ++시켜서 확인
// 비 효율적임 코테면 이렇게 풀수도? 2^15면 1024 * 32 = 3만언저리 시간 통과 가능
// 2. 규칙 찾아서 계산
// 칸 방문 순서는 정해져잇음
// 칸을 1/4 씩 나눠서 확인하기

void solve(int N, int r, int c)
{
	int t = pow(2, N - 1);
	int ans = 0;

	while (N > 0)
	{
		if (c >= pow(2, N - 1))
		{
			c -= pow(2, N - 1);
			ans += 1 * pow(4, N - 1);
		}
		if (r >= pow(2, N - 1))
		{
			r -= pow(2, N - 1);
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