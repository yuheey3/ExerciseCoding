#include<iostream>
#include<string>
#include"myfriends.h"
using namespace std;

int main()
{

	LinkList *li = new LinkList();
	int choice;
	string n, b, a, p;
	string item, da;

	//make 5 freind in the list
	li->insertion("Yuki", "01/01/1990", "Scarborough", "902-111-1111");
	li->insertion("Hoony", "05/12/1994", "Eglinton", "647-676-9999");
	li->insertion("Jin", "08/03/1994", "North York", "647-345-6543");
	li->insertion("Ian", "01/01/1991", "Scarborgh", "902-111-111");
	li->insertion("JongWong", "05/12/1914", "Eglion", "647-676-999");
	li->insertion("Yuri", "08/03/1924", "Northrk", "647-345-543");


	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "Information of friends" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Insert friends information in the double linked list" << endl;
		cout << "2.Delete friend information in the double linked list" << endl;
		cout << "3.Find friend in the double linked list" << endl;
		cout << "4.Edit friends in the double linked list" << endl;
		cout << "5.Count friends in the double linked list" << endl;
		cout << "6.Display all freiends" << endl;
		cout << "7.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter friend's name: ";
			cin >> n;
			cout << "Date of birth: ";
			cin >> b;
			cout << "Address: ";
			cin.ignore();
			getline(cin, a);
			cout << "Phone number: ";
			cin >> p;
			li->insertion(n, b, a, p); 
			cout << endl;
			cout << "your friend's information is successfully stored in the list!" << endl;

			break;
		case 2:
		cout << "Enter name of friend to be deleted: ";
		cin >> n;
		if (li->deletion(n)) {
			cout << endl;
			cout << "your friend " << n << " is deleted on the list!";
		}
		break;
		case 3:
		cout << "Enter your friend name to find: ";
		cin >> n;
		cout << endl;
		cout << "Here is your friend Information" << endl;
		li->searching(n);
		break;
		case 4:
		cout << "Enter your friend name to edit: ";
		cin >> n;
		cout << "Please choose which data you want to edit" << endl;
		cout << "1.DOB     2.Address    3.Phone number : ";
		cin >> item;
		cout << "Enter new data: ";
		cin >> da;
		li->Edit(n, item, da);
		cout << endl;
		cout << "Successfully edied!";
		break;
		case 5:
			cout << endl;
			cout << "Total " << li->getDataNumber() << " friend is on the list";
			break;
		case 6:
			li->display();
			break;
		case 7:
			exit(1);
			break;
	default:
		cout << "Wrong Choice" << endl;
	}
}
	return 0;
}