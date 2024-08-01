/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			7/5/2023
Project #:		6
Status: 		Submitted
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives 
	• Create a structure to store student information
	• Create an array of structures
	• Use a loop to input data into the array of structures
	• Use a loop to display the data in the array of structures
	• Calculate the average of the exam scores for each student
	• Calculate the class average
	• Calculate the number of students who received each letter grade
	• Display the class average and the number of students who received each letter grade

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
	struct Student
	{
		string name;
		int exam1;
		int exam2;
		int exam3;
	};

	int studentcount = getIntegerData("How many sudents? "); //get number of students

	Student* Students = new Student[studentcount];

	for(int i = 0; i<studentcount; i++){
		cout << "Student #" << i+1 << endl;
		cout << "----------------------------------------------" << endl;
		Students[i].name = getStringData("Enter student name: ");
		do
		{
			Students[i].exam1 = getIntegerData("Enter exam 1 score: ");
			if (Students[i].exam1 > 110) //input validation
			{
				cout << "Error: Exam score must be between 0 and 110" << endl;
			} //end of if
		} while (Students[i].exam1 > 110);

		do
		{
			Students[i].exam2 = getIntegerData("Enter exam 2 score: ");
			if (Students[i].exam2 > 110)
			{
				cout << "Error: Exam score must be between 0 and 110" << endl;
			} //end of if
		} while (Students[i].exam2 > 110);
		
		do{
			Students[i].exam3 = getIntegerData("Enter exam 3 score: ");
			if (Students[i].exam3 > 110)
			{
				cout << "Error: Exam score must be between 0 and 110" << endl;
			} //end of if
		} while (Students[i].exam3 > 110);
		
	} //end of for loop
	cout << "\n----------------------------------------------\nSemester Summary: Ian Korrub Math Class\n----------------------------------------------" << endl;

	cout << "Student Name\tExam 1\tExam 2\tExam 3\tLetter Grade" << endl << "------------------------------------------------------" << endl;

	//counters for each grade
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int F = 0;
	float tavg;

	//loop to display individual student data
	for(int i = 0; i<studentcount; i++){
		float avg = (Students[i].exam1 + Students[i].exam2 + Students[i].exam3) / 3;
		char grade;
		//determine letter grade
		if(avg >= 90){
			grade = 'A';
			A ++;
		}else if(avg >= 80){
			grade = 'B';
			B ++;
		}else if(avg >= 70){
			grade = 'C';
			C ++;
		}else if(avg >= 60){
			grade = 'D';
			D ++;
		}else{
			grade = 'F';
			F ++;
		}//end of if else statement to determine letter grade
		//display student data
		cout << Students[i].name << "\t\t" << Students[i].exam1 << "\t" << Students[i].exam2 << "\t" << Students[i].exam3 << "\t" << grade << endl;
		tavg += avg; //total average
	}//end of for loop to display individual student data


	cout << "------------------------------------------------------" << endl;
	//display class summary
	cout << "number of students: " << studentcount << endl;
	cout << "Class average: " << tavg/studentcount << endl;
	cout << "Number of A’s:: " << A << endl;
	cout << "Number of B’s:: " << B << endl;
	cout << "Number of C’s:: " << C << endl;
	cout << "Number of D’s:: " << D << endl;
	cout << "Number of F’s:: " << F << endl;

	delete[] Students;
	
	
	
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
			cout << "\t\t\tError Message. Non numeric is entered or out of range"  << endl;
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
	cin.ignore(); // ignores the enter key (You forgot this line)
	getline(cin, value, '\n'); // accepts spaces in the entry
	
	return value;
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #6" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives 	• Create a structure to store student information\n	• Create an array of structures\n	• Use a loop to input data into the array of structures\n	• Use a loop to display the data in the array of structures\n	• Calculate the average of the exam scores for each student\n	• Calculate the class average\n	• Calculate the number of students who received each letter grad\n	• Display the class average and the number of students who received each letter grade" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #6" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


