/*
Name: Yuki Waka
Student Number: 141082180
Date: 5Feb.2020
Assignment1
Program 1
*/
#include<iostream>
#include <algorithm>
using namespace std;


int main() {
	
	const int size = 10;
	float arr[size];
	int count = 0;

	//Get numbers from user
	cout << "Enter 10 float number" << endl;

	while (count < size)
	{
		cin >> arr[count];
		count++;
	}

	//Display user input
	cout << "You entered these numbers" << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	//Use Sort function
	sort(arr, arr + size);

	cout << endl << endl;
	cout << "After Sort numbers..." << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}