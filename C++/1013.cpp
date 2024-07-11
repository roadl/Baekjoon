#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string str)
{
	int index = 0;

	if (str.length() <= 1)
		return false;
	
	while (index != str.length())
	{
		if (str.compare(index, 2, "01") == 0)
		{
			index += 2;
			//cout << "01" << endl;
			continue;
		}
		if (str.compare(index, 2, "10") != 0)
			return false;
		//cout << "10" << endl;
		index += 2;
		if (str.compare(index, 1, "0") != 0)
			return false;
		while (str.compare(index, 1, "0") == 0)
		{
			//cout << "0" << endl;
			index += 1;
		}
		if (str.compare(index, 1, "1") != 0)
			return false;
		//cout << "1" << endl;
		index += 1;
		while (true)
		{
			if (str.compare(index, 3, "100") == 0)
			{
				//cout << "100 break" << endl;
				break;
			}
			if (str.compare(index, 3, "101") == 0)
			{
				//cout << "101 break" << endl;
				index += 1;
				break;
			}
			if (str.compare(index, 1, "1") == 0)
			{
				//cout << "1" << endl;
				index += 1;
				continue;
			}
			break;
		}
	}
	return true;
}

int main()
{
	int testNum;

	cin >> testNum;

	while (testNum--)
	{
		string str;
		
		cin >> str;

		if (solve(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}