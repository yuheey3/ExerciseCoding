#include<iostream>
#include<string>
#include<stack>
#include "ExpressionTree.h"
using namespace std;


int main()
{
	char postOrder[] = "66+xx*x**3xx**+4xx**R+33++";
	TreeNode* tree = CreateTree(postOrder);

	cout << "12 * x * x * x + 3 * x * x + Root 4 * x * x + 6" << endl << endl;

	cout << "Inorder(LVR): ";
	displayInorder(tree);
	cout << endl << endl;;

	cout << "Preorder(VLR): ";
	displayPreorder(tree);
	cout << endl << endl;

	cout << "Postorder(LRV): ";
	displayPostorder(tree);
	cout << endl;
	
	return 0;
}