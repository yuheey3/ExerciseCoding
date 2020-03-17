/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_2
*/
#include <iostream> 
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <vector>
#include <typeinfo>
using namespace std;

template <class T>
void determineClass(T &c) {
	if (string(typeid(c).name()) == "class SavingsAccount") {

		c.credit(c.calculateInterest());
		cout << "\nSuccessfully added Interest\n";
	}
	else {
		cout << "\nThis is Checking Account\n";
		
	}

}

int main()
{
	//Create a vector of Account pointers to SavingsAccount and CheckingAccount objects.
	vector<Account*> SavingChecking;
	SavingChecking.push_back(new SavingsAccount(500.0, 0.3));
	SavingChecking.push_back(new CheckingAccount(600.0, 1.0));

	//allow the user to specify an amount of money to withdraw from the Account using member function debit 
	SavingChecking[0]->debit(400);
	SavingChecking[1]->debit(400);

	
	cout << "\nAfter debit $400 balance" << endl;
	cout << "Saving account : " << SavingChecking[0]->getBalance();
	cout << "\nChecking account : " << SavingChecking[1]->getBalance() << endl;;

	//amount of money to deposit into the Account using member function credit
	SavingChecking[0]->credit(500);
	SavingChecking[1]->credit(500);

	cout << "\nAfter credit $500 balance" << endl;
	cout << "Saving account : "<< SavingChecking[0]->getBalance();
	cout << "\nChecking account : " << SavingChecking[1]->getBalance() << endl;
	cout << endl;

	//determine its type
	//If an Account is a SavingsAccount, calculate the amount of interest
	//add the interest to the account balance using member function credit
	SavingsAccount sav (SavingChecking[0]->getBalance(), 0.3);
	CheckingAccount chk (SavingChecking[1]->getBalance(),0);

	determineClass(sav);
	determineClass(chk);

	vector<Account*> SavingChecking2;
	SavingChecking2.push_back(new SavingsAccount(sav.getBalance(), 0.3));
	SavingChecking2.push_back(new CheckingAccount(chk.getBalance(),0));
	
	cout << "\nUpdated Account balance.." << endl;
	cout << "Saving account: " << SavingChecking2[0]->getBalance();
	cout << "\nChecking account: " << SavingChecking2[1]->getBalance();
	cout << endl;
			
	return 0;
}

