#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

string L, R;
int n1, n2;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int flag = false;

	cin >> n1 >> n2;

	R = to_string(n2);

	ostringstream oss;
	oss << setw(R.length()) << setfill('0') << n1;

	L = oss.str();

	for (int i = 0; i < R.length(); i++) {
		if (R[i] == '8' && L[i] == '8')
			cnt++;
		else if (R[i] > L[i])
			break;
	}

	cout << cnt << endl;

	return 0;
}