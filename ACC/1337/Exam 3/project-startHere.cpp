/* 
-------------------------------------------------------------------------
Name:     		Ian
Date: 			9/16
Project #:		Exam 3 Project
Status: 		WIP
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:
Using the following struct, read and store file data from dictonary.txt.
then create a quiz for the user to take. The quiz will ask the user to
translate a word from english to spanish. The user will be given a score
based on the number of correct answers. The user will be given the option
to take another quiz. The program will keep track of the number of quizes
taken, the number of quizes passed, the number of quizes failed, and the
highest score. The program will display the quiz summary at the end of the
program. The program will also write the quiz summary to a file called
results.txt.

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

// Global decleration
const string dashes(40, '-');

struct question{
	string word;//english word
	string translated;//spanish word
};

int Quiz(question[], string, int); //function prototype for the quiz

int main()
{
	// Displays start of project 
	projectStart();
	
	// write your code below

	

	ifstream dictonary("dictonary.txt"); //opens the file dictonary.txt

	if (!dictonary.is_open()){//checks if the file is open
		cout << "Error: dictonary doesn't exsist\n";//if the file is not open, it will display this message
		return 1;//returns 1
	}//end of if (!dictonary.is_open())

	question questions[100];//creates an array of 100 questions

	 for (int i = 0; i < 100; i++){ //reads the file and stores the data in the array
		if (dictonary.eof()){//checks if the file is at the end
			break;//if the file is at the end, it will break out of the loop
		}//end of if (dictonary.eof())
		getline(dictonary, questions[i].word); //reads the english word
		getline(dictonary, questions[i].translated);//reads the spanish word
	
	}//end of for (int i = 0; i < 100; i++)

	dictonary.close();//closes the file


	string name = getStringData("Enter your name: "); //gets the name of the user

	ofstream file2("results.txt", ios::app);//opens the file results.txt
	file2 << "Name: " << name << endl;//writes the name of the user to the file
	file2.close();//closes the file

	int quiznum = 0;//quiz number
	int correct = 0;//number of passed quizs
	int failed = 0;//number of failed quizs
	int max = 0;//highest score
	int current = 0;//current score
	do{
		quiznum++;//increments the quiz number
		cout << dashes << endl;//displays dashes
		current = Quiz(questions, name, quiznum);//calls the quiz function
		if (current >= 80){//checks if the score is greater than or equal to 80
			correct++;//increments the number of passed quizs
		}
		else{
			failed++;//increments the number of failed quizs
		}
		if (current > max){//checks if the current score is greater than the highest score
			max = current;//sets the highest score to the current score
		}//end of if (current > max)
		cout << dashes << endl;
	} while (getCharData("Would you like to take another quiz? (Y/N) ") != 'N'); //asks the user if they would like to take another quiz

	cout << dashes << endl;
	
	// Displays the quiz summery
	cout << "Quiz summery" << endl;
	cout << "\tStudent Name: " << name << endl;
	cout << "\n\tNumber of Quizes " << endl;
	cout << "\t\tTotal Quizes: " << quiznum << endl;
	cout << "\t\tTotal Passed: " << correct << endl;
	cout << "\t\tTotal Failed: " << failed << endl;
	cout << "\t\tHighest Score: " << max << "%" << endl;

	ofstream file("results.txt", ios::app);
	//writes the quiz summery to the file
	file << "\nQuiz summery" << endl;
	cout << "\tStudent Name: " << name << endl;
	cout << "\n\tNumber of Quizes " << endl;
	cout << "\t\tTotal Quizes: " << quiznum << endl;
	cout << "\t\tTotal Passed: " << correct << endl;
	cout << "\t\tTotal Failed: " << failed << endl;
	cout << "\t\tHighest Score: " << max << "%" << endl;



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
			
			//cout << "\t\tError Message. Selection does not exist"  << endl;
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
			
		//cout << "\t\tError Message. ONLY integers"  << endl;
	} // end of while (true)
} // end of int getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value) || value < 0 || value > 10)
		{
			if (value < 0 || value > 10){
				cout << "\t\tError Message. Number must be between 0 and 10"  << endl;
			}
			else{
				cout << "\t\tError Message. Non numeric is entered"  << endl;
			}
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		return value;
		
		//cout << "\t\tError Message. ONLY integers"  << endl
			
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
	cout << dashes << endl;
	cout << "\tExam 3 Project " << endl;
	cout << "\tWritten by: Ian Korrub" << endl;
	cout << "\tDate: 9/17" << endl;
	cout << dashes  << endl;
	cout << "\t Allybaba POS" << endl;
	cout << dashes  << endl;
	cout << "\tProject Objectives Projct Objectives:" << endl;
	cout << "Using the following struct, read and store file data from dictonary.txt." << endl;
	cout << "then create a quiz for the user to take. The quiz will ask the user to" << endl;
	cout << "translate a word from english to spanish. The user will be given a score" << endl;
	cout << "based on the number of correct answers. The user will be given the option" << endl;
	cout << "to take another quiz. The program will keep track of the number of quizes" << endl;
	cout << "taken, the number of quizes passed, the number of quizes failed, and the" << endl;
	cout << "highest score. The program will display the quiz summary at the end of the" << endl;
	cout << "program. The program will also write the quiz summary to a file called" << endl;
	cout << "results.txt." << endl;
	cout << dashes  << endl;
	cout << "IMPORTANT: Please make sure to use upercase leters when inputing words,\nand if there is an empty propt, don't imput anything, thank you." << endl;
	cout << dashes  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << dashes  << endl;
	cout << "\tEnd of Exam 2 Project" << endl;
	cout << dashes << endl;
} // end of projectEnd()

//function to take the quiz
int Quiz(question answers[], string name, int quiznum){
	int score = 0;
	string question;
	int questions = getIntegerData("Maximum available words in the Quiz: 10 words.\nHow many questions would you like to be quizzed on? "); //gets the number of questions the user would like to be quizzed on
	cout << dashes << endl << "Quiz" << endl << dashes << endl;
	for (int i = 0; i < questions; i++){ //loops through the number of questions the user would like to be quizzed on
		cout << "Question " << i + 1 << endl; //displays the question number
		cin.ignore(120, '\n'); //clears the buffer
		question = getStringData("English word: to "); //gets the english word
		string answer;//gets the answer
		answer = getStringData("Your answer in Spanish: "); //gets the answer in spanish
		cout << "Result: "; //displays the result
		for (int j = 0; j < 101; j++){
			if (question == answers[j].word){
				if (answer == answers[j].translated){
					cout << "Correct!\n";
					score++;
				}
				else{
					cout << "Incorrect.\nThe correct answer is " << answers[j].translated << endl; // displays the correct answer
				}
				break;
			}
			if (j == 100){
				cout << "Question not in list.\n";
				i -= 1; //decrements the question number
			}
		}
		cout << dashes << endl;
	}

	//displays the quiz summary
	cout << "\nQuiz Summary" << endl;
	cout << "Name: " << name << endl;
	cout << "\t# of questions: " << questions << endl;
	cout << "\t# of correct answers: " << score << endl;
	cout << "\t# of incorrect answers: " << questions - score << endl;
	cout << "\tYout % grade: " << score * 100 / questions << "%" << endl;
	cout << "\tDecision: " << (score * 100 / questions >= 80 ? "Pass" : "Fail") << endl;
	//write to file
	ofstream file("results.txt", ios::app);
	file << "Quiz #" << quiznum << "\n\t# of questions: " << questions << "\n\t# of correct answers: " <<  score << "\n\t# of incorrect answers: " << questions - score << "\n\tYout % grade: " << score * 100 / questions << "%" << "\n\tDecision: " << (score * 100 / questions >= 80 ? "Pass" : "Fail") << endl; //writes the quiz summary to the file
	file.close();
	return score * 100 / questions; //returns the score
}//end of Quiz()
