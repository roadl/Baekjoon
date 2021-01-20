#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int value;
	Node* prev;
	Node* next;

	Node(int value);
};

Node::Node(int value)
{
	this->value = value;
	this->prev = NULL;
	this->next = NULL;
}

class Queue {
public:
	Node* frontNode;
	Node* backNode;
	int queueSize;

	Queue();

	void push(int value);
	int pop();
	int size();
	int empty();
	int front();
	int back();
};

Queue::Queue()
{
	this->frontNode = NULL;
	this->backNode = NULL;
	this->queueSize = 0;
}

void Queue::push(int value)
{
	Node* n = new Node(value);

	n->next = backNode;

	if (empty())
		frontNode = n;
	else
		backNode->prev = n;

	backNode = n;

	queueSize++;
}

int Queue::pop()
{
	if (empty())
		return -1;

	int value = frontNode->value;

	Node* temp = frontNode;
	frontNode = frontNode->prev;

	if (queueSize != 1)
		frontNode->next = NULL;
	
	delete temp;

	queueSize--;

	return value;
}

int Queue::size()
{
	return queueSize;
}

int Queue::empty()
{
	if (queueSize == 0)
		return 1;
	else
		return 0;
}

int Queue::front()
{
	if (empty())
		return -1;
	else
		return frontNode->value;
}

int Queue::back()
{
	if (empty())
		return -1;
	else
		return backNode->value;
}

int main()
{
	Queue Queue;
	string str;
	int n;

	cin >> n;
	getline(cin, str);

	for (int i = 0; i < n; i++) {
		getline(cin, str);

		if (str == "pop")
			cout << Queue.pop() << endl;
		else if (str == "size")
			cout << Queue.size() << endl;
		else if (str == "empty")
			cout << Queue.empty() << endl;
		else if (str == "front")
			cout << Queue.front() << endl;
		else if (str == "back")
			cout << Queue.back() << endl;
		else {
			Queue.push(stoi(str.substr(5)));
		}
	}

	return 0;
}