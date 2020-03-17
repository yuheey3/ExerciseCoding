/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_3
*/
#ifndef __UPDATEDTAX_H__
#define __UPDATEDTAX_H__
#include <iostream>
#include "Tax.h"
using namespace std;

// Task 1: Make the required function(s) (such as taxCalc) virtual in Tax class
// Task 2: Add 2 more tax factors (taxRate_factor2, taxRate_factor3 in this class)
// Task 3: Redefine virtual function(s) in child class to incorporate all three tax factors

class UpdatedTax : public Tax
{
public:
	float taxRate_factor2 = 0;
	float taxRate_factor3 = 0;

	UpdatedTax() 
	{
		cout << "Default updated Tax Rate applies" << endl;
	}
	float UpdatedTaxForRegion(float tr1, float tr2)
	{
		taxRate_factor2 = tr1;
		taxRate_factor3 = tr2;
		return taxRate_factor2, taxRate_factor3;
	}

	float taxCalc(float amount, string r)
	{
		return taxRate_factor2 * amount;
	}

	float amountAfterTax(float amount, string r)
	{
		return (amount - taxCalc(amount,r));
	}
};
#endif