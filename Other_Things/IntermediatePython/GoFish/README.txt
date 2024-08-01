This game is a significant logical and graphical programming challenge that is intended to be completed over the course of three lessons as a sort of capstone for the class. It is a good final step because it covers essentially all of the main topics covered in this course in a way that will ultimately be engaging for the students.

Included in the starter code is a folder containing images for all 52 cards, as well as several classes in their own .py files with a description of how I envision them working. Ultimately, I envision an object oriented hierarchy that looks something like the following:

Game Object: contains several Player objects
Player Object: contains a Hand Object
Hand Object: contains several Card objects

The different actions that can happen in a game of Go-Fish can be modeled as methods in the appropriate class.

Also included is the SkeletonGraphics framework which provides a simplified way for students to interact with graphical applications without too much time being spent on setting up the backbone of the application.

To run the game, use the terminal to navigate to the folder containing SkeletonGraphics.py. Then run 'python 3 SkeletonGraphics.py' in the terminal and it should run. 

If they finish early, I have included some partial code to include a listbox, which will record all the 
player turns, who matched what cards, and if a player drew or took a card. It's located in the ListBox code. 
All you have to do is look for where 'box' is being used, and incorporate that into the student's code.
