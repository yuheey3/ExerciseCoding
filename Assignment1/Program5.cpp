/*
Name: Yuki Waka
Student Number : 141082180

Name Ramesh Sinnarajah
Student Number: 111404158

Date: 12Feb.2020
Assignment1
Program 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int even[] = { 2, 4, 6, 8 };
	int odd[] = { 1, 3, 5, 7, 9 };

	//size of array
	int n = sizeof(even) / sizeof(even[0]);
	int n2 = sizeof(odd) / sizeof(odd[0]);

	vector<int> vecEven(n);
	vector<int> vecOdd(n2);
	vector<int> vecMerge(n + n2);

	//copy array to vector
	copy(even, even + n, vecEven.begin());
	copy(odd, odd + n2, vecOdd.begin());

	//display
	cout << "Even numbers: ";
	for (int i : vecEven) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Odd numbers: ";
	for (int i : vecOdd) {
		cout << i << " ";
	}

	//merge containers into a vector
	merge(vecEven.begin(), vecEven.end(), vecOdd.begin(), vecOdd.end(), vecMerge.begin());

	cout << endl;
	cout << "After merge containers : ";

	for (vector<int>::iterator it = vecMerge.begin(); it != vecMerge.end(); ++it)
		cout << ' ' << *it;
	cout << endl;



}