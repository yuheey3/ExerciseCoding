/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_1
*/
#ifndef __SAVINGACCOUNT_H__
#define __SAVINGACCOUNT_H__
#include <iostream> 
#include "Account.h"
using namespace std;

class SavingsAccount : public Account
{
	double interRate = 0.0;
public:
	SavingsAccount(double balance, double rate) : Account(balance)
	{
		interRate = rate;
	}
	double calculateInterest() {

		return getBalance() * interRate;
	}
	double getRate() {
		return interRate;
	}
	double getBalance() {
		return balance;
	}
	

};
#endif