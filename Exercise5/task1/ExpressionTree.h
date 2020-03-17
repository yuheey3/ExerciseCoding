#ifndef EXPRESSION_TREE_H__
#define EXPRESSION_TREE_H__
#include<iostream>
#include<string>
#include<stack>
using namespace std;

	//Creating node
	struct TreeNode
	{
		char value;
		TreeNode* left;
		TreeNode *right;
	};

	bool isOperator(char c)
	{
		if (c == '+' || c == '-' ||	c == '*' || c == '/' ||c == '^')
			return true;
		return false;
	}

	bool isRoot(char c)
	{
		return (c == 'R' ? true : false);
	}

	//inorder traversal 
	void displayInorder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			displayInorder(nodePtr->left);
			cout << nodePtr->value << ' ';
			displayInorder(nodePtr->right);
		}
	}
	//preorder traversal 
	void displayPreorder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			cout << nodePtr->value << ' ';
			displayPreorder(nodePtr->left);
			displayPreorder(nodePtr->right);
		}
	}
	//postorder traversal 
	void displayPostorder(TreeNode *nodePtr)
	{
		if (nodePtr)
		{
			displayPostorder(nodePtr->left);
			displayPostorder(nodePtr->right);
			cout << nodePtr->value << ' ';
		}
	}

	// A utility function to create a new node 
	TreeNode* newNode(int num)
	{
		TreeNode *nNode = new TreeNode;
		nNode->value = num;
		nNode->left = nNode->right = NULL;
		return nNode;
	};

	TreeNode* CreateTree(char postfix[])
	{
		//make stack for store value for temporary
		stack<TreeNode *> st;
		TreeNode *t, *t1, *t2;

		//insert the node using for loop
		for (int i = 0; i < strlen(postfix); i++)
		{
			// If the number, push to stack for temporary
			if (!isOperator(postfix[i]) && !isRoot(postfix[i]))
			{
				t = newNode(postfix[i]);
				st.push(t);
			}
			//if the root 
			else if (isRoot(postfix[i])){
				t = newNode(postfix[i]);

				//get top and remove from stack
				t1 = st.top(); 
				st.pop();      

				//connect to only right
				t->right = t1;

				// puch to stack
				st.push(t);
			}
			//if the operator
			else if(isOperator(postfix[i]))
			{
				t = newNode(postfix[i]);

				//store and remove from stack
				t1 = st.top(); 
				st.pop();      
				t2 = st.top();
				st.pop();

				//connect to left side and right side
				t->right = t1;
				t->left = t2;

				//push to stack
				st.push(t);
			}
		}

		//move to tree and remove stack
		t = st.top();
		st.pop();

		return t;
	}


#endif