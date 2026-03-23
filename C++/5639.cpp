#include <iostream>

using namespace std;

int tree[10000];

void recur(int start, int end) {
    if (start >= end) return;

    for (int i = start + 1; i < end; i++) {
        if (tree[i] > tree[start]) {
            recur(start + 1, i);
            recur(i, end);
            cout << tree[start] << '\n';
            return;
        }
    }

    recur(start + 1, end);
    cout << tree[start] << '\n';
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int input, i = 0;

	while (cin >> input)
		tree[i++] = input;

	recur(0, i);

	return 0;
}