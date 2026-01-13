#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int> > vec;
vector<pair<int, int> > input;
/*
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 
마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

1. 우선순위 만들어서 정렬
	- input1, input2로 받음
	- input2의 우선순위가 input1의 우선순위보다 작거나 같으면 1 크게 만들어줌
	- 4,5 3,4 로 들어왔을때 4, 5의 우선순위가 2로 같아지는 문제 발생

1-1. 1의 과정을 변화가 없을때까지 실행
	- 비효율적임
	- 백준 문제는 통과함

2. 위상정렬
	- 안해봄, 해봐야 함
*/

void solve(int N, int M)
{
	int input1, input2;
	bool flag = true;

	while (flag)
	{
		flag = false;

		for (int i = 0; i < M; i++)
		{
			input1 = input[i].first;
			input2 = input[i].second;

			if (vec[input2].second <= vec[input1].second)
			{
				vec[input2].second = vec[input1].second + 1;
				flag = true;
			}
		}
	}

	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){
    	return a.second < b.second;
	});

	for (int i = 0; i < N; i++)
		cout << vec[i].first << " ";

	cout << endl;

	// for (int i = 0; i < N; i++)
	// 	cout << vec[i].second << " ";

	// cout << endl;
}

int main()
{
	int N, M;
	int input1, input2;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		vec.push_back({i + 1, 0});

	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;

		input1--;
		input2--;

		input.push_back({input1, input2});
	}

	solve(N, M);
	
	return 0;
}