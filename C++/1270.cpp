#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;
int t;

void solve()
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> t;
	
		map<long long, int> map;
		long long x;
		bool flag = false;

		for (int i = 0; i < t; i++) {
			cin >> x;
			map[x]++;
		}

		for (auto m: map) 
			if (m.second > t / 2) {
				cout << m.first << endl;;
				flag = true;
			}
		
		if (!flag)
			cout << "SYJKGW" << endl;
	}
}