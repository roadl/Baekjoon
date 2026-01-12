#include <iostream>
#include <vector>

using namespace std;

/* 
left = 0부터 더해서 sum이 S보다 커질때까지 right 증가, 길이 min에 저장
left 증가시켜서 반복, 반복시 이전 sum에서 vec[left]를 빼서 계산 최소화
min이 변하지 않았으면 0, 아님 min 출력
*/

void solve(vector<int> vec, int N, int S)
{
	int min = N + 1;
	int sum = 0, left = 0, right = 0;

	while (left < N) 
	{
		for (;sum < S && right < N; right++)
			sum += vec[right];

		if (sum >= S)
		{
			int cur = right - left;

			// cout << "sum: " << sum << ", cur: " << cur << endl;

			min = min > cur ? cur : min;
		}

		sum -= vec[left];

		left++;
	}

	cout << (min == N + 1 ? 0 : min) << endl;
}

int main()
{
	int N, S;
	vector<int> vec;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;

		vec.push_back(temp);
	}

	solve(vec, N, S);

	return 0;
}