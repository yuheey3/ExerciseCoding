/*
Name: Yuki Waka
Student#: 141082180
Date: 06.Mar.2020
Assignment2_task1

*/
#include <iostream>
#include <string>
#include <iomanip>
#include"myfriends.h"
using namespace std;


LinkList::LinkList() //constructor
{
	head = new Node();
	tail = head;
	size = 0;
} 
LinkList::~LinkList() //destructor
{
	Node* temp = head->getNext();
	delete head;

	for (int i = 0; i < size; i++) {
		head = temp;
		temp = temp->getNext();
		delete head;
	}
} 

int LinkList::getDataNumber()//check the number of node
{
	return size;
} 

void LinkList::insertion(string n, string b, string a, string cn) //Insert data to last node
{
	Node* insertNode = new Node(n, b, a, cn); //make memory
	tail->setNext(insertNode); //previous node will point to current node
	insertNode->setPrev(tail); //new node's previous node point to previous node
	tail = insertNode; //last node will be new node
	size++;


}
void LinkList::searching(string n)
{
	Node* p = head;
	Node* temp = p->getNext();

	if (head->getNext() == NULL)
	{
		cout << "There is no node in the link" << endl;

	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (temp->getName() == n)
			{
				cout << setw(15) << temp->getName() << setw(15) << temp->getBirthDay() << setw(30) << temp->getAddress() << setw(10) << temp->getNumber() << endl;
				break;
			}
			p = temp;
			temp = temp->getNext();
		}
	}
}



void LinkList::Edit(string n, string option, string data)
{
		Node* p = head;
		Node* temp = p->getNext();

		if (head->getNext() == NULL)
		{
			cout << "There is no node in the link" << endl;

		}
		else {
			int check = 0; //to check name is in the list

			for (int i = 0; i < size; i++)
			{
				if (temp->getName() == n)
				{
					check++;

					if (option == "1") 
					{
						temp->setBirth(data);
						cout << n << "'s date of birth is changed to " << data << endl;
						break;
					}
					else if (option == "2")
					{
						temp->setAddress(data);
						cout << n << "'s address is changed to " << data << endl;
						break;
					}
					else if (option =="3")
					{
						temp->setNumber(data);
						cout << n << "'s phone number is changed to " << data << endl;
						break;
					}
				}
				p = temp;
				temp = temp->getNext();
			
			}
			if (!check)
				cout << "The name you entered '"<< n << "' is not on the list." << endl;
}



}
bool LinkList::deletion(string n)
{
	Node* p = head;
	Node* temp = p->getNext();

	if (head->getNext() == NULL)
	{
		cout << "There is no node in the link" << endl;
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (temp->getName() == n)
		{
			//Make both of them point to temp's next node 
			p->setNext(temp->getNext());
			p->setPrev(temp->getNext());
			if (temp == tail)// if temp is tail, make p to tail
			{
				tail = p;
			}
			delete temp;
			size--;
			break;
		}
		p = temp;
		temp = temp->getNext();
	}

		return true;
	
}
void LinkList::display()
{
	Node* temp = head->getNext();
	Node* pre = tail;
	
	if (head->getNext() == NULL)
	{
		cout << endl;
		cout << "There is no node in the link" << endl;

	}
	else {
		cout.setf(ios::left);
		cout << endl;
		cout << setw(15) << "Name" << setw(15) << "DOB" << setw(40) << "Address" << setw(10) << "Phone Number" << endl;
		cout << "***********************************************************************************" << endl;

		for (int i = 0; i < size; i++)
		{
			cout << setw(15) << temp->getName() << setw(15) << temp->getBirthDay() << setw(40) << temp->getAddress() << setw(10) << temp->getNumber() << endl;
			temp = temp->getNext();
		}
	}
}




