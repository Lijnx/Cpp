#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node* current = new Node;
Node* head = new Node;

void print_list()
{
	for (Node* temp = head; temp != nullptr; temp = temp->next)
	{
		cout << temp->value << " ";
	}
}

void push_front(int value)
{
	Node* front = new Node;
	front->value = value;
	front->next = nullptr;
	Node* temp = current;
	temp->next = front;
	current = front;
}

void push_back(int value)
{
	Node* back = new Node;
	back->value = value;
	Node* temp = head;
	back->next = temp;
	head = back;
}

void delete_list()
{
	Node* i = head;
	while (i != nullptr)
	{
		Node* temp = i;
		i = i->next;
		delete temp;
	}
}

void pop_front()
{
	Node* temp = head;
	while (temp->next->next != nullptr)
	{
		temp = temp->next;
	}
	delete current;
	temp->next = nullptr;
	current = temp;
}

void pop_back()
{
	Node* temp = head;
	head = head->next;
	delete temp;
}

void delete_elem(int pos)
{
	Node* temp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	Node* elem = temp->next;
	temp->next = elem->next;
	delete elem;
}

void insert_elem(int pos, int value)
{
	Node* temp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	Node* elem = new Node;
	elem->value = value;
	elem->next = temp->next->next;
	temp->next = elem;
}

void insert_array(int* arr, int n)
{
	head->value = arr[0];
	current = head;
	for (int i = 1; i < n; i++)
	{
		push_front(arr[i]);
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void input_list()
{
	int n;
	cin >> n;
	head->value = n;
	current = head;
	while (n != 0)
	{
		cin >> n;
		push_front(n);
	}
	pop_front();
}

void sort_list()
{
	for (Node* i = head; i->next != nullptr; i = i->next)
	{
		for (Node* j = i->next; j != nullptr; j = j->next)
		{
			if (i->value > j->value)
			{
				swap(i->value, j->value);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	input_list();
	sort_list();
	print_list();
	delete_list();

	return 0;
}