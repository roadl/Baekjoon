#include <iostream>
#include <vector>

using namespace std;

int G1, G2, S1, S2, B1, B2;

int main()
{
	cin >> G1 >> S1 >> B1;
	cin >> G2 >> S2 >> B2;

	int diff;
	int cnt = 0;

	if (G1 < G2)
	{
		diff = G2 - G1;
		G1 = G2;
		S1 -= diff * 11;
		cnt += diff;
	}
	if (B1 < B2)
	{
		diff = (B2 - B1 + 8) / 9;
		B1 += diff * 9;
		S1 -= diff;
		cnt += diff;
	}

	if (S1 < S2)
	{
		diff = min((S2 - S1 + 8) / 9, G1 - G2);
		G1 -= diff;
		S1 += diff * 9;
		cnt += diff;

		if (S1 >= S2)
		{
			cout << cnt << endl;
			return 0;
		}

		diff = S2 - S1;
		S1 = S2;
		B1 -= diff * 11;
		cnt += diff;

		if (B1 >= B2)
			cout << cnt << endl;
		else
			cout << "-1" << endl;
	} else {
		cout << cnt << endl;
	}
}