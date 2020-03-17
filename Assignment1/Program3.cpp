/*
Name: Yuki Waka
Student Number : 141082180

Name Ramesh Sinnarajah
Student Number: 111404158

Date: 12Feb.2020
Assignment1
Program 3
*/
#include<iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main() {

	//To store word and the number of word(count) together
	map<string, int> frequency;
	string file;
	ifstream fileName;

	//Get input from user
	cout << "Please enter the name of text file" << endl;
	cin >> file;

	//open file
	fileName.open(file);

	//if file is not exist, error
	if (!fileName.is_open())
		std::cerr << "Error: Cannot open file";

	while (fileName.good())
	{
		//store word
		string s;

		//get one line
		getline(fileName, s);

		//skip space and find the location of first word 
		int pos = s.find_first_of(' ');
		if (pos < 0) continue;
		//when find word
		while (s.size() > 0)
		{
			//find space
			pos = s.find_first_of(' ');
			if (pos < 0)
				pos = s.size();
			//substract only word
			string word = s.substr(0, pos);
			//word is exist
			if (word != "")
				for (int i = 0, len = word.size(); i < len; i++)
				{
					//change to lower case
					word[i] = tolower(word[i]);
					//if find not a character(ex)!@#,...)delete it
					if (ispunct(word[i]))
					{
						word.erase(i--, 1);
						len = word.size();
					}
				}
			
			frequency[word]++;
			s = s.erase(0, pos + 1);
		}
	}
	
	cout << endl << endl;
	cout << "words and the number of times each word appears in a text file... " << endl << endl;

	//display all word and the number of word
	for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); ++it)
		cout << "word: " << it->first << "\t" << it->second << endl;

	return 0;
}
