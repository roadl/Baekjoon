#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n, x, temp;
	list<int> arr;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < x)
			arr.push_back(temp);
	}

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}