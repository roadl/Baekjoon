#include <iostream>
#include <stack>

using namespace std;

class Oper{
public:
	char c;
	int prior;

	Oper(char c, int prior) {
		this->c = c;
		this->prior = prior;
	}
};

void printNPop(stack<Oper>* s) 
{
	if (s->top().c != '(' && s->top().c != ')')
		cout << s->top().c;
	s->pop();
}

int main()
{
	stack<Oper> s;
	char c;
	int prior;

	while (1) {
		cin.get(c);

		if (c == '\n') {
			while (!s.empty())
				printNPop(&s);
			break;
		}

		if (isalpha(c)) {
			cout << c;
			continue;
		}

		switch (c) {
		case '(': 
			s.push(Oper(c, 0)); continue;
		case ')': 
			while (!s.empty() && s.top().c != '(')
				printNPop(&s);
			s.pop();
			continue;
		case '+':
		case '-':
			prior = 1; break;
		case '*':
		case '/':
			prior = 2; break;
		}

		if (s.empty())
			s.push(Oper(c, prior));
		else {
			if (s.top().prior >= prior) {
				while (!s.empty() && s.top().prior >= prior)
					printNPop(&s);
				s.push(Oper(c, prior));
			}
			else {
				s.push(Oper(c, prior));
			}
		}
	}

	return 0;
}