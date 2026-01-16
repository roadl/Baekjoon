#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

/*
1. 전체 칸을 돌면서 몇일 뒤에 녹는지 계산한다
	- 물에 인접한 곳은 1
	- 물에 인접하지 않으면 상하좌우 보고 제일 낮은 숫자 + 1
		- 변경시 상하좌우에 전파해야 함
			- 바로 전파 or 변경사항 없을때까지 전체 반복?
	- 백조끼리 만나는건 어떻게 계산?
		- 계산 후에 한쪽 백조로부터 가장 낮은 숫자로 갱신하면서 상하좌우 탐색

2. 각 L로부터 있는 .칸들 전부 큐에 넣고 두 큐에서 가장 가까운 거리 / 2 (반올림)
	- pruning?
*/

int R, C;

char map[1500][1500];
bool bitmap[1500][1500];

pair<int, int> L1, L2;

vector<pair<int, int> > L1_queue, L2_queue;

void recur(int y, int x, bool is_first)
{
	if (y < 0 || y >= R || x < 0 || x >= C ||
		bitmap[y][x] == true || (map[y][x] != '.' && map[y][x] != 'L'))
		return;

	// printf("(%d, %d)\n", y, x);
	
	if (is_first)
		L1_queue.push_back({y, x});
	else
		L2_queue.push_back({y, x});
	bitmap[y][x] = true;

	recur(y - 1, x, is_first);
	recur(y + 1, x, is_first);
	recur(y, x - 1, is_first);
	recur(y, x + 1, is_first);
}

void solve()
{
	recur(L1.first, L1.second, true);
	// printf("====\n");
	recur(L2.first, L2.second, false);

	int min = 3000;

	if (L2_queue.size() == 0)
	{
		cout << 0 << endl;
		return;
	}


	for (auto c1: L1_queue)
	{
		for (auto c2: L2_queue)
		{
			int distance = (abs(c1.first - c2.first) + abs(c1.second - c2.second)) / 2;

			// printf("dis: %d\n", distance);

			if (distance < min)
				min = distance;
		}
	}

	cout << min << endl;
}

int main()
{
	cin >> R >> C;

	int temp = 0;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			bitmap[i][j] = false;

			if (map[i][j] == 'L')
			{
				if (temp == 0)
				{
					L1.first = i;
					L1.second = j;
					temp++;
				}
				else
				{
					L2.first = i;
					L2.second = j;
				}
			}
		}
	
	solve();

	return 0;
}