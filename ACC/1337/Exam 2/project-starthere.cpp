/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			7/5/2023
Exam #:		    2
Status: 		Submitted
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives 
1.  Create a program that simulates a Point of Sale (POS) system for a grocery store.
2.  The program will read the menu items and prices from a file named Menu.txt.
3.  The program will allow the user to select items from the menu and enter the weight of the items.
4.  The program will calculate the total cost of the items selected.
5.  The program will display the total cost of the items selected.
6.  The program will display the daily sales transaction summary.
-------------------------------------------------------------------------
*/



#include <iostream> // for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> // for toupper()
#include <cstdlib> // for random numbers
#include <fstream> // includes filestream header
#include <cmath>

using namespace std;

// Declaration of prototype functions
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
int getItem(string[], float[], int);
void displayList(string[], float[], int[], int);

// Global constants
const string dashes(40, '-');
const float salesTax = 8.25; // percent

int main()
{
    // Displays start of project 
    projectStart();

    // Variable declarations
    ifstream file;

    // String lists
    string menu[25];
    string order[25];
    string allOrders[75];

    // float lists
    float price[25];
    float orderprice[25];
    float allOrdersPrice[75];

    // int lists
    int orderweight[25];
    int allOrderweight[75];

    //ints
    int result;
    int ordercount = 0;
    int allOrdercount = 0;

    //floats
    float ordercost = 0;
    float totalcost = 0;

    // Check if Menu.txt file can be opened
    file.open("Menu.txt");

    if (!file) {
        cout << "File not found" << endl;
        return 0;
    }

    // Read menu items and prices from file
    int length = 0;
    while (file >> menu[length] >> price[length]) {
        length++;
    }
    file.close();

    // Main loop for shopping
    while (true) {
        cout << "Main Menu" << endl;
        cout << "\n S - Shop";
        cout << "\n Q - Quit";
        cout << "\n" << endl;
        cout << dashes << endl;

        // Get user selection
        result = getCharData("Enter your selection: ");

        if (result == 'Q') {
            cout << "Total Cost: $" << fixed << setprecision(2) << totalcost << endl;
            break;
        }

        // Reset order variables
        ordercost = 0;
        ordercount = 0;
        for (int i = 0; i < 25; i++) {
            order[i] = "";
            orderprice[i] = 0;
            orderweight[i] = 0;
        }

        // Loop to handle individual item selection
        do {
            int itemIndex = getItem(menu, price, length);
            if (itemIndex == -1) { // Complete transaction
                cout << "Transaction Completed" << endl;
                cout << dashes << endl;
                displayList(order, orderprice, orderweight, ordercount);
                totalcost += ordercost;
                for (int i = 0; i < ordercount; i++) { // Add order to all orders
                    allOrders[allOrdercount] = order[i];
                    allOrdersPrice[allOrdercount] = orderprice[i];
                    allOrderweight[allOrdercount] = orderweight[i];
                    allOrdercount++;
                }
                break;
            
            } else if (itemIndex == -2) {
                cout << "Transaction Cancelled" << endl; // transaction cancelled
                break;
            
            } else if (itemIndex < 0 || itemIndex >= length+1) {
                cout << "Invalid selection" << endl; // Invalid selection
            
            } else { // Add item to order
                int pound = getIntegerData("Pounds of " + menu[itemIndex - 1] + ": ");
                ordercost += price[itemIndex - 1] * pound;
                order[ordercount] = menu[itemIndex - 1];
                orderprice[ordercount] = price[itemIndex - 1] * pound;
                orderweight[ordercount] = pound;
                ordercount++;
                cout << "Selected Item: " << menu[itemIndex - 1] << " Price: $" << fixed << setprecision(2) << price[itemIndex - 1] * pound << endl;
            }
        } while (true);

        // Prompt user to press Enter to continue
        cout << "Press Enter to continue";
        cin.ignore();
        cin.get();
        cout << dashes << endl;
    }

    // Display daily sales transaction summary
    cout << "Daily Sales Transaction Summary" << endl;
    cout << dashes << endl << endl;
    displayList(allOrders, allOrdersPrice, allOrderweight, allOrdercount); // Display all orders

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
            cout << "\t\tError Message. Non numeric is entered" << endl;
            cin.clear(); // clear error buffer
            cin.ignore(120, '\n'); // clear up to 120 chars or it reaches an enter
            cout << prompt;
        } // 	while (!(cin >> value))
        return value;
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
            cout << "\t\t\tError Message. Non numeric is entered" << endl;
            cin.clear(); // clear error buffer
            cin.ignore(120, '\n'); // clear up to 120 chars or it reaches an enter
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
    cin.ignore(); // Clear the input buffer
    getline(cin, value); // accepts spaces in the entry
    return value;
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
    cout << dashes << endl;
    cout << "\tExam 2 Project " << endl;
    cout << "\tWritten by: Ian Korrub" << endl;
    cout << "\tDate: 7/6" << endl;
    cout << dashes << endl;
    cout << "\t Allybaba POS" << endl;
    cout << dashes << endl;
    cout << "\tProject Objectives" << endl;
    cout << "\t\t" << endl;
    cout << "\t " << endl;
    cout << dashes << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
    cout << dashes << endl;
    cout << "\tEnd of Exam 2 Project" << endl;
    cout << dashes << endl;
} // end of projectEnd()

// This function will display the menu items, then ask the user to select an item
int getItem(string menu[], float price[], int length)
{
    for (int food = 0; food < length; food++) {
        // Display the menu items with two decimal places
        cout << food + 1 << ". " << menu[food] << "\t($" << fixed << setprecision(2) << price[food] << ")" << endl;
    }
    cout << endl;
    cout << "T Complete Transaction\nX Cancel Transaction" << endl;

    char temp = getCharData("Enter your selection: ");
    if (temp == 'T') { // Complete transaction
        return -1;
    } else if (temp == 'X') { // Cancel transaction
        return -2;
    } else if (temp >= '1' && temp <= '0' + length) { // Valid selection
        return temp - '0'; // Convert character to integer index
    } else {
        cout << "Invalid selection" << endl;
        return getItem(menu, price, length); // Retry on invalid selection
    }
}

// This function will display the list of ordered items and calculate totals
void displayList(string order[], float orderprice[], int orderweight[], int ordercount)
{
    cout << "Grocery Items" << endl;
    float total = 0;
    for (int i = 0; i < ordercount; i++) { // Display each item in the order
        cout << order[i] << "\t" << orderweight[i] << "lbs\t$" << fixed << setprecision(2) << orderprice[i] << endl;
        total += orderprice[i];
    }
    cout << dashes << endl;
    cout << "Sub Total\t$" << fixed << setprecision(2) << total << endl;
    cout << "Tax\t\t$" << fixed << setprecision(2) << total * salesTax / 100 << endl; // Calculate tax
    cout << dashes << endl;
    cout << "Total\t\t$" << fixed << setprecision(2) << total * (1 + salesTax / 100) << endl;
}
