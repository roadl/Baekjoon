#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int	tree_count;

int minX, maxX, minY, maxY, min;

typedef struct info {
	int	x;
	int	y;
	int	value;
} Info;

vector<Info> vec;
vector<int> x_vec;
vector<int> y_vec;

bool compare(Info i1, Info i2)
{
	if (i1.value > i2.value)
		return true;
	return false;
}

bool in_rect(Info i, int top, int bottom, int left, int right)
{
	if (i.y < top || i.y > bottom || i.x < left || i.x > right)
		return false;
	return true;
}

int get_out_fence(vector<Info> vec, int top, int bottom, int left, int right)
{
	int res = 0;

	for (int i = 0; i < tree_count; i++)
		if (!in_rect(vec[i], top, bottom, left, right))
			res += vec[i].value;
	return res;
}

int get_out_count(vector<Info> vec, int top, int bottom, int left, int right)
{
	int count = 0;

	for (int i = 0; i < tree_count; i++)
		if (!in_rect(vec[i], top, bottom, left, right))
			count++;
	return count;
}

int	get_min_tree(vector<Info> vec, int top, int bottom, int left, int right)
{
	int require = ((bottom - top) + (right - left)) * 2;
	int	fence;
	int	count;

	// if ((bottom == top) || (right == left))
	// 	require /= 2;

	fence = get_out_fence(vec, top, bottom, left, right);
	count = get_out_count(vec, top, bottom, left, right);

	//printf("top: %d, bot: %d, left: %d, right: %d - require: %d, out: %d\n" \
		, top, bottom, left, right, require, fence);
	
	if (require <= fence)
		return count;

	for (int i = 0; i < vec.size(); i++)
	{
		Info info = vec[i];

		// printf("%d, %d, %d\n", info.x, info.y, info.value);
		if (in_rect(info, top, bottom, left, right))
		{
			fence += info.value;
			count++;

			//printf("require: %d, fence: %d, count: %d\n", require, fence, count);

			if (require <= fence)
				return count;
		}
	}

	return count;
}

void solve(vector<Info> vec)
{
	int minX, maxX, minY, maxY, min;

	minX = x_vec[0];
	maxX = x_vec[tree_count - 1];
	minY = y_vec[0];
	maxY = y_vec[tree_count - 1];

	min = tree_count;

	//get_min_tree(vec, 1, 1, 1, 7);

	for (int i = 0; i < tree_count; i++)
	{
		for (int j = i; j < tree_count; j++)
		{
			for (int k = 0; k < tree_count; k++)
			{
				for (int n = k; n < tree_count; n++)
				{
					int tmp = get_min_tree(vec, y_vec[i], y_vec[j], x_vec[k], x_vec[n]);

					if (tmp < min)
					{
						min = tmp;

						//printf("top: %d, bot: %d, left: %d, right: %d - out: %d\n" \
							, i, j, k, n, tmp);
					}
				}
			}
		}
	}

	cout << min << endl;
}

int main()
{
    cin >> tree_count;

    // 2차원 벡터 선언

	cin.ignore();

    // 각 행의 입력값을 받기 위해 반복문 사용
    for (int i = 0; i < tree_count; ++i) {
		Info info;

		cin >> info.x;
		cin >> info.y;
		cin >> info.value;

		vec.push_back(info);
		x_vec.push_back(info.x);
		y_vec.push_back(info.y);
    }

	// if (tree_count == 1)
	// {
	// 	cout << "0" << endl;
	// 	return 0;
	// }

	sort(vec.begin(), vec.end(), compare);
	sort(x_vec.begin(), x_vec.end());
	sort(y_vec.begin(), y_vec.end());

	// for (int i = 0; i < x_vec.size(); i++)
	// 	printf("%d ", x_vec[i]);

	// printf("height: %d, width: %d\n", height, width);

	solve(vec);

	return 0;
}