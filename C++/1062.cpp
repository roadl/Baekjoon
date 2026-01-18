#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> input;
int N, K;
int max_word;

bool alpha[26];

/*
1. 브루트 포스
	- N <= 50, K <= 26, string length <= 15라 대충 갖다 붙여도 무조건 될듯
	- anta, tica가 반드시 포함되므로 string 앞뒤 4글자 제거하고 알파벳도 5개 제거하고 하기
*/

int cal_max()
{
	int cnt = 0;

	for (auto str: input)
	{
		if (str.size() == 0)
		{
			cnt++;
			continue;
		}
		for (int i = 0; i <= str.size(); i++)
		{
			if (!alpha[str[i] - 'a'])
				break;
			if (i == str.size() - 1)
				cnt++;
		}
	}

	return cnt;
}

void recur(int c, int depth)
{
	if (depth >= K)
	{
		int temp = cal_max();
		if (max_word < temp)
			max_word = temp;
		return;
	}
	for (int i = c; i < 26; i++)
	{
		if (alpha[i])
			continue;
	// printf("i: %d, c: %c, depth: %d, K: %d\n", i, i + 'a', depth, K);
		alpha[i] = true;
		recur(i + 1, depth + 1);
		alpha[i] = false;
	}
}

void solve()
{	
	if (K < 5)
	{
		cout << 0 << endl;
		return;
	}

	K -= 5;

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	recur(0, 0);

	cout << max_word << endl;

	// for (int i = 0; i < N; i++)
	// 	cout << input[i] << endl;
}

int main()
{

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		string temp;

		cin >> temp;

		input.push_back(temp.substr(4, temp.size() - 8));
	}

	for (int i = 0; i < 26; i++)
		alpha[i] = false;

	max_word = 0;

	solve();

	return 0;
}