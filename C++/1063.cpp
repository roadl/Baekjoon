#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

pair<int, int> king, stone, offset;

void move() {
	pair<int, int> king_next, stone_next = stone;

	king_next.first = king.first + offset.first;
	king_next.second = king.second + offset.second;

	if (king_next == stone) {
		stone_next.first = stone.first + offset.first;
		stone_next.second = stone.second + offset.second;
	}

	if (king_next.first < 0 || king_next.first > 7
		|| king_next.second < 0 || king_next.second > 7
		|| stone_next.first < 0 || stone_next.first > 7
		|| stone_next.second < 0 || stone_next.second > 7)
		return;
	
	king = king_next;
	stone = stone_next;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;

	cin >> str;

	king.first = str[0] - 'A';
	king.second = str[1] - '1';
	
	cin >> str;

	stone.first = str[0] - 'A';
	stone.second = str[1] - '1';

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		offset.first = 0;
		offset.second = 0;

		if (str.find('R') != string::npos)
			offset.first++;
		if (str.find('L') != string::npos)
			offset.first--;
		if (str.find('B') != string::npos)
			offset.second--;
		if (str.find('T') != string::npos)
			offset.second++;
		
		move();
	}

	printf("%c%c\n%c%c\n", king.first + 'A', king.second + '1',
		stone.first + 'A', stone.second + '1');
}