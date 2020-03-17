/*
Name: Yuki Waka
Student# : 141082180
Date: 18Feb.2020
Lab5
*/
#include <iostream>
#include <string>
using namespace std;

class WIFE;

class HUSBAND
{
private:
	string Husband_fname;
	string Husband_lname;
	int Husband_income;
	friend class WIFE;
public:
	HUSBAND(string f1, string l1, int inc) :Husband_fname(f1), Husband_lname(l1), Husband_income(inc) {}
	HUSBAND()
	{
		//	Default initializations of data members
		Husband_fname = "";
		Husband_lname = "";
		Husband_income = 0;
	}
	int getIncome() {
		return Husband_income;
	}

	string getFullNameForHusband() {

		string fullName = "";
		fullName = this->Husband_fname;
		fullName.append(" ");
		fullName.append(this->Husband_lname);

		return fullName;

	}

};

class WIFE
{
private:
	string Wife_fname;
	string Wife_lname;
	int Wife_income;
	int tax_rate;
public:
	WIFE(string f2, string l2, int inc, int tr) :Wife_fname(f2), Wife_lname(l2), Wife_income(inc), tax_rate(tr) {};
	WIFE()
	{
		//Default initializations of private data members;
		string Wife_fname = "";
		string Wife_lname = "";
		int Wife_income = 0;
		int tax_rate = 0;
		
	}
	float calcTax(HUSBAND &f) {
		float tempTax = 0.0;
		float tempTax2 = 0.0;
		float total = 0.0;
		

		tempTax = f.Husband_income * (getTaxRate() / 100);
		tempTax2 = Wife_income * (getTaxRate() / 100);
		total = tempTax + tempTax2;
		cout << "Husband's tax amount is: $" << tempTax << endl;
		cout << "Wife's tax amount is: $" << tempTax2 << endl;
	
		return total;
	}

	float getTaxRate() {

		return this->tax_rate;
	}

	int getIncome() {
		return Wife_income;
	}
	
	int GetTotalIncome(HUSBAND &f) {
		int total = 0;
		total = getIncome() + f.getIncome();
		return total;
	}
	string GetFullNameForWife() {

		string fullName = "";
		fullName = this->Wife_fname;
		fullName.append(" ");
		fullName.append(this->Wife_lname);

		return fullName;

	}

};

int main()
{
	HUSBAND obj1("Albert", "John", 55026);
	WIFE obj2("Mary", "Chin", 120000, 5);

	cout << "Husband full name is: " << obj1.getFullNameForHusband() << endl;
	cout << "Wife full name is: " << obj2.GetFullNameForWife() << endl << endl;
	cout << "Task1: Display the tax rate" << endl;
	cout << "Tax rate is : " << obj2.getTaxRate() << "%" << endl << endl;
	cout << "Task2: Display income of HUSBAND" << endl;	
	cout << "The income of Husband is: $" << obj1.getIncome() << endl << endl;
	cout << "Task3: Display income of WIFE" << endl;
	cout << "The income of Wife is : $" << obj2.getIncome() << endl << endl;
	cout << "Task4: Display total family income" << endl;
	cout << "Total family income is : $" << obj2.GetTotalIncome(obj1) << endl << endl;
	cout << "Task5: Display total Tax Amount" << endl;
	cout << "Total tax amount is: $" << obj2.calcTax(obj1) << endl << endl;


	system("pause");
	return 0;
}
