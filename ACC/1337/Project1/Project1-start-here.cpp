/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			June 2nd
Project #:		1
Status: 		Submitted
Class:			COSC 1337
-------------------------------------------------------------------------
Project Objectives
	A movie theater only keeps a percentage of the revenue earned from ticket sales.  
	The remainder goes to the movie distributor.  Write a program that will calculate a gross income for a movie for a single show.  
	It will also calculate the amounts distributed to the theater and the movie distributor.

	The program will ask the user to enter the name of the movie, and how many adult and child tickets were sold.  

	The price of an adult ticket is $20.00, and a child ticket is $10.00.  T
	he theater keeps 40 percent of the box office Income and the rest goes to the movie distributor.
-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				//for toupper()
#include <cstdlib> 				//for random numbers
#include <fstream>               //includes filestream header
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
	
	// WRITE THE CODES BELOW
	
	//innisialization (forgive me for my poor spelling)
	string movie_name;
	int adult;
	int kid;
	int sum;
	
	//get values from user
	movie_name = getStringData("\tName of movie: ");
	adult = getIntegerData("\tAdult Tickets Sold: ")*20;
	kid = getIntegerData("\tChildren Tickets Sold: ")*10;
	sum = kid + adult;
	//print results
	cout << "----------------------------------------"  << endl;
	cout << "Movie Income Distribution Summary" << endl;
	cout << "----------------------------------------"  << endl;
	
	
	cout << "\tMovie Name: " << movie_name << "\n";
	
	cout << "\t Box Office Income: $" << sum << "\n\n";

	cout << "\t Movie distributor income: $" << sum*.60 << "\n";

	cout << "\t Theater income: $" << sum*.40 << "\n\n";
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

// This function will gets a char value from the user
char getCharData(string prompt)
{
	char value;
	
	cout << prompt;
	cin >> value;
	
	return value;	
			
} // end of getCharData()

// This function will get a float value from the user
float getFloatData(string prompt)
{
	float value;
	
	cout << prompt;
	cin >> value;	
	
	return value;	

} // end of getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;
} // end of getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;
	
	cout << prompt;
	getline(cin, value, '\n'); // accepts spaces in the entry
	
	return value;
	
} // end of getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------"  << endl;
	cout << "Project 1" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives: Finds the Income dictribution for distributor and theater" << endl;
	cout << "----------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------"  << endl;
	cout << "End of Project 1" << endl;
	cout << "----------------------------------------"  << endl;
} // end of projectEnd()


