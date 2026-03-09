#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int N;

vector<pair<int, int>> points;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;

		cin >> x >> y;

		points.push_back({x, y});
	}

	long double area = 0;

	for (int i = 0; i < N - 1; i++) {
		area += (double)points[i].first * points[i + 1].second;
		area -= (double)points[i + 1].first * points[i].second;
	}

	area += (double)points[N - 1].first * points[0].second;
	area -= (double)points[0].first * points[N - 1].second;

	cout << fixed << setprecision(1) << abs(area) / 2.0 << endl;

	return 0;
}