/*
Name: Yuki Waka
Student#: 141082180
Date: 22Feb.2020
Lab6
*/
#include <iostream>
#include <string>
using namespace std;

/*Create a single linked list that contains the data (age) of your friends.
Perform basic operations including insertion, deletion, searching and display.
The insertion operation should only allow a friend’s data to be inserted in sorted order only.*/

class Node {

private:
	string name;
	int age;
	double height;
	Node *next;
	Node(string s, int a, double h, Node *n)
	{
		name = s;
		age = a;
		height = h;
		next = n;
	}
public:
	friend class LinkList;
};


class LinkList
{
private:
	Node *head, *tail;
	int size;

public:
	LinkList() //initialization
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	LinkList(string s, int a, double h) //Insert information
	{
		head = tail = new Node(s, a, h, NULL);
		size = 1;
	}
	void insertion(string s, int a, double h) 
	{
		Node *newNode = new Node(s, a, h, NULL);
		if (head == NULL) //If link is empty, insert node to first(head)
			head = newNode;
		else
			tail->next = newNode; //If link is not empty, insert node to last(tail)

		tail = newNode;
		size++;
	}

	void searching(string s, int a, double h)
	{
		Node *insert = new Node(s, a, h, NULL);
		Node *scan; //to search
		if (head != NULL) //if list is not empty
		{
			if (head->age > a) {      //If node(age) is smaller than head, then insert to head
				insert->next = head;
				head = insert;
			}
			else if (tail->age < a) {      //If node(age) is bigger than tail, then insert to tail
				tail = insert;
			}
			else {      
				scan = head;
				while (scan->next->age < insert->age) //find appropriate position
					scan = scan->next;
				insert->next = scan->next;  //change pointer
				scan->next = insert;   
			}
		}
		else
		{
			head = insert;
			tail = insert;
			head->next = NULL;
		}
		size++;//increase size

	}

	void deletion(string s) {
		Node* current = head;
		Node* previous = head;

		while (current != NULL && (s != current->name)) //proceed to next until find 'name' in the link
		{

			previous = current->next;    //pointer
			current = current->next;

		}
		if (current != NULL) //link is not null and match string(name)
		{
			previous = current->next;
			size--;
			delete current; //delete

		}

		return;
	}



	void display()
	{
		Node *scan = head;
		while (scan != NULL)
		{
			cout << scan->name << " age:" << scan->age << " height:" << scan->height << endl << endl;
			scan = scan->next;
		}
	}
};


int main() {

	cout << "Sorted by age!" << endl << endl;
	//make link list
	LinkList L1("Hoony", 25, 170);
	//Insert freinds
	L1.insertion("Yuki", 29, 160);
	L1.searching("Jin", 24, 175);
	L1.searching("Ian", 27, 185);
	L1.searching("Jeongwon", 26, 180);
	L1.searching("Kimin", 22, 180);
	L1.searching("Seongmin", 20, 178);
	L1.searching("Yuri", 19, 163);

	//display
	L1.display();
	cout << endl << endl;
	cout << "After delete Yuki!" << endl;
	//delete Yuki
	L1.deletion("Yuki");
	cout << endl;

	L1.display();

	return 0;
}