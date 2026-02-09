#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> A, B, C, D;
double max_round;
double min_round;

/*
AB와 평행하게 CD
AC와 평행하게 BD
AD와 평행하게 BC 만들고 둘레 젤 작은거, 긴거 확인

*/

double cal_dis(pair<int, int> p1, pair<int, int> p2)
{
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool is_cross(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) 
{
	if ((p1.first - p2.first) * (p1.second - p3.second)
		== (p1.first - p3.first) * (p1.second - p2.second))
		return true;
	return false;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> A.first >> A.second >> B.first
		>> B.second >> C.first >> C.second;

	if (is_cross(A, B, C)) {
		cout << "-1\n";
		return 0;
	}

	double p1 = 2 * (cal_dis(A, B) + cal_dis(A, C));
	double p2 = 2 * (cal_dis(B, A) + cal_dis(B, C));
	double p3 = 2 * (cal_dis(C, A) + cal_dis(C, B));

	double mx = max({p1, p2, p3});
	double mn = min({p1, p2, p3});

	cout << fixed;
	cout.precision(10);
	cout << mx - mn << endl;
}