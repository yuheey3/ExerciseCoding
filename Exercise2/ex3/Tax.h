/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_3
*/
#ifndef __TAX_H__
#define __TAX_H__
#include<iostream>
using namespace std;

class Tax
{
public:
	float taxRate_factor1;


	Tax() :taxRate_factor1(2)
	{
		cout << "Default Tax Rate applies" << endl;
	}
	Tax(float tr)
	{
		taxRate_factor1 = tr;
	}

	virtual float taxCalc(float amount, string r)
	{
		return taxRate_factor1 * amount;
	}

	virtual float amountAfterTax(float amount, string r)
	{
		return (amount - taxCalc(amount,r));
	}


};
#endif