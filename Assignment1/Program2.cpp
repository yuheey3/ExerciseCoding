/*
Name: Yuki Waka
Student#: 141082180
Date: 6Feb.2020
Assignment 1
Program2
*/
#include<iostream>
#include <list>
using namespace std;

int main() {

	std::list<int> even = { 1,2,3,4,5,6 };
	std::list<int> odd = { 1,2,3,4,5,6,7 };
	
	void moveForward(list<int>);
	void moveBackward(list<int>);

	//Call moveforward function
	moveForward(even);
	moveForward(odd);

	cout << endl;

	//Call movebackward function
	moveBackward(even);
	moveBackward(odd);

}

void moveForward(list<int> list) {
	std::list<int> temp;

	cout << "Default numbers are..." << endl;
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << ' ' << *it;
	cout << endl;

	//push frnot to temp list to reverse order
	while (!list.empty()) {
		temp.push_front(list.front());
		list.pop_front();
	}

	//swap temp and list
	swap(list, temp);

	cout << "Numbers after push front and swap" << endl;
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
}

void moveBackward(list<int> list) {
	std::list<int> temp;

	cout << "Default numbers are..." << endl;
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << ' ' << *it;
	cout << endl;

	//push back to temp list to reverse order
	while (!list.empty()) {
		temp.push_back(list.back());
		list.pop_back();
	}

	//swap temp and list
	swap(list, temp);

	cout << "Numbers after push back and swap" << endl;
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
}