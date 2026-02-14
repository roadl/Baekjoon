#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int mafia;

int dead_count = 0;
int guilty[16];
bool dead[16] = { false };

int cur_day = 0;
int max_day = 0;

int R[16][16];

void recur();

void cal_day()
{
	int min = 0;
	int p;

	for (int i = 0; i < N; i++) {
		if (!dead[i] && guilty[i] > min) {
			p = i;
			min = guilty[i];
		}
	}
	
	dead_count++;
	dead[p] = true;

	recur();

	dead_count--;
	dead[p] = false;
}

void cal_night()
{
	for (int i = 0; i < N; i++) {
		if (!dead[i] && i != mafia) {
			dead_count++;
			dead[i] = true;
			cur_day++;

			for (int j = 0; j < N; j++)
				guilty[j] += R[i][j];

			recur();

			for (int j = 0; j < N; j++)
				guilty[j] -= R[i][j];

			dead_count--;
			dead[i] = false;
			cur_day--;
		}
	}
}

void recur() 
{
	if (dead[mafia] || dead_count == N - 1) {
		max_day = max(max_day, cur_day);
		return;
	}

	if ((N - dead_count) % 2 == 0)
		cal_night();

	else
		cal_day();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> guilty[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> R[i][j];
		}
	}

	cin >> mafia;

	recur();

	cout << max_day << "\n";
}