#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	A.resize(N);
	B.resize(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int sum = 0;

	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];
	
	cout << sum << "\n";
}