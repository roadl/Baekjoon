#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, K;
vector<long long> vec;
vector<long long> tree;

long long build(int node, int start, int end)
{
	if (start == end)
		return tree[node] = vec[start];
	
	int mid = (start + end) / 2;

	long long left = build(node * 2, start, mid);
	long long right = build(node * 2 + 1, mid + 1, end);

	return tree[node] = left + right;
}

long long cal_tree(int target, long long value, int node, int start, int end)
{
	if (start == end)
		return tree[node] = value;
	
	int mid = (start + end) / 2;

	long long sum = 0;

	if (target <= mid) {
		sum += tree[node * 2 + 1];
		sum += cal_tree(target, value, node * 2, start, mid);
	}
	else {
		sum += tree[node * 2];
		sum += cal_tree(target, value, node * 2 + 1, mid + 1, end);
	}
	return tree[node] = sum;
}

long long cal_sum(int left, int right, int node, int start, int end)
{
	if (left == start && right == end)
		return tree[node];

	int mid = (start + end) / 2;

	long long sum = 0;

	if (left <= mid)
		sum += cal_sum(left, min(right, mid), node * 2, start, mid);
	if (right > mid)
		sum += cal_sum(max(left, mid + 1), right, node * 2 + 1, mid + 1, end);
	
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	vec.resize(N);
	tree.resize(N * 4);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	build(1, 0, N - 1);
	
	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;

		cin >> a >> b >> c;

		if (a == 1)
			cal_tree(b - 1, c, 1, 0, N - 1);
		else
			cout << cal_sum(b - 1, c - 1, 1, 0, N - 1) << "\n";
	}
}