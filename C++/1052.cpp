#include <iostream>
#include <vector>

using namespace std;

/*
1. 비트로 풀기
	- K=1 N보다 큰 수가 나올때까지 2를 곱해준 다음 그 차이만큼 출력
	- K>1 면 N보다 큰 수가 나오기 전까지 2를 곱해줘서 빼고 K--하고 다시
	- 빼고 1보다 작으면 무조건 가능하므로 0 출력
*/

int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	while (true) {
		int t = 1;

		if (N <= 1) {
			cout << 0 << "\n";
			break;
		}

		while (t << 1 < N)
			t = t << 1;

		if (K == 1) {
			t = t << 1;
			cout << t - N << "\n";
			break;
		}

		N -= t;
		K--;
	}

	return 0;
}