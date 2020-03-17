/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_1
*/
#include <iostream> 
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;


int main()
{
	/******Test for Account.h*********/
	cout << "***********************************************************************" << endl;
	cout << "Test for Account.h" << endl;
	cout << "***********************************************************************" << endl;

	Account Myaccount(1000.00);
	Account MyaccountFaild(-100.00);

	Myaccount.credit(300);
	cout << "After credit your balance is : " << Myaccount.getBalance() << endl;
	Myaccount.debit(200);
	cout << "After debit your balance is : " << Myaccount.getBalance() << endl;

	//Debit amount exceeded account balance.
	Myaccount.debit(20000);

	cout << endl;

	/******Test for SavingsAccount.h*********/
	cout << "***********************************************************************" << endl;
	cout << "Test for SavingsAccount.h" << endl;
	cout << "***********************************************************************" << endl;
	SavingsAccount MySaving(500.00,0.2);
	SavingsAccount MySavingFaild(-100.00,0.1);

	MySaving.credit(900.00);
	cout << "After credit your balance is : " << MySaving.getBalance() << endl;
	MySaving.debit(100.00);
	cout << "After debit your balance is : " << MySaving.getBalance() << endl;

	//Debit amount exceeded account balance.
	MySaving.debit(20000);


	//calculate interest and added to balance
	MySaving.credit(MySaving.calculateInterest());
	cout << "After calculate interest your balance is : " << MySaving.getBalance() << endl;

	cout << endl;

	/******Test for CheckingAccount.h*********/
	cout << "***********************************************************************" << endl;
	cout << "Test for CheckingAccount.h" << endl;
	cout << "***********************************************************************" << endl;
	CheckingAccount MyChecking(550.00, 0.2);
	CheckingAccount MyCheckingFaild(-100.00, 0.1);

	MyChecking.credit(50.00);
	cout << "After credit your balance is : " << MyChecking.getBalance() << endl;

	//transaction fee is applied
	MyChecking.debit(100.00);
	cout << "After debit your balance is : " << MyChecking.getBalance() << endl;

	//Debit amount exceeded account balance.
	MyChecking.debit(20000);
	




} 
