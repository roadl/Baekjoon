#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
int** board;
int cnt;
int b_max = 0;

vector<pair<int, int> > current;

bool check_board(int y, int x)
{
	for (pair<int, int> bishop: current)
		if (abs(y - bishop.first) == abs(x - bishop.second))
			return false;
	return true;
}

void put(int y, int x)
{
	cnt++;
	current.push_back({y, x});

	// cout << "put(" << y << "," << x << "), " << cnt << endl;
}

void unput()
{
	cnt--;
	current.pop_back();
}

void next(int i, int j)
{
	for (int x = j + 1; x < N; x++)
	{
		if (board[i][x] == 1 && check_board(i, x))
		{
			put(i, x);
			next(i, x);
			unput();
		}
	}

	for (int y = i + 1; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == 1 && check_board(y, x))
			{
				put(y, x);
				next(y, x);
				unput();
			}
		}
	}

	if (cnt > b_max)
		b_max = cnt;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0)
				continue;
			
			current.clear();
			cnt = 0;

			// cout << "-----" << endl;

			put(i, j);

			next(i, j);
			
			// for (int y = i; y < N; y++)
			// 	for (int x = 0; x < N; x++)
			// 		if (board[y][x] == 1 && check_board(y, x))
			// 			put(y, x);

			// if (cnt > max)
			// 	max = cnt;
		}
	}

	cout << b_max << endl;
}

int main()
{
	cin >> N;

	board = (int **)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++)
		board[i] = (int *)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	
	solve();
}