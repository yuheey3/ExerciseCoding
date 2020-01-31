/*
Name: Yuki Waka
Date: 01/30/2020
StudentNumber: 141082180
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//function template
//It will return true, if it is Palindrome
template <typename T>
bool CheckPalindrome(T original, T reverse) {
	return (original == reverse) ? true : false;
}

int main() {

	int num[5];
	cout << "Please enter 5 numbers for palindrome" << endl;

	int count = 0;
	//get numbers from user
	while (count < 5)
	{
		cin >> num[count];
		count++;
	}

	//store in vector in order
	vector<int> palind(num, num + 5);

	//store in vector in reverse order
	vector<int> palindReverse;
	for (int k = 4; k >= 0; k--) {
		palindReverse.push_back(num[k]);
	}

	//display numbers that user entered
	cout << "You entered these numbers" << endl;
	for (auto i = palind.begin(); i != palind.end(); ++i)
		std::cout << *i << ' ';
	cout << endl << endl;

	//display reverse order
	cout << "This is Reverse order" << endl;
	for (auto i = palindReverse.begin(); i != palindReverse.end(); ++i)
		std::cout << *i << ' ';

	cout << endl << endl;

	//this will go to function template and get true or false.
	if(CheckPalindrome(palind, palindReverse))
		std::cout << "matched! This is Palindrome" << std::endl;
	else
		cout << "Not matched! This is not a Palindrome" << std::endl;


}