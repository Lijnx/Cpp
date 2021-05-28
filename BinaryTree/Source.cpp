#include <iostream>
#include <string>
using namespace std;

template <class ValueType>
class BinaryTree
{
private:
	struct Node
	{
		ValueType value;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* root;

public:
	BinaryTree()
	{
		root = nullptr;
	}

	BinaryTree(string text)
	{
		root = nullptr;
		string word;
		for (unsigned int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
				word.push_back(text[i]);
			else
			{
				insert(word);
				word.clear();
			}
		}
		insert(word);
	}

	void remove_tree(Node* current)
	{
		if (current->left != nullptr)
			remove_tree(current->left);
		if (current->right != nullptr)
			remove_tree(current->right);
		delete current;
	}

	~BinaryTree()
	{
		remove_tree(get_root());
	}

	Node* get_root()
	{
		return root;
	}

	bool is_empty()
	{
		return get_root() == nullptr;
	}

	void insert(ValueType value)
	{
		Node* node = new Node;
		node->value = value;
		if (is_empty())
			root = node;
		else
			insert_traverse(node, get_root());
	}

	void insert_traverse(Node* node, Node* current)
	{
		if (node->value > current->value)
		{
			if (current->right != nullptr)
				insert_traverse(node, current->right);
			else
				current->right = node;
		}
		if (node->value < current->value)
		{
			if (current->left != nullptr)
				insert_traverse(node, current->left);
			else
				current->left = node;
		}
	}

	void infix_traverse(Node* current)
	{
		if (current->left != nullptr)
			infix_traverse(current->left);
		cout << current->value << " ";
		if (current->right != nullptr)
			infix_traverse(current->right);
	}
};

int main()
{
	string input;
	getline(cin, input);
	BinaryTree <string> tree(input);
	tree.infix_traverse(tree.get_root());

	return 0;
}