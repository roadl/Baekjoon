#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
현재 위치 보고 뒤가 가까운지 앞이 가까운지 확인
돌리는데 드는 수 cnt에 더하고 큐 변경하고 다음 출력
큐 변경 어떻게?

N 50 M 50이라 어떻게 하든 될듯

size / 2에서 정수계산해서 시간 날림 ㅜ
*/

int N, M;
int cur = 1;
int cnt = 0;

vector<int> vec;

int cal_dis(int i)
{
	if (abs(cur - i) < vec.size() / 2.0)
		return abs(cur - i);
	return vec.size() - abs(cur - i);
}

void rotate_queue(int next) 
{
	auto iter = vec.begin();
	for (int i = 0; i < vec.size(); i++, iter++) {
		if (vec[i] == next) {
			cnt += cal_dis(i + 1);
			cur = i + 1;
			vec.erase(iter);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		vec.push_back(i + 1);

	for (int i = 0; i < M; i++) {
		int next;

		cin >> next;

		rotate_queue(next);
	}

	cout << cnt << "\n";
}