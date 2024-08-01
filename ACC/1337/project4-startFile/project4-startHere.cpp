/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			6/20
Project #:		4
Status: 		Submited
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

This code calculates shipping charges based on package weight, dimensions, and destination. The program ensures 
compliance with size and weight restrictions, performs input validation, and calculates costs using specified rates. 
It also provides transaction details and a summary of accepted and rejected packages upon program termination.

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
	int rcount;
	int acount;
	float cost;
	float tcost;
	int temp;
	int largest;
	int weight;
	int size;
	float rcost[50] = {1.50, 2.10, 4, 6.75, 6.75, 9.9, 9.9, 14.95, 14.95, 14.95, 19.40, 19.40, 19.40, 24.20, 24.20, 24.20, 27.30, 27.30, 27.30, 27.30, 31.90, 31.90, 31.90, 31.90, 31.90, 38.50, 38.50, 38.50, 38.50, 38.50, 43.50, 43.50, 43.50, 43.50, 43.50, 44.80, 44.80, 44.80, 44.80, 44.80, 47.40, 47.40, 47.40, 47.40, 47.40, 55.20, 55.20, 55.20, 55.20, 55.20};
//for refrace with weight. (refrance cost)
	while (true){
		char location = getCharData("\nMenu\nEnter Location - (T)exas| (O)ut of state| (F)oreign (X)it: ");

		if (location == 'X'){
			break;// leaves loop
		}
		else if (not(location == 'T'|| location == 'O'|| location == 'F'|| location == 'S')){
			cout << "Invalid, please try again.";
			continue;
		}// valid location check
		weight = getIntegerData("\nEnter package weight: ");
		if (weight <= 0){
			cout <<"invalid weight" << endl;
			continue;
		}
		temp = getIntegerData("Enter Length: ");
		if (temp <= 0){
			cout <<"invalid Length" << endl;
			continue;
		}
		size = temp;
		largest = temp;
		temp = getIntegerData("Enter Width: ");
		if (temp <= 0){
			cout <<"invalid Width" << endl;
			continue;
		}
		size += temp;
		if (temp > largest){
			largest = temp;
		}
		temp = getIntegerData("Enter Hight: ");
		if (temp <= 0){
			cout <<"invalid Hight" << endl;
			continue;
		}
		size += temp;
		if (temp > largest){
			largest = temp;
		}

		//Displays output;
		cout << "\nTransaction Completed: ";
		if (size - largest >= 60 || largest > 72|| weight > 50){
			cout << "Rejected";
		}
		cout << "Mail to ";
		if (location == 'T'){ 
		cout << "Texas\n----------------------------------------------\n\tLocation\t\tTexas\n";
		cost = 0;
		}
		else if (location == 'O'){
		cout << "Out of State\n----------------------------------------------\n\tLocation\t\tOut of State\n";
		cost = 35;
		}
		else if (location == 'F'){
		cout << "Foreign\n----------------------------------------------\n\tLocation\t\tForeign";
		cost = 40;
		}// finds location for output lines
		else{
		cout << "Outer Space\n----------------------------------------------\n\tLocation\t\tOuter Space\n";
		cost = 1000;
		}//If you don't want your pacage lost in space, don't chose this option, no refunds.
		cout << "Status\t\t";
		if (size - largest >= 60 || largest > 72 || weight > 50){
			cout << "Rejected\n";
			cout << "Weight\t\t" << weight << "lbs.\n";
			cout << "Cost\t\tN/A\n";
			rcount ++; // Rejected count is incremented
		}
		else{
			cout << "Accepted\n";
			cout << "Weight\t\t" << weight << "lbs.\n";
			cout << "Cost\t\t" << rcost[weight] + cost;//finds and displays cost
			tcost += cost + rcost[weight];// ands to total
			acount ++; // Accepted count is incremented
		}

	}// end of While True

	cout << "\nShipping Transaction\n----------------------------------------------\n\tNumber of accepted packages\t" << acount << "\n\tNumber of rejected packages\t" << rcount << "\n\tTotal Cost\t" << tcost << endl;
	//Displays results. 

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
	cout << "Project #4" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #4" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


