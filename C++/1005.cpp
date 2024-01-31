#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int build_time;
	int total_time;
	int num;
	vector<Node *> parent_node;

	Node() : build_time(-1), total_time(-1), num(-1){};
	~Node() {} ;
	void cal_total_time()
	{
		if (parent_node.size() == 0)
		{
			this->total_time = this->build_time;
			return;
		}
		if (total_time != -1)
			return ;

		vector<Node *>::iterator iter;
		int max = 0;

		for (iter = this->parent_node.begin(); iter != this->parent_node.end(); iter++)
		{
			if ((*iter)->total_time == -1)
				(*iter)->cal_total_time();
			if ((*iter)->total_time > max)
				max = (*iter)->total_time;
		}

		this->total_time = max + this->build_time;
	}
};

int main()
{
	vector<Node> buildings;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int building_num;
		int rule_num;

		cin >> building_num;
		cin >> rule_num;

		for (int j = 0; j < building_num; j++)
		{
			Node n;
			cin >> n.build_time;
			n.total_time = -1;
			n.num = j + 1;
			buildings.push_back(n);
		}
		for (int j = 0; j < rule_num; j++)
		{
			int x;
			int y;

			cin >> x;
			cin >> y;
			buildings[y - 1].parent_node.push_back(&buildings[x - 1]);
		}

		for (int j = 0; j < building_num; j++)
		{
			buildings[j].cal_total_time();
		}

		int target_building;

		cin >> target_building;

		cout << buildings[target_building - 1].total_time << endl;

		buildings.clear();
	}

	return 0;
}