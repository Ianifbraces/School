/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			9/17
Project #:		5
Status: 		Submitted
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
Prossesses empoly payrolls, and calculates the gross pay, tax,
and net pay for each employee.
-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				// for toupper() 
#include <cstdlib> 				// for random numbers
#include <fstream>              // filestream header
#include <cmath>
using namespace std;

// Decleration of prototype     
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	int employees;


	employees = getIntegerData("\tNumber of payrolls to be processed: ");

	string names[employees];
	int ids[employees];
	float income[employees];
	int type[employees];  
	cout << "-----------------------------------------------\n";

	for (int i = 0; i < employees; i++){
		cout << "\n\tEnter information for employee #" << i+1 << endl;
		ids[i] = getIntegerData("\t\tEmployee id: ");
		names[i] = getStringData("\t\tEmployee name: ");
		income[i] = getFloatData("\t\tPay rate: ");
		type[i] = getIntegerData("\t\tType: ");
		cout << "-----------------------------------------------\n";
	}

	int time[employees];

	for (int i = 0; i < employees; i++){
		time[i] = getIntegerData("\t\tHours worked for " + names[i] + ": ");
	}

	cout << "\n\t\t\tPayroll Report\n";
	cout << "-----------------------------------------------\n";
	cout << "ID\tName\tGross Pay\tTax\tNet Pay\n";
	cout << "-----------------------------------------------\n";

	for(int i = 0; i < employees; i++){
		float grossPay = 0;
		float tax = 0;
		float netPay = 0;
		grossPay = income[i] * time[i];
		if (type[i] == 0 && time[i] > 40){
			grossPay += (grossPay-40) * .5;
		}
		tax = grossPay * 0.15;
		netPay = grossPay - tax;
		cout << ids[i] << "\t" << names[i] << "\t" << grossPay << "\t\t" << tax << "\t" << netPay << endl;
	}
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


// This function will get a char value from the user
char getCharData(string prompt)
{
	char value;
	
	while (true)
	{
			cout << prompt;
			cin >> value;
	
			value = toupper(value);
			
			return value;	
			
			cout << "\t\tError Message. Selection does not exist"  << endl;
	} // end of while(true)

} // end of int getFloatData()

// This function will get a float value from the user
float getFloatData(string prompt)
{
	float value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		if (value >= 1 && value <= 100)
		{
			return value;	
		} // end of 	if (value >= 0)
			
		cout << "\t\tError Message. ONLY integers between 1 and 10"  << endl;
	} // end of while (true)
} // end of int getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		return value;
			
	} // end of while (true)
} // end of int getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	cin.ignore(); // clear the buffer
	string value;
	cout << prompt;
	getline(cin, value, '\n'); // accepts spaces in the entry
	
	return value;
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #5" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives\n Prossesses empoly payrolls, and calculates the gross pay, tax,\n and net pay for each employee." << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #5" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


