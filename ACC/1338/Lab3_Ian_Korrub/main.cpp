/*
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			7/13
Project #:		2
Status: 		Complete
Class:			COSC 1338
-------------------------------------------------------------------------
Objectives:  
Use a linked list to store a list of strings. Each string will have a 
category. It displays each category in alphabetical order, followed by 
the strings in that category.
-------------------------------------------------------------------------
*/

#include "Linked_list.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string fileName;
    cout << "Enter the name of the file: "; // gets name of file
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) { // checks if file is open
        cout << "Error: file not found" << endl;
        return 1;
    } // end if (!file.is_open())

    LinkedList list; // creates linked list
    string catagory; // creates category string
    int count = 0; // creates count variable
    for (string line; getline(file, line); ++count) { // gets line from file
        if (count % 2 == 0) { // checks if count is even
            catagory = line; // sets category to line
        } else { // if count is odd
            list.addNode(catagory, line); // adds node to list
        } // end if (count % 2 == 0)
    }
    file.close(); // closes file
    list.display(); // displays list

    return 0;
}
