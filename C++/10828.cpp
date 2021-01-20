#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value);
};

Node::Node(int value) 
{
	this->value = value;
	this->next = NULL;
}

class Stack {
public:
	Node* topNode;
	int stackSize;

	Stack();

	void push(int value);
	int pop();
	int size();
	int empty();
	int top();
};

Stack::Stack()
{
	this->topNode = NULL;
	this->stackSize = 0;
}

void Stack::push(int value)
{
	Node* n = new Node(value);
	n->next = this->topNode;
	topNode = n;
	
	stackSize++;
}

int Stack::pop()
{
	if (empty())
		return -1;

	int value = topNode->value;

	Node* temp = topNode;
	topNode = topNode->next;
	delete temp;

	stackSize--;

	return value;
}

int Stack::size()
{
	return stackSize;
}

int Stack::empty()
{
	if (stackSize == 0)
		return 1;
	else
		return 0;
}

int Stack::top()
{
	if (empty())
		return -1;
	else
		return topNode->value;
}

int main()
{
	Stack stack;
	string str;
	int n;

	cin >> n;
	getline(cin, str);

	for (int i = 0; i < n; i++) {
		getline(cin, str);

		if (str == "pop")
			cout << stack.pop() << endl;
		else if (str == "size")
			cout << stack.size() << endl;
		else if (str == "empty")
			cout << stack.empty() << endl;
		else if (str == "top")
			cout << stack.top() << endl;
		else {
			stack.push(stoi(str.substr(5)));
		}
	}

	return 0;
}