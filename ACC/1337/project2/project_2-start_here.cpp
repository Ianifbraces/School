/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			6/4
Project #:		2
Status: 		Complete
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

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
char choseOperation();
bool withdraw(float &);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	string name = getStringData("Name: ");
	float balance = getIntegerData("Enter the beginning balance: ");
	float fees = 0;
	while(true){

	char Operation = choseOperation();

		if (Operation == 'W'){
			// put Withdraw here
			if (withdraw(balance)){
				cout << "\t\tError: withdrawl amout higher then current balance\n";
				cout << "\t\tOverdraft fee: $100.00\n\t";
				fees += 100;
			}
			else{
				cout << "\tWithdrawl processed.\n";
			}
			cout << "\tService charge: $.25 for withdrawl\n\n";
			fees +=.25;
			cout << "Curent balance: $" << balance << "\n" << "Service and overdraft fees: $" << fees << "\n";
		}
		else if (Operation == 'D'){
			//put Deposit here
			balance += getIntegerData("\nEnter deposit amount: ");
			cout << "\n\n\tDeposit prosesed.\n\tCurent balance: $" << balance << "\n\n\tService and overdraft fees $" << fees << "\n";
		}
		else if (Operation == 'E'){
			//enter results here
			cout << "Name" << name << "\n";
			cout << "Current balance: $" << balance << "\n";
			cout << "Service and overdraft fees: $" << fees << "\n\n";
			cout << "Final balance: $" << balance - fees << "\n";
			
			// Displays end of project
			projectEnd();
		
			return 0;
		}
		else{
			cout << "\tError, invalid transaction type \'" << Operation << "\'. please try again. Valid transactions inclued W, D, and E.\n";
		}	
	}
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
			
		if (value >= 1 && value <= 10)
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
	string value;
	cout << prompt;
	getline(cin, value, '\n'); // accepts spaces in the entry
	
	return value;
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #2" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #2" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


char choseOperation(){
	cout << "----------------------------------------------------------------------------\n";
	cout << "Select Transaction Type:\n"; 
	cout << "W - Withdraw monies\n";
	cout << "D – Deposit monies\n";
	cout << "E – End of Transaction\n";
	cout << "----------------------------------------------------------------------------\n";
	return getCharData("Enter transaction type: ");
}

bool withdraw(float &money){
	int withdrawed = getIntegerData("\tEnter transaction amount: ");
	if (withdrawed < 0){
		cout << "\t\tError: Withdraw amount negitive. Please try again with a positive number.\n";
		return withdraw(money);
	}
	if (withdrawed > money){
		return true;
	}
	money -= withdrawed;
	return false;
}
