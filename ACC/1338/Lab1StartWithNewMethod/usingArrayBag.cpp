/*
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			6/7
Project #:		2
Status: 		Complete
Class:			COSC 1338
-------------------------------------------------------------------------
Objectives:  

Adding to the array bag ADT, using the code from the text book, which is attached to the assignment,  2 public methods.
1. A recursive method to find and return the smallest value in the array
2. A recursive method to find and return the largest value in the array

-------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void sampleProgramFunction(ArrayBag<int>& bag);
int findGreatestValueInArray(ArrayBag<int>& bag);
int findSmallestValueInArray(ArrayBag<int>& bag);

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;

	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8};
	
	// Add the initial values to the bag
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 10; i++)
	{
		bag.add(initialValues[i]);
	}  // end for
	int operation;
	int temp;
	int anoyance;
	while(true){
		cout << "\n\n Chose operation:\n\t 1: Add value \n\t 2: Remove value\n\t 3: Display bag\n\t 4: Find smallest value\n\t 5: Find largest value\n\t 6: End\n";
		cin >> operation;
		if (operation == 1){
			cout << "Add: ";
			cin >> temp;
			if (bag.contains(temp)){
			cout << "value already in bag";
			}
			else{
			bag.add(temp);
			}
		}
		else if (operation == 2){
			cout << "Remove: ";
			cin >> temp;
			bag.remove(temp);
		}
		else if (operation == 3){
			cout << "Bag is: " << bag[0];
			for (int i = 1; i < bag.getCurrentSize(); i++){
				cout << ", " << bag[i];
			}			
		}
		else if (operation == 4){
			cout << "The smallest value is " << findSmallestValueInArray(bag);
		}
		else if (operation == 5){
			cout << "The largest value is " << findGreatestValueInArray(bag);
		}
		else if (operation == 6){
			return 0;
		}
		else{
			if (anoyance == 0){
				cout << "That... that isn't an option. try a number 1-6 this time please.";
			}
			else if (anoyance == 1){
				cout << "Sorry, that also isn't valid. Try a number 1-6.";
			}
			else if (anoyance == 2){
				cout << "That isn't valid. Try a number 1-6";
			}
			else if (anoyance == 3){
				cout << "Are you doing this on purpose?. Use a number 1-6.";
			}
			else if (anoyance == 4){
				cout << "Chose. A. Number. One. Trough. Six.";
			}
			else if (anoyance == 5){
				cout << "I'm not tollerating this anymore. 1-6.";
			}
			else{
				cout << "Thats it. I'm chosing for you. I pick: 6";
				return 0;
			}
			anoyance ++;
		}
	}
   return 0;
}  // end main

/****************************************************************/
/* Function:   sampleProgramFunction
/* Inputs:     the array bag
/* Outputs:    none
/* Purpose:    This function exercises some of the bag methods
/****************************************************************/

void sampleProgramFunction(ArrayBag<int>& bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();
   
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end sampleProgramFunction

/****************************************************************/
/* Function:   findGreatestValueInArray
/* Inputs:     the array bag
/* Outputs:    the greatest value in the array
/* Purpose:    This function uses the FindGreatestValue in the ArrayBag
/****************************************************************/

int findGreatestValueInArray(ArrayBag<int>& bag)
{
	return bag.FindGreatestValue(0, bag.getCurrentSize() - 1);
}  // end findGreatestValueInArray

/****************************************************************/
/* Function:   findSmallestValueInArray
/* Inputs:     the array bag
/* Outputs:    the smallest value in the array
/* Purpose:    This function uses the FindSmallestValue in the ArrayBag
/****************************************************************/

int findSmallestValueInArray(ArrayBag<int>& bag)
{
	return bag.FindSmallestValue(0, bag.getCurrentSize() - 1);
}  // end findSmallestValueInArray
