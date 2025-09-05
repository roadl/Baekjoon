#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

enum Dice {
	A = 0, B, C, F, E, D
};

bool is_opposite(int d1, int d2)
{
	if (abs(d1 - d2) == 3)
		return true;
	return false;
}

bool is_opposite(int d1, int d2, int d3)
{
	if (abs(d1 - d2) == 3)
		return true;
	if (abs(d2 - d3) == 3)
		return true;
	if (abs(d3 - d1) == 3)
		return true;
	return false;
}

int cal_1_min(int dice[6])
{
	int min = dice[A];

	for (int i = 0; i < 6; i++) {
		if (dice[i] < min)
			min = dice[i];
	}

	return min;
}

int cal_2_min(int dice[6])
{
	int min = dice[A] + dice[B];

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1;  j < 6; j++) {
			int temp = dice[i] + dice[j];

			if (!is_opposite(i, j) && temp < min)
				min = temp;
		}
	}

	return min;
}

int cal_3_min(int dice[6])
{
	int min = dice[A] + dice[B] + dice[C];

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				int temp = dice[i] + dice[j] + dice[k];

				if (!is_opposite(i, j, k) && temp < min)
					min = temp;
			}
		}
	}
	
	return min;
}

long long solve(int N, int dice[6])
{
	long long result = 0;

	if (N == 1) {
		for (int i = 0; i < 6; i++)
			result += dice[i];
		result -= *max_element(dice, dice + 6);
		return result;
	}

	result += cal_3_min(dice) * 4;
	result += cal_2_min(dice) * (8 * (N - 2) + 4);
	result += cal_1_min(dice) * (pow(N - 2, 2) * 5 + 4 * (N - 2));

	return result;
}

int main()
{
	int N;
	int dice[6];

	cin >> N;

	cin >> dice[A];
	cin >> dice[B];
	cin >> dice[C];
	cin >> dice[D];
	cin >> dice[E];
	cin >> dice[F];

	cout << solve (N, dice) << endl;

	return 0;
}