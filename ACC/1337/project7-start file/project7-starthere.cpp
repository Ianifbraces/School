/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			7/13/2024
Project #:		7
Status: 		Completed
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
Use a struct to create a Date class that stores the month, day, and year.
Can display the date in three formats: MM/DD/YYYY, Month DD, YYYY, and DD Month YYYY.
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

struct Date
{
	int month = 1;
	int day = 1; // default values
	int year = 2020;
	private:
		int limit[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // array of days in each month
		string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // array of month names

	public:
	bool setDate(int m, int d, int y)
	{
		if (m < 1 || m > 12) // validation check month
		{
			cout << "Invalid month";
			return false;
		}
		if (d < 1 || d > limit[m - 1]) // validation check day
		{
			cout << "Invalid day";
			return false;
		}
		if (y < 1900 || y > 2022) // validation check year
		{
			cout << "Invalid year";
			return false;
		}
		if (m == 2 && d == 29 && y % 4 != 0) // validation check leap year
		{
			cout << "Invalid day, Not a leap year";
			return false;
		}// end of validation check

		month = m;
		day = d; // if all validation checks pass
		year = y;

		return true; // if all validation checks pass
	}

	void displayDateDash()
	{
		cout << month << "/" << day << "/" << year << endl; // display date in MM/DD/YYYY format
	}

	void displayDateMDY()
	{
		cout << monthName[month - 1] << " " << day << ", " << year << endl; // display date in Month DD, YYYY format
	}

	void displayDateDMY()
	{
		cout << day << " " << monthName[month - 1] << " " << year << endl; // display date in DD Month YYYY format
	}
};

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	Date date;
	int m, d, y;
	do{
		cout << " Please enter a valid date" << endl << endl; // prompt user to enter date, and adds to error message
		m = getIntegerData("Enter month: ");
		d = getIntegerData("Enter day: "); // get date from user
		y = getIntegerData("Enter year: ");
		cout << endl;
	}while (!date.setDate(m, d, y));
	cout << "----------------------------------------------"  << endl;
	cout << "\t\tFormatted Dates" << endl;
	cout << "----------------------------------------------"  << endl;
	cout << "\tFormat 1:\t"; // display date in all three formats
	date.displayDateDash(); // display date in MM/DD/YYYY format
	cout << "\tFormat 2:\t"; // display date in all three formats
	date.displayDateMDY(); // display date in Month DD, YYYY format
	cout << "\tFormat 3:\t"; // display date in all three formats
	date.displayDateDMY(); // display date in DD Month YYYY format
	
	cout << endl;
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
	cout << "Project #7" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives Use a struct to create a Date class that stores the month, day, and year. \n Can display the date in three formats: MM/DD/YYYY, Month DD, YYYY, and DD Month YYYY." << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #7" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


