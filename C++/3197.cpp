#include <iostream>
#include <vector>

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

int R, C;

char map[1500][1500];
int day_map[1500][1500];

int X1, X2, Y1, Y2;

int cal_day(int y, int x);
void check_cell(int y, int x, int *min);

int main()
{
	cin >> R >> C;

	int temp = 0;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			day_map[i][j] = -1;

			if (map[i][j] == 'L')
			{
				if (temp == 0)
				{
					Y1 = i;
					X1 = j;
					temp++;
				}
				else
				{
					Y2 = i;
					X2 = j;
				}
			}
		}
	
	int flag = false;

	while (!flag)
	{
		flag = true;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int day;
				
				if (map[i][j] == '.' || map[i][j] == 'L')
					day = 0;
				else
					day = cal_day(i, j);

				if (day != day_map[i][j])
				{
					day_map[i][j] = day;
					flag = false;
				}
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'L')
				cout << "L ";
			else
				cout << day_map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int cal_day(int y, int x)
{
	int min = 1500;

	check_cell(y - 1, x, &min);
	check_cell(y + 1, x, &min);
	check_cell(y, x - 1, &min);
	check_cell(y, x + 1, &min);

	printf("(%d, %d): %d\n", y, x, min);

	return min;
}

void check_cell(int y, int x, int *min)
{
	int res = -1;

	if (y < 0 || y >= R || x < 0 || x >= C)
		res = -1;
	else if (map[y][x] == '.' || map[y][x] == 'L')
		res = 1;
	else if (day_map[y][x] != -1)
		res = day_map[y][x] + 1;
	
	if (res != -1 && res < *min)
		*min = res;
}