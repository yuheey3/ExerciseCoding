#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
	int choice;
	int num;
	IntBinaryTree tree;

	//generate 20 random number(range is 1 to 50)
	//Insert the data by generating random numbers. 
	srand((unsigned)time(0));
	int randomNumber;
	for (int index = 0; index < 20; index++) {
		randomNumber = (rand() % 50) + 1;
		tree.insertNode(randomNumber);
	}
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "Display Tree" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Display InOrder" << endl;
		cout << "2.Display PreOrder" << endl;
		cout << "3.Display PostOrder" << endl;
		cout << "4.Delete Node" << endl;
		cout << "5.Exit" << endl;
		cout << "\n\nEnter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tree.showNodesInOrder();
			break;
		case 2: 
			tree.showNodesPreOrder();
			break;
		case 3 :
			tree.showNodesPostOrder();
			break;
		case 4: 
			cout << "Enter you want to delete: ";
			cin >> num;
			tree.remove(num);
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
