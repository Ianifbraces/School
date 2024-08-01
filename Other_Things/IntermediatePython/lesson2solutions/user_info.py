from tkinter import *
from tkinter import messagebox
def showInfo():
	name = username.get()
	pword = password.get()
	mail = email.get()
	theAge = age.get()
	label.config(text = "Username: " + name + "\nPassword: " + pword + 
		"\nEmail: " + mail + "\nAge: " + theAge)
root = Tk()
usernameLabel = Label(root, text="Username")
usernameLabel.pack()
username = Entry(root, bd=2)
username.pack()

passwordLabel = Label(root, text="Password")
passwordLabel.pack()
password = Entry(root, bd=2, show="*")
password.pack()

emailLabel = Label(root, text="Email")
emailLabel.pack()
email = Entry(root, bd=2)
email.pack()

ageLabel = Label(root, text="Age")
ageLabel.pack()
age = Entry(root, bd=2)
age.pack()

button = Button(root, text="Display User Info", command=showInfo)
button.pack()

label = Label(root)
label.pack()
root.mainloop()	

