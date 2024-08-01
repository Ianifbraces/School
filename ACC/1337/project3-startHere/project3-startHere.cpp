/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			6/20
Project #:		3
Status: 		WIP
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

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};// days of the week for convinence.
	float monkeys[3][7];

	for(int monkey = 0; monkey <= 2; monkey++){
		cout << "monkey " << monkey+1 << "\n\tEnter intake for each day";
		for (int day = 0; day <=6; day++){
			monkeys[monkey][day] = getFloatData("\n\t\t"+days[day]+':');
		}
	}//end of get data loops
	
	cout << "----------------------------------------------\n" << "Weekly Monkey Summary Intake\n" << "----------------------------------------------\n" << "Pounds of Food Eaten by Monkey for each day of week" << endl;

	cout << "\n\tMonkey\t\tSun\tMon\tTue\tWed\tThu\tFri\tSat";
	float max = 0;
	float min = 11;
	float sum = 0;
	for(int monkey = 0; monkey <= 2; monkey++){
		cout << "\n\t" << monkey+1 << '\t';
		for (int day = 0; day <=6; day++){
			cout << '\t' << monkeys[monkey][day];
			sum += monkeys[monkey][day];//adds to running sum for averaging later
			if (monkeys[monkey][day] > max){
				max = monkeys[monkey][day];//finds max value so far
			}
			if (monkeys[monkey][day] < min){
				min = monkeys[monkey][day];//finds min value so far
			}
		}
	}//End Display loops

	cout << "\n\nThe average food eaten per day by all monkeys\t\t\t" << sum/21 << "pounds";
	cout << "\t\nThe least amount of food eaten by any monkey\t\t\t" << min  << "pounds";//displays the three things
	cout << "\t\nThe largest amount of food eaten by any monkey\t\t\t" << max << "pounds" <<endl;

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
	cout << "Project #3" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #3" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


