#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
1. 백트래킹 + 백트래킹
	- 0~9까지 숫자 중 K개 사용
	- digit, digit+1까지 숫자 넣어보고 제일 작은거로
	- 시간초과 될거 같은데 18자리 + 10개 조합?

2. N에서 증가시키기
	- 현재 N에서 몇개의 숫자를 쓰는지 확인
	- 다음 K개의 숫자를 쓰게 만들기

3. K, 자리수에 따라서 다른 로직 정용
	- K == digit -> 중복 숫자 나오면 증가시키고 9까지 중복이면 앞자리로 넘어가 체크

3.
*/

string input;
string str, str2, str3;
int K, digit, cur_K = 0;
unsigned long long N, res = 0;
int arr[10];

int cnt() {
	int res = 0;

	for (int i = 0; i < 10; i++)
		if (arr[i])
			res++;

	return res;
}

// 앞에서부터 K번째 다른 숫자 나올때까지 진행
// K+1 번째 다른 숫자 나오면 arr에서 true인 더 높은 숫자로 변경
// arr에서 더 높은 숫자 없으면 앞으로 돌아가서 ++시키기
// 한번 증가시켰으면 K만큼 안 썼으면 0부터 낮은거로 채우기
// K만큼 썼으면 arr에서 제일 낮은 숫자로 채우기
void solve(string str, bool flag)
{
	unsigned long long temp = 0;
	int j = 8;
	bool f1 = false, f2 = false;

	for (int i = 0; i < 10; i++)
		arr[i] = 0;

	// cout << "solve: " << str << endl;

	for (int i = 0; i < digit; i++) {
		if (f2)
			flag = true;
		if (f1)
			f2 = true;
		// printf("str[%d]: %c, arr[%c]: %d, flag:%d, cnt:%d\n", i, str[i], str[i], arr[str[i] - '0'], flag, cnt());

		if (flag)
			str[i] = '0';
		if (i == digit - (K - cnt()) && arr[str[i] - '0']) {
			// cout << "ASDF" << endl;
			// 남은 자릿수가 남은 K보다 작으면 이거 실행
			while (arr[str[i] - '0'] && str[i] <= '9')
				str[i]++;
			if (str[i] > '9') {
				str[i] = '0';
				i--;
				while (str[i] >= '9' || arr[str[i] - '0' + 1]) {
					arr[str[i] - '0']--;
					str[i] = '0';
					i--;
				}
				
				arr[str[i] - '0']--;
				str[i]++;
				// printf("str[%d]: %c, arr[%c]: %d, flag:%d, cnt:%d\n", i, str[i], str[i], arr[str[i] - '0'], flag, cnt());
				i--;
				f1 = true;
				f2 = false;
				continue;
			}
			arr[str[i] - '0']++;
			flag = true;
			continue;
		}
		if (flag && K == cnt()) {
			while (!arr[str[i] - '0'])
				str[i]++;
			arr[str[i] - '0']++;
			continue;
		}
		if (arr[str[i] - '0']) {
			arr[str[i] - '0']++;
			continue;
		}
		if (K == cnt()) {
			while (!arr[str[i] - '0'] && str[i] <= '9')
				str[i]++;
			if (str[i] > '9') {
				str[i] = '0';
				i--;
				arr[str[i] - '0']--;
				str[i]++;
				i--;
				f1 = true;
				f2 = false;
				continue;
			}
			flag = true;
			arr[str[i] - '0']++;
			continue;
		}
		arr[str[i] - '0']++;
	}

	cout << str << endl;
	exit(0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> str >> str2;

	for (auto c : str)
	{
		N *= 10;
		N += c - '0';
	}

	K = stoi(str2);

	digit = str.size();

	for (int i = 0; i < 10; i++)
		arr[i] = false;

	// cout << "K: " << K << ", digit: "
	// 	<< digit << ", N: " << N << "\n";

	if (K > digit)
	{
		res = 10;
		for (int i = 2; i < K; i++)
		{
			res *= 10;
			res += i;
		}

		cout << res << "\n";
	}
	else if (K == digit)
	{
		unsigned long long temp = 9;

		for (int i = 1; i < digit; i++)
		{
			temp *= 10;
			temp += 9 - i;
		}

		// cout << "temp: " << temp << "\n";

		// 987, 3 같은 경우 1002로
		if (N > temp)
		{
			if (digit == 1)
				res = 11;
			else
			{
				res = 100;

				for (int i = 2; i < digit; i++)
				{
					res *= 10;
					res += i;
				}
			}
			cout << res << "\n";
		}

		// 앞에서부터 체크하면서 동일한 숫자 나오면 ++시켜서 적용
		// 9를 썼는데 뒤에 9 또 나오면 앞자리++이 중복 아닐떄까지 되돌아가서 체크하기
		// 한번 증가됐으면 이후에는 아직 안 쓴 제일 낮은 숫자 적용
		else
		{
			bool flag = false;

			for (int i = 0; i < digit; i++)
			{
				// printf("str[%d]: %c, arr[%c]: %d, flag:%d, cnt:%d\n", i, str[i], str[i], arr[str[i] - '0'], flag, cnt());
				if (flag)
					str[i] = '0';
				if (arr[str[i] - '0']) {
					flag = true;
					while (arr[str[i] - '0'] && str[i] <= '9')
						str[i]++;
					if (str[i] > '9') {
						str[i] = '0';
						i--;
						while (str[i] == '9' || arr[str[i] - '0' + 1]) {
							arr[str[i] - '0']--;
							str[i] = '0';
							i--;
						}
						arr[str[i] - '0']--;
						str[i]++;
						arr[str[i] - '0']++;
						continue;
					}
				}
				arr[str[i] - '0']++;
			}

			cout << str << "\n";
		}
	}
	else
		solve(str, false);
}