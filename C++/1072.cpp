#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void j2_solve(long long X, long long Y, int Z)
{
	long long win_rate;
	int count = 0;

	if (Z >= 99)
	{
		cout << -1 << endl;
		return;
	}

	// cout << "origin rate: " << Z << endl;

	// cout << "Z: " << Z << endl;

	while (true) {
		count += 1000;
		win_rate = (Y + count) * 100 / (X + count);

		if (Z < win_rate)
			break ;
	}

	while (true) {
		count--;

		win_rate = (Y + count) * 100 / (X + count);

		if (Z == win_rate)
		{
			count++;
			break ;
		}
	}

	cout << count << endl;
	
	// cout << "win_rate: " << win_rate << endl;
	
	// cout << (X + count) << " " << (Y + count) << " " << win_rate << endl;
}

int main()
{
	long long X, Y;
	long long Z;

	cin >> X >> Y;

	Z = Y * 100 / X;

	j2_solve(X, Y, Z);

	return 0;
}

// void j_solve(long long X, long long Y, int Z)
// {
// 	long long win_rate;
// 	int count = 0;

// 	if (Z >= 99)
// 	{
// 		cout << -1 << endl;
// 		return;
// 	}

// 	// cout << "origin rate: " << Z << endl;

// 	// cout << "Z: " << Z << endl;

// 	while (true) {
// 		count++;
// 		win_rate = (Y + count) * 100 / (X + count);

// 		if (Z < win_rate)
// 			break ;
// 	}

// 	cout << count << endl;
	
// 	// cout << "win_rate: " << win_rate << endl;
	
// 	// cout << (X + count) << " " << (Y + count) << " " << win_rate << endl;
// }