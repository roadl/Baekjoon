#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <math.h>

using namespace std;

vector<map<int, int> > diff_map(36);
list<int> max_diff;

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

char to_char(int n)
{
	if (n >= 0 && n <= 9)
		return n + '0';
	if (n >= 10 && n <= 35)
		return n - 10 + 'A';
}

void cal_diff(char c, int digit)
{
	int n = to_num(c);

	diff_map[n][digit] += 35 - n;
}

bool cal_greater(map<int, int> a, map<int, int> b)
{
	map<int, int>::reverse_iterator it_a = a.rbegin();
	map<int, int>::reverse_iterator it_b = b.rbegin();

	if (it_a == a.rend())
		return false;
	if (it_b == b.rend())
		return true;

	while (true)
	{
		if (it_a->first != it_b->first)
			return it_a->first > it_b->first;
		if (it_a->second != it_b->second)
			return it_a->second > it_b->second;
		it_a++;
		it_b++;

		if (it_b == b.rend())
			return true;
		if (it_a == a.rend())
			return false;
	}
}

bool in_max_K(int n, int K)
{
	int i = 0;
	for (auto it = max_diff.begin();
		it != max_diff.end() && i < K; it++, i++) {
			if (n == *it)
				return true;
	}
	return false;
}

void solve(vector<string> input, int K)
{
	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input[i].size(); j++)
			cal_diff(input[i][input[i].size() - j - 1], j);

	for (int i = 0; i < 36; i++) {
		// cout << to_char(i) << "--" << endl;

		for (auto m : diff_map[i]) {
			if (m.second >= 36) {
				diff_map[i][m.first + 1] += m.second / 36;
				diff_map[i][m.first] %= 36;
			}
			// cout << "key: " << m.first << ", value: " << diff_map[i][m.first] << endl;
		}
	}

	max_diff.insert(max_diff.begin(), 0);

	for (int i = 1; i < 36; i++)
	{
		// cout << i << "--" << endl;
		// for (auto it = diff_map[i].rbegin(); it != diff_map[i].rend(); ++it) {
		// 	cout << it->first << " : " << it->second << '\n';
		// }

		// cout << "check" << to_char(i) << endl;
		for (auto it = max_diff.begin(); it != max_diff.end(); it++)
		{
			// cout << to_char(*it) << ", " << to_char(i) << endl;
			if (cal_greater(diff_map[i], diff_map[*it]))
			{
				// cout << to_char(i) << " input" << endl;
				max_diff.insert(it, i);
				break;
			}
		}
	}

	// for (auto it: max_diff) {
	// 	cout << to_char(it) << endl;
	// }

	vector<int> result(54);

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			char c = input[i][input[i].size() - j - 1];
			int digit = j;

			if (in_max_K(to_num(c), K))
				result[j] += 35;
			else
				result[j] += to_num(c);
		}
	}

	for (int i = 0; i < 52; i++)
		if (result[i] >= 36) {
			result[i + 1] += result[i] / 36;
			result[i] %= 36;
		}

	int flag = false;
	
	for (int i = 52; i >= 0; i--)
	{
		if (result[i] == 0 && !flag && i != 0)
			continue;
		if (!flag && result[i] != 0)
			flag = true;
		cout << to_char(result[i]);
	}
	cout << endl;
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

		int t = temp.find_first_not_of('0');

		if (t == -1)
			t = temp.size() - 1;

		temp = temp.substr(t);

		input.push_back(temp);
	}

	cin >> K;

	solve(input, K);
}