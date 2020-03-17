/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_3
*/
#include<iostream>
#include <string>
#include "Tax.h"
#include "UpdatedTax.h"
#include "CustomizedTax.h"
using namespace std;

int main()
{
	//Task 6, create the object of CustomizedTax class to test your program, Add menu inside loop to ask for options.
	int choice = 0;
	float amount = 0.0;
	float tax1, tax2;
	string r1, r2, rCin;
	float upTax[2] = { };
	float result = {};

	CustomizedTax Mytax;

	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "Tax Calculate Program" << endl; 
		cout << "\n---------------------" << endl;
		cout << "1.Insert region1 and region2" << endl;
		cout << "2.Insert tax percentage" << endl;
		cout << "3.Insert Amount" << endl;
		cout << "4.Display Tax" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your Choice: ";

		cin >> choice;

		switch (choice)
		{ 
		case 1:
			cout << "Enter the region1 and refion2: ";
			cin >> r1 >> r2;
			Mytax.insertRegion(r1,r2);
			cout << "Successfully inserted region" << endl;
			break;
		case 2:
			cout << "Enter the tax rate for " << r1 << " and " << r2  <<" : ";
			cin >> tax1 >> tax2;
		    Mytax.UpdatedTaxForRegion(tax1, tax2);
			cout << "Successfully updated tax for " << r1 << " tax: " << Mytax.taxRate_factor2 << endl;
			cout << "Successfully updated tax for " << r2 << " tax: " << Mytax.taxRate_factor3 << endl;
			break;
		case 3:
			cout << "Enter the amount: ";
			cin >> amount;
			cout << "Enter the region " << r1 << " or " << r2 << endl;
			cin >> rCin;
 			result =  Mytax.amountAfterTax(amount, rCin);
			break;
		case 4:
			cout << "Displaying " << endl;;
			cout << "After calculated tax is...: " << result << endl;
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}


	}


	
}