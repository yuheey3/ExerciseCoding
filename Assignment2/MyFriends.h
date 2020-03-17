#ifndef MYFRIENDS_H__
#define MYFRIENDS_H__

#include <iostream>
#include <string.h>
using namespace std;

class Node {

private:
	string name;
	string birthdate;
	string address;
	string contact_number;

	Node *next;//pointer for next
	Node *prev;//pointer for previous
public:
	Node(){ next = NULL, prev = NULL; } //Initialization

	//Constructor for Inserting data
	Node(string na, string b, string a, string cn)
	{
		this->name = na;
		this->birthdate = b;
		this->address = a;
		this->contact_number = cn;
		next = NULL;
		prev = NULL;
	}
	//get data
	string getName() { return name; }
	string getBirthDay() { return birthdate; }
	string getAddress() { return address; }
	string getNumber() { return contact_number; }

	//get position
	Node* getNext() { return next; }
	Node* getPrev() { return prev; }

	//set data
	void setName(string n) { name = n; }
	void setBirth(string b) { birthdate = b; }
	void setAddress(string a) { address = a; }
	void setNumber(string num) { contact_number = num; }

	void setNext(Node* n) { next = n; }
	void setPrev(Node* p) { next = p; }

};


class LinkList
{
private:
	Node *head;
	Node *tail;
	int size; //the number of node

public:
	LinkList(); //constructor
	~LinkList(); //destructor

	int getDataNumber(); //check the number of node

	void insertion(string n, string b, string a, string cn);
	void searching(string n);
	void Edit(string n, string option, string data);
	bool deletion(string n);
	void display();


};

#endif