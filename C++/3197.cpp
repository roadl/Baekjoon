#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1. 전체 칸을 돌면서 몇일 뒤에 녹는지 계산한다
	- 물에 인접한 곳은 1
	- 물에 인접하지 않으면 상하좌우 보고 제일 낮은 숫자 + 1
		- 변경시 상하좌우에 전파해야 함
			- 바로 전파 or 변경사항 없을때까지 전체 반복?
	- 백조끼리 만나는건 어떻게 계산?
		- 계산 후에 한쪽 백조로부터 가장 낮은 숫자로 갱신하면서 상하좌우 탐색
*/

int R, C, cnt;

char map[1500][1500];
bool bitmap[1500][1500];
bool bitmap_L[1500][1500];

queue<pair<int, int> > cur_map;
queue<pair<int, int> > next_map;
queue<pair<int, int> > cur_L;
queue<pair<int, int> > next_L;

int X1, X2, Y1, Y2;

void recur_L(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C || bitmap_L[y][x])
		return;

	bitmap_L[y][x] = true;
		
	if (y == Y2 && x == X2)
	{
		cout << cnt << endl;
		exit(0);
	}
	else if (map[y][x] == '.')
		cur_L.push({y, x});
	else if (map[y][x] == 'X')
	{
		next_L.push({y, x});
		return;
	}

	recur_L(y - 1, x);
	recur_L(y + 1, x);
	recur_L(y, x - 1);
	recur_L(y, x + 1);
}

void cal_L()
{
	while(cur_L.size())
	{
		pair<int, int> cur = cur_L.front();

		int y = cur.first;
		int x = cur.second;

		cur_L.pop();

		recur_L(y, x);
	}
}

void recur_map(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C || bitmap[y][x])
		return;

	bitmap[y][x] = true;
		
	if (map[y][x] == '.')
		cur_map.push({y, x});
	else if (map[y][x] == 'X')
	{
		next_map.push({y, x});
		return;
	}

	recur_map(y - 1, x);
	recur_map(y + 1, x);
	recur_map(y, x - 1);
	recur_map(y, x + 1);
}

void cal_map()
{
	while(cur_map.size())
	{
		pair<int, int> cur = cur_map.front();

		int y = cur.first;
		int x = cur.second;

		cur_map.pop();

		recur_map(y, x);
	}
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
			bitmap_L[i][j] = false;

			if (map[i][j] == 'L')
			{
				if (temp == 0)
				{
					Y1 = i;
					X1 = j;
					temp++;
					cur_L.push({i, j});
				}
				else
				{
					Y2 = i;
					X2 = j;
				}
			}
			if (map[i][j] == '.' || map[i][j] == 'L')
			{
				cur_map.push({i, j});
			}
		}
	
	cnt = 0;

	while (true)
	{	
		cal_L();
		cal_map();

		cur_L = next_L;
		cur_map = next_map;

		next_L = queue<pair<int, int> >();
		
		while (!next_map.empty())
		{
			pair<int, int> p = next_map.front();

			int y = p.first;
			int x = p.second;

			map[y][x] = '.';
			bitmap[y][x] = false;
			bitmap_L[y][x] = false;

			next_map.pop();
		}

		cnt++;
	}

	return 0;
}