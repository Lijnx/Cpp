#include <iostream>
#include <string>
using namespace std;

template <typename StackType> class Stack
{
private:

	struct Node
	{
		StackType value;
		Node* prev;
	};
	Node* top;

public:

	Stack()
	{
		top = nullptr;
	}

	~Stack()
	{
		while (top != nullptr)
			pop();
	}

	void print_stack()
	{
		for (Node* temp = top; temp != nullptr; temp = temp->prev)
			cout << temp->value << " ";
	}

	StackType get_top()
	{
		return top->value;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	void push(StackType value)
	{
		Node* front = new Node;
		front->value = value;
		Node* temp = top;
		front->prev = temp;
		top = front;
	}

	void pop()
	{
		Node* temp = top;
		top = top->prev;
		delete temp;
	}
};

bool isOperand(char x)
{
	if ((x >= '0' && x <= '9') || x == '.')
		return true;
	else
		return false;
}

int get_priority(char x)
{
	switch (x)
	{
	case '(':
		return 1;
	case ')':
		return 2;
	case '=':
		return 3;
	case '+':
		return 4;
	case '-':
		return 4;
	case '*':
		return 5;
	case '/':
		return 5;
	default:
		return -1;
	}
}

double doOperation(double a, double b, char c)
{
	switch (c)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '*':
		return b * a;
	case '/':
		return b / a;
	default:
		return -1;
	}
}

string toPostfix(string infix)
{
	Stack <char> stack;
	string postfix;
	for (unsigned int i = 0; i < infix.length(); i++)
	{
		char x = infix[i];

		if (isOperand(x))
		{
			postfix.append(1, x);
			if (!isOperand(infix[i + 1]))
				postfix.append(1, ' ');
		}

		if (x == '(')
			stack.push(x);

		if (x == ')')
		{
			while (stack.get_top() != '(')
			{
				postfix.append(1, stack.get_top());
				stack.pop();
			}
			stack.pop();
		}

		if (!(isOperand(x)) && x != '(' && x != ')')
		{
			while (!stack.isEmpty() && get_priority(stack.get_top()) >= get_priority(x))
			{
				postfix.append(1, stack.get_top());
				stack.pop();
			}
			stack.push(x);
		}
	}
	while (!stack.isEmpty())
	{
		postfix.append(1, stack.get_top());
		stack.pop();
	}
	return postfix;
}

double calculate(string postfix)
{
	Stack <double> stack;
	string num;
	for (unsigned int i = 0; i < postfix.length(); i++)
	{
		char x = postfix[i];

		if (isOperand(x))
			num.append(1, x);

		if (x == ' ')
		{
			stack.push(stod(num));
			num.clear();
		}

		if (!isOperand(x) && x != ' ')
		{
			double a = stack.get_top();
			stack.pop();
			double b = stack.get_top();
			stack.pop();
			stack.push(doOperation(a, b, x));
		}
	}
	double result = stack.get_top();
	stack.pop();
	return result;
}

int main()
{
	string infix;

	cin >> infix;
	cout << calculate(toPostfix(infix));

	return 0;
}