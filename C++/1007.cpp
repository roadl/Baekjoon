#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef struct vec2 {
	int p1;
	int p2;
} Vec2;

void generateCombinations(vector<int>& arr, int n, int k, int index, vector<int>& currentCombination, vector<vector<int> >& allCombinations) {
    // 조합이 완성되었을 때
    if (currentCombination.size() == k) {
        allCombinations.push_back(currentCombination);
        return;
    }

    // 배열의 끝에 도달했을 때
    if (index == n) {
        return;
    }

    // 현재 원소를 선택
    currentCombination.push_back(arr[index]);
    generateCombinations(arr, n, k, index + 1, currentCombination, allCombinations);

    // 현재 원소를 선택하지 않음
    currentCombination.pop_back();
    generateCombinations(arr, n, k, index + 1, currentCombination, allCombinations);
}

vector<vector<int> > getCombinations(vector<int>& arr) {
    int n = arr.size();
    int k = n / 2;
    vector<vector<int> > allCombinations;
    vector<int> currentCombination;

    generateCombinations(arr, n, k, 0, currentCombination, allCombinations);

    return allCombinations;
}

void solve(vector<Vec2> &vectors)
{
	int size = vectors.size();
	double min = 300000;
	vector<vector<int> > combinations;
	vector<int> remain;
	Vec2 cur;
	
	for (int i = 0; i < size; i++)
		remain.push_back(i);

	combinations = getCombinations(remain);

	for (auto c: combinations)
	{
		int index = 0;
		cur.p1 = 0;
		cur.p2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == c[index])
			{
				cur.p1 += vectors[i].p1;
				cur.p2 += vectors[i].p2;
				index++;
			}
			else
			{
				cur.p1 -= vectors[i].p1;
				cur.p2 -= vectors[i].p2;
			}
		}
		double distance = sqrt(pow(cur.p1, 2) + pow(cur.p2, 2));
		
		if (distance < min)
			min = distance;
	}
	printf("%.12lf\n", min);
}

int main()
{
	int testNum;
	vector<Vec2> vectors;

	cin >> testNum;

	while (testNum--)
	{
		int n;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int p1, p2;

			cin >> p1;
			cin >> p2;
			
			Vec2 vec;

			vec.p1 = p1;
			vec.p2 = p2;

			vectors.push_back(vec);
		}

		solve(vectors);

		vectors.clear();
	}

	return 0;
}