/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		Exam 1 Project
Status: 		WIP
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:


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
	
	// write your code below

	int num1; 
	int num2;
	int num3;
	float temp;
	int points = 0;
	int questions = 0;
	srand(time(NULL));
	string name = getStringData("Enter student name: ");
	cout << "Arithmetic Quiz";
	while (true){
		char operation = getCharData("\n ------------------------------------------\n + Addition\n - Subtraction\n * Multiplication\n / Division\n % Modulus\n E Exit\n----------------------------------------- \n \t\tEnter your selection ");
		//displays menu and asks for input
		num1 = rand() % 20 +1;
		num2 = rand() % 20 +1;// finds 3 random numbers 1-20
		num3 = rand() % 20 +1;
		// Displays end of project
		cout << "\n\toperation\t";
		if (operation=='+'){ // displays what operation was selected
			cout << "Addition";
		}
		else if(operation =='-'){
			cout << "Subtraction";
		}
		else if (operation == '*'){
			cout << "Multiplication";
		}
		else if (operation == '/'){
			cout << "Division";
		}
		else if (operation == '%'){
			cout << "Modulus";
		}
		else if (operation == 'E'){
			cout << "End\n";
			break;
		}
		else{
			cout << "Invalid operation.";
			continue;
		}//end if else operation
		questions +=1;
		cout << "\n\n\tArithmetic Expression\t" <<  num1 << ' ' << operation << ' ' << num2 << ' ' << operation << ' ' << num3 << '\n';
		temp = getFloatData("\tEnter the answer\t");
		if (((operation=='+') && (num1 + num2 + num3 == temp))||((operation =='-')&&(num1 - num2 - num3 == temp))||((operation =='*')&&(num1 * num2 * num3 == temp))||((operation =='/')&&(num1 / num2 / num3 == temp))||((operation =='%')&&(num1 % num2 % num3 == temp))){
			// finds of the answer is corect
			cout << "\n\n\tCorect.";
			points += 1;
		}
		else{
			cout << "\n\n\tIncorect";
			cout << "\nCorect answer:";
			if (operation=='+'){
			cout << num1 + num2 + num3;
		}
		else if(operation =='-'){
			cout << num1 - num2 - num3;
		}
		else if (operation == '*'){
			cout << num1 * num2 * num3;
		}
		else if (operation == '/'){
			cout << num1 / num2 / num3;
		}
		else if (operation == '%'){
			cout << num1 % num2 % num3;
		}// end of find corect answer if statments
		}
	}// end of while true

	cout <<  "------------------------------------------";
	cout << "\n\tStudent name: " << name;
	cout << "\n\t\tNumber of quiz questions: " << questions;
	cout << "\n\t\tNumber of quiz points: " << points;
	cout << "\n\t\tGrade: " << points*100/questions << "%\n";

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
			
		return value;	
			
		cout << "\t\tError Message. ONLY integers"  << endl;
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
		
		cout << "\t\tError Message. ONLY integers"  << endl;
			
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
	cout << "-------------------------------------------------"  << endl;
	cout << "\tExam 1 Project " << endl;
	cout << "\tWritten by: Ian" << endl;
	cout << "\tDate: Jun 15th" << endl;
	cout << "-------------------------------------------------"  << endl;
	cout << "\t Allybaba Arithmetic Quiz" << endl;
	cout << "-------------------------------------------------"  << endl;
	cout << "\tProject Objectives" << endl;
	cout << "\t\t" << endl;
	cout << "\t " << endl;
	cout << "-------------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "-------------------------------------------------"  << endl;
	cout << "\tEnd of Exam 1 Project" << endl;
	cout << "-------------------------------------------------"  << endl;
} // end of projectEnd()


