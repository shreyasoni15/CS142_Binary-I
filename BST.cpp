#include <iostream>
	using namespace std;
	
	class Node
	{
		public:
		int data;
		// Children
		Node *left;
		Node *right;
	
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
	};
	
	class BST
	{
		public:
		Node *root;
	
		BST() { root = NULL; }
	
		void insert(int value)
		{ insertHelper(root, value);}
	
		void insertHelper(Node *curr, int value)
		{
			if (root == NULL)
			{
				root = new Node(value);
			}
			// Else compare the current data with value
			else if (value < curr->data)
			{
				// else move left and call insertHelper
				if (curr->left == NULL)
					curr->left = new Node(value);
				Else
					insertHelper(curr->left, value);
			}
			Else
			{
				// Else move right and call insertHelper
				if (curr->right == NULL)
					curr->right = new Node(value);
				Else
					insertHelper(curr->right, value);
			}
	  	}
	
	  	void display()
		{displayHelper(root);}
	
	  	void displayHelper(Node *curr)
		{
			// Base condition
			if (curr == NULL)
				return;
			// Display left
			displayHelper(curr->left);
			// Display current
			cout << curr->data << ",";
			// Display right
			displayHelper(curr->right);
		}
	
		void displayFancy()
		{
			displayFancyHelper(root,0);
		}
	
		void displayFancyHelper(Node * cur,int s)
		{
			//return when at the end of a trail 
			if(cur==NULL)
			{return;}
			//go left and increase the number of spaces
			displayFancyHelper(cur->left,s+1);
			//print the spaces
			for(int i=0;i<4*s;i++){cout<<" ";}
			//print the data
			cout<<cur->data<<endl;
			//go right and increase the number of spaces
			displayFancyHelper(cur->right,s+1);
	  	}
	
		Node* search(Node * cur,int value)
		{
			if(cur==NULL)
			{return NULL;}
			if(cur->data==value)
			{return cur;}
			if(cur->data<value)
			{return search(cur->right,value);}
			Else
			{return search(cur->left,value);}
		}
	};
	
	int main()
	{
		BST bst1;
		bst1.insert(4);
		bst1.insert(8);
		bst1.insert(2);
		bst1.insert(3);
		bst1.insert(1);
		bst1.insert(78);
		bst1.insert(5);
		bst1.insert(67);
		bst1.insert(6);
		bst1.displayFancy();
		if (bst1.search (bst1.root , 2) == NULL)
		{
			cout << "Not Found"<<endl;
		}
		else
		{
			cout<<"Found"<<endl;
		}
  return 0;  
	}
