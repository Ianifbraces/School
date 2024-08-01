/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			7/19
Project #:		8
Status: 		Submitted
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
1.  Create a structure to store employee information
2.  Read employee information from a file
3.  Read transaction information from a file
4.  Calculate the gross pay, tax, insurance, and net pay for each employee
5.  Write the payroll report to a file
6.  Write the errors to a file
7.  Write the number of transactions processed correctly to a file
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

struct employee
{
	string name;// employee name
	int id;// employee id
	float hours;// number of hours worked
	float rate;// hourly rate
	int dependents; // number of dependents
	int type; // 0 for union, 1 for Management
	
	void setName(string n) {
		if (n.length() > 20){
			name = n.substr(0,20); // if the name is longer than 20 characters, only take the first 20
		}
		else{
			name = n;// if the name is less than 20 characters, take the whole name
		}
		}
	void setId(int i) {id = i;} // set the id
	void setHours(float h) {hours = h;}// set the hours
	void setRate(float r) {rate = r;}// set the rate
	void setDependents(int d) {dependents = d;}// set the dependents
	void setType(int t) {
		if (0<=type && type<=1){ // if the type is 0 or 1, set the type
			type = t;// set the type
		}
		else{
			type = -1;// if the type is not 0 or 1, set the type to -1
		}
	}
};

int findIndex(employee[], int, int, int);

int main() {
    // Displays start of project 
    projectStart();
    
    // START YOUR CODING BELOW
    employee emp[100];
    int errors[100] = {0}; // Initialize error array to 0
    int count = 0;
    ifstream inputFile("employee.txt");

    if (inputFile.fail()) { // if the file fails to open
        cout << "Error opening file" << endl; 
        return 0;
    } else {// if the file opens successfully
        string temp;
        while (getline(inputFile, temp, ' ')) { // while there is a space in the file
            emp[count].setId(stoi(temp)); // turn temp into an int and set it to the id
            getline(inputFile, temp, '?');
            emp[count].setName(temp); // set the name
            getline(inputFile, temp, ' '); 
            emp[count].setRate(stof(temp)); // Attempt to convert temp to float and set it to the rate
            getline(inputFile, temp, ' ');
            emp[count].setDependents(stoi(temp)); // turn temp into an int and set it to the dependents
            getline(inputFile, temp, '\n');
            emp[count].setType(stoi(temp)); // turn temp into an int and set it to the type
            count++; // increment count
            if (count >= 100) break; // prevent out-of-bounds access
        } // end of while (getline(inputFile, temp, ' '))
    } // end of else
    inputFile.close(); // close the file

    ifstream inputFile2("transaction.txt"); // open the transaction file
    
    if (inputFile2.fail()) {
        cout << "Error opening file" << endl;
        return 0;
    } else {
        ofstream outputFile("payrollReport.txt");

        outputFile << "----------------------------------------------" << endl;
        outputFile << "Payroll Report" << endl; // output
        outputFile << "----------------------------------------------" << endl;
        outputFile << "ID Name\t\t\t\tTax\t\t\tInsurance\tGross Pay\tNet Pay\n"; // header
        string temp;
        int empCount = 0;
        float totalGross = 0;
        float totalNet = 0;
        while (getline(inputFile2, temp, ' ')) {
            int id = stoi(temp); // convert temp to int and set it to id
            int index = findIndex(emp, 0, count, id); // find the index of the id
            if (index == -1) {
                errors[empCount] = id; // if the id is not found, add it to the errors array
            } else {
                getline(inputFile2, temp, '\n'); // get the hours
                emp[index].setHours(stof(temp)); // convert temp to float and set it to hours
				if (emp[index].hours <= -1) {// if the hours are less than 0, add the id to the errors array
					errors [empCount] = id;
					continue;
				}
                outputFile << setprecision(2) << emp[index].id << " " << emp[index].name << "\t\t"; // output
                int income = emp[index].hours * emp[index].rate; // calculate income
                if (emp[index].type == 0) {
                    income += (emp[index].hours - 40) * emp[index].rate * 0.5; // calculate income for union employees
                }
                outputFile << fixed << setprecision(2) << income * 0.15 << "\t\t" << emp[index].dependents * 30 << "\t\t\t" << income << "\t\t\t" << income * 0.85 - emp[index].dependents * 30 << "\n"; // output
                empCount++; // increment empCount
                totalGross += income; // add income to totalGross
                totalNet += income * 0.85 - emp[index].dependents * 30; // add net pay to totalNet
            }
        } // end of while (getline(inputFile2, temp, ' '))
        inputFile2.close();
        outputFile << "----------------------------------------------" << endl;    
        outputFile << "Number of Employees: " << empCount << endl; // output
        outputFile << "Total Gross Pay: " << totalGross << endl;    // output
        outputFile << "Total Net Pay: " << totalNet << endl;    // output
        outputFile << "\n----------------------------------------------" << endl;
        outputFile << "End of Project 8";
        outputFile.close();
        ofstream errorFile("errors.txt");
        errorFile << "----------------------------------------------" << endl;
        errorFile << "Errors" << endl;
        errorFile << "----------------------------------------------" << endl;
        errorFile << "The following items could not be processed\n";
        for (int i = 0; i < 100; i++) {
            if (errors[i] != 0) {
                errorFile << errors[i] << endl; // output
            }
        }
        errorFile << "----------------------------------------------" << endl;
        errorFile << "Number of transactions processed correctly: " << empCount << endl; // output
    } // end of else

    // Displays end of project
    projectEnd();
    
    return 0;
} // end of main



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
	cout << "Project #8" << endl;
	cout << "Written by: Ian Korrub" << endl;
	cout << "Objectives\n 1.  Create a structure to store employee information\n2.  Read employee information from a file\n3.  Read transaction information from a file\n4.  Calculate the gross pay, tax, insurance, and net pay for each employee\n5.  Write the payroll report to a file\n6.  Write the errors to a file\n7.  Write the number of transactions processed correctly to a file" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #8" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()

int findIndex(employee emp[], int start, int finish, int id)
{
	if (start +1 == finish)
	{
		if (emp[start].id == id)
		{
			return start;// return the index of the id
		}
		else
		{
			return -1;// return -1 if the id is not found
		}
	}
	else
	{
		int mid = (start + finish) / 2;
		if (emp[mid].id == id)
		{
			return mid; // return the index of the id
		}
		else if (emp[mid].id < id)
		{
			return findIndex(emp, mid+1, finish, id); // recursive call to search the right side
		}
		return findIndex(emp, start, mid, id);// recursive call to search the left side
		
	} 
}


