#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
int board[10][10];
int cnt = 0;
int b_max, w_max = 0;

/*
정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다.
체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때,
서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.

1. 백 트래킹
	- 왼쪽 위칸부터 돌며 비숍을 놔보고 놓을 수 있으면 다음 칸을 보며 확인
	- 트리형식으로 모두 체크한 후에 백트래킹으로 돌아와서 다음 경우의 수 확인
	- 시간초과, 7*7부터 느림

1.1 어두운칸, 밝은칸 백 트래킹
	- 비숍은 애초에 갈 수 있는 칸이 정해져 있어서 전체로 하면 효율 떨어짐
	- 어두운칸, 밝은 칸으로 나눠서 따로 체크
	- (0,0) - (2,0)(1,1)(0,2) 식으로 나눠서 한 대각선에 놓으면 다음 대각선부터 확인 시작
	- 각 칸 확인 후 최대 개수 더해서 출력
*/

vector<pair<int, int> > current;

void put(int y, int x, bool is_black)
{
	current.push_back({y, x});
	cnt++;
	if (is_black && cnt > b_max)
		b_max = cnt;
	if (!is_black && cnt > w_max)
		w_max = cnt;
}

void unput()
{
	current.pop_back();
	cnt--;
}

bool is_available(int y, int x)
{
	if (!board[y][x])
		return false;

	for (auto b: current)
		if (abs(b.first - y) == abs(b.second - x))
			return false;
	
	return true;
}

void black_recur(int y)
{
	for (int i = y; i < N; i++)
	{
		int j = i * 2, k = 0;

		while (j >= 0 && k < N)
		{
			if (j < N && is_available(j, k))
			{
				put(j, k, true);
				black_recur(i + 1);
				unput();
			}
			j--; k++;
		}
	}
}

void white_recur(int y)
{
	for (int i = y; i < N - 1; i++)
	{
		int j = 1 + i * 2, k = 0;

		while (j >= 0 && k < N)
		{
			if (j < N && is_available(j, k))
			{
				put(j, k, false);
				white_recur(i + 1);
				unput();
			}
			j--; k++;
		}
	}
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	black_recur(0);
	white_recur(0);

	cout << b_max + w_max << endl;
}