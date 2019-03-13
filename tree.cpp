#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node * right;
	Node * left;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
class BiST
{
	public:
	Node * root;
	BiST()
	{
		root = NULL;
	}
	void insert(int value)
	{
		inserthelper(root,value);
	}
	void inserthelper(Node * current, int value)
	{
		//base case if current is null then insert there
		if(current == NULL)
		{
			current = new Node(value);
			if(root == NULL) root = current;
			return;
		}
		//else compare the current data with value
		else if(value < current->data)
		{
			if(current->left == NULL)
			{
				current->left = new Node(value);
			}
			else
			{
				inserthelper(current->left,value);
			}
		}
		//if current data is less than value then move right and call insert
		//else move lrft and call insert
		else
		{
			if(current->right == NULL)
			{
				current->right = new Node(value);
			}
			else
			{
				inserthelper(current->right, value);
			}
		}
	}
	void display()
	{
		display2(root);
	}
	void display2(Node * current)
	{
		if(current == NULL) return;
		display2(current->left);
		cout<<current->data<<",";
		display2(current->right); 
	}
	Node * search(Node * current,int value)
	{
		if(current == NULL || current->data == value)
		{
			return current;
		}
		else if(value < current->data)
		{
			return search(current->left,value);
		}
		else
		{
			return search(current->right, value);
		}
	}
	//height();
	//deleteNode();
};
int main()
{
	BiST a;
	a.insert(4);
	a.insert(3);
	a.insert(5);
	a.display();
	return 0;
}
