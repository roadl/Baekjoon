#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long long min, max, count;
	 
	cin >> min;
	cin >> max;

	vector<bool> vec(max - min + 1, false);

	count = 0;

	for (unsigned long long i = 2; i * i <= max; i++)
	{
		//cout << "i: " << i << endl;
		for (unsigned long long j = (min - 1) / (i * i) + 1; i * i * j <= max; j++)
		{
			//cout << "j: " << j << endl;
			vec[i * i * j - min] = true;
		}
	}
	for (unsigned long long i = 0; i < max - min + 1; i++)
		if (vec[i] == false)
			count++;

	cout << count << endl;

	return 0;
}