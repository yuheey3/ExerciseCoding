/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_1
*/
#ifndef __CHECKINGACCOUNT_H__
#define __CHECKINGACCOUNT_H__
#include <iostream> 
#include "Account.h"
using namespace std;

class CheckingAccount : public Account 
{
	double transacFee = 0.0;
public:
	CheckingAccount(double balance, double tranFee) : Account(balance) {

		transacFee = tranFee;
	}
	void credit(double amount) {

		Account::credit(amount);
		
	}
	bool debit(double amount)  {

		if (Account::debit(amount)) {
			Account(Account(getBalance() - transacFee));
			return true;
		}
		else
			return false;
		}
	
};
#endif