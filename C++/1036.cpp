#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<map<int, int> > diff_map(36);

// 각 숫자별 값을 계산할 벡터 자료형?
// unsigned long long으로 해도 부족할거 같은데
// int, int 형의 map으로 앞에는 1~35, 뒤에는 36진법의 digit으로?

int to_num(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
}

void cal_diff(char c, int digit)
{
	int n = to_num(c);

	cout << c << " " << digit << endl;

	diff_map[n][digit] += 35 - n;
}

void solve(vector<string> input, int K)
{	
	for (int i = 0; i < input.size(); i++) 
	{
		for (int j = 0; j < input[i].size(); j++) 
		{
			cal_diff(input[i][input[i].size() - j - 1], j);
		}
	}

	for (int i = 0; i < 36; i++)
	{
		cout << i << "--" << endl;
		for (auto m: diff_map[i]) 
		{
			if (m.second >= 36) {
				diff_map[i][m.first + 1] += m.second / 36;
				m.second %= 36;
			}
			cout << "key: " << m.first << ", value: " << m.second << endl;
		}
	}
}

int main()
{
	int N, K;

	vector<string> input;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		
		cin >> temp;

		input.push_back(temp);
	}

	cin >> K;

	solve(input, K);
}