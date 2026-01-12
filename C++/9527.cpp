#include <iostream>
#include <vector>

using namespace std;

/*
두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해
x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오

1. 각 수에 대해 2로 나누면서 구한다
- 10^16까지라 될리가 있나

2. 구간별로 나누기?

3. 전 숫자에 비해 어떻게 변하는지 확인하기?
- 맨 마지막이 0->1이면 1개 증가
- 1->0이면 어디까지 같은지 &로 확인
- 했는데 느림 안됨

4. 자리별로 확인
- 1의 자리는 0 1 반복
- 2의 자리는 0 0 1 1 반복 이후 같음
- A랑 B를 확인해서 각 자리별 몇개 나오는지 확인하고 더하기
	- 패턴이 몇번 반복되는지 확인하고 A, B가 속한 패턴은 따로 계산
	- 패턴은 B / t - A / t 만큼 반복
	- A랑 B랑 다른 패턴이면
		- (패턴 - 1) * t / 2 만큼 1
		- A에선 t / 2 - cnt_(a - 1) 만큼 1 나옴
		- B에선 cnt_b 만큼 1 나옴
	- A랑 B랑 같은 패턴이면 cnt_b - cnt_a + 1만큼 1 나옴

- 2시간 걸림, 아이디어 떠올리는데 30분, 구현에 1시간반
	- 다른 패턴일때 A 뒤에 있는걸 계산해야하는데 앞에 있는거로 계산함
	- A 개수 셀때 헷갈려서 시간 날림
*/

unsigned long long cal_1_cnt(unsigned long long t, long long cur)
{
	return (cur >= t / 2 ? cur - t / 2 + 1 : 0);
}

void solve(unsigned long long A, unsigned long long B)
{
	unsigned long long count = 0;
	unsigned long long t = 1;

	while (true)
	{
		t = t << 1;

		// 패턴의 개수
		long long pattern_cnt = B / t - A / t;

		// 현재 패턴에서 몇번째에 있는지
		long long cur_a = A % t;
		long long cur_b = B % t;

		// 패턴내에서 A 미포함 앞에 1이 몇개 있는지
		long long cnt_a = cal_1_cnt(t, (cur_a - 1 < 0 ? 0 : cur_a - 1));
		// 패턴내에서 B 포함 앞에 1이 몇개 있는지
		long long cnt_b = cal_1_cnt(t, cur_b);

		if (pattern_cnt == 0)
			count += cnt_b - cnt_a;

		else
			count += (pattern_cnt - 1) * t / 2 + (t / 2 - cnt_a) + cnt_b;

		if (t > B)
			break;
	}

	cout << count << endl;
}

int main()
{
	unsigned long long A, B;

	cin >> A >> B;
	
	solve(A, B);

	return 0;
}