/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_1
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream> 
using namespace std;

class Account {

public:
	double balance = 0.0;
	Account(double bal)
	{
		if (bal < 0.0) {
			cout << endl;
			cout << "The initial balance was invalid." << endl << endl;
			balance = 0.0;
		}
		else {
			balance = bal;
			cout << endl;
			cout << "Your balance is : " << bal << endl;
			cout << "Successfullly initialzed your balance." << endl;;
		}
	}
	void credit(double amount) {
		balance = balance + amount;
	}
	bool debit(double amount) {
		if (amount < balance) {
			balance = balance - amount;
			return true;
		}
		else {
			cout << endl;
			cout << "Debit amount exceeded account balance." << endl;
			return false;
		}
	}
	virtual double getBalance() {
		return balance;
	}

};
#endif