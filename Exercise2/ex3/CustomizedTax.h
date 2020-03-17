/*
Name: Yuki Waka
Student#: 141082180
Date: 11Feb.2020
Lab4_3
*/
#ifndef __CUSTOMIZED_H__
#define  __CUSTOMIZED_H__
// Task 4: Add 2 regions (region1, region2)
// Task 5: Redefine the relevant virtual function in this class to incorporate the tax factors based on regions 
#include <iostream>
#include "UpdatedTax.h"
using namespace std;

class CustomizedTax : public UpdatedTax
{
public:

	string region1;
	string region2;

	CustomizedTax()
	{
		region1 = "";
		region2 = "";
	}
	void insertRegion(string r1, string r2){
	
		region1 = r1;
		region2 = r2;
		cout << "Region1  is : " << region1 << endl;
		cout << " Region2 is : " << region2 << endl;
	}

	float taxCalc(float amount, string r){

		if (r == region1) {
			cout << "Successfully calculated tax" << endl;
			return taxRate_factor2 * amount;
		}
		else if (r == region2) {
			cout << "Successfully calculated tax" << endl;
			return taxRate_factor3 * amount;
		}
		else {
			cout << "No region here. Please select option." << endl;
			return 0;
		}
	}

	float amountAfterTax(float amount, string r)
	{
		return (amount + taxCalc(amount, r));
	}
};
#endif