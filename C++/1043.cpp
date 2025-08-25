#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 진실을 알고 있는 사람이 포함된 파티는 전부 진실
// while문을 돌면서 진실을 들으면 바꾸고 다시 돈다
// 한바퀴 돌았을때 더이상 진실을 알게 되는 사람이 없다면 break
// 진실을 아는 사람이 한명도 포함되지 않는 파티의 수 출력

bool has_intersection(const std::vector<int>& a, const std::vector<int>& b)
{
	std::unordered_set<int> setA(a.begin(), a.end());
	for (int val: b) {
		if (setA.count(val)) return true;
	}
	return false;
}

void merge_unique(std::vector<int>& a, const std::vector<int>& b)
{
	std::unordered_set<int> seen(a.begin(), a.end());
	for (int val: b) {
		if (seen.insert(val).second) {
			a.push_back(val);
		}
	}
}

void solve(vector<vector<int> > lines)
{
	int flag, count;

	while (true)
	{
		flag = false;
		count = 0;

		for (int i = 1; i < lines.size(); i++)
		{
			if (has_intersection(lines[0], lines[i]))
			{
				// cout << "intersects!!" << endl;
				merge_unique(lines[0], lines[i]);
				lines[i].clear();
				flag = true;
			}
			else if (lines[i].size() != 0)
				count++;
		}

		if (flag == false)
		{
			cout << count << endl;
			break;
		}
	}
}

vector<int> get_line()
{
	int num, temp;
	vector<int> line;

	cin >> num;

	while (num--)
	{
		cin >> temp;
		line.push_back(temp);
		// cout << temp << " ";
	}
	// cout << endl;

	return line;
}

int main()
{
	int n, m;

	int truth_n;
	vector<vector<int> > lines;

	cin >> n >> m;

	// cout << n << " " << m << endl;

	for (int i = 0; i <= m; i++) 
	{
		vector<int> line = get_line();
		lines.push_back(line);
	}

	if (lines[0].size() == 0)
		cout << m << endl;
	else
		solve(lines);

	// for (int i = 0; i < lines.size(); i++)
	// {
	// 	for (int j = 0; j < lines[i].size(); j++)
	// 		cout << lines[i][j] << " ";
	// 	cout << endl;
	// }

	return 0;
}