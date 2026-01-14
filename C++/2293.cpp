#include <iostream>
#include <vector>

using namespace std;

/*
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

1. k에서 큰 가치의 동전부터 맞추서 빼고 k가 0이 되면 cnt++
	- 동전 sort
	- k에서 가장 큰 동전을 나눠 빼고 나머지 처리
	- k / max_value ~ 0까지 반복문 돌면서 아래 가치 처리
	- 느릴거 같은데

2. 동전의 가치를 만들 수 있는 경우의 수를 계산해서 저장, 이용한다
	- 1은 1 -> 1개
	- 2는 2 or 1 + 1 -> 2개
	- 5는 1 * 5 or 1 * 3 + 2 or 1 + 2 * 2 or 5 -> 4개
	- DP로 하면 될듯
*/

int n, k, cnt;
vector<int> vec;

void loop(int cur, int x, int depth)
{
	for (int i = x; i >= 0; i--)
	{
		for (int j = cur / vec[i]; j > 0; j--)
		{
			cur -= vec[i] * j;

			// for (int k = 0; k < depth; k++)
			// 	printf("  ");
			// printf("i: %d, j: %d, ?: %d\n", i, j, cur == 0);
			
			if (cur == 0)
			{
				cnt++;
				// printf("i: %d, j: %d, cur: %d, cnt: %d\n", 
				// i, j, cur + vec[i] * j, cnt);
			}
			else
				loop(cur, i - 1, depth + 1);

			cur += vec[i] * j;
		}
	}
}

void solve()
{
	int cur;
	cnt = 0;
	cur = k;
	
	loop(cur, n - 1, 0);
	
	cout << cnt << endl;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;

		vec.push_back(temp);
	}

	solve();
}