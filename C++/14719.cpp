#include <iostream>
#include <vector>

using namespace std;

// 높이별로 계산
// 왼쪽 오른쪽 끝 벽 확인, 그 사이 빈칸 개수만큼 ++
void solve(vector<int> map, int H, int W)
{
	bool flag = false;
	int left, right, ans = 0;
	
	for (int i = 0; i <= H; i++)
	{
		for (left = 0; left < W && map[left] < i; left++);
		for (right = W - 1; right >= 0 && map[right] < i; right--);

		if (left > right)
			continue;

		// printf("height: %d, left: %d, right: %d\n", i, left, right);
		
		for (int j = left + 1; j < right; j++)
			if (map[j] < i)
				ans++;

		// printf("current: %d\n", ans);
	}

	cout << ans << endl;
}

int main()
{
	int H, W;

	cin >> H >> W;

	vector<int> map;

	for (int i = 0; i < W; i++)
	{
		int temp;

		cin >> temp;

		map.push_back(temp);
	}

	solve(map, H, W);

	return 0;
}