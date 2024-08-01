from tkinter import *

root = Tk()

frame = Frame(root)
vbar = Scrollbar(frame)
vbar.pack(side=RIGHT, fill=Y)
box = Listbox(frame, yscrollcommand=vbar.set)
vbar.config(command=box.yview)

for i in range(100):
	box.insert(END, 'This is line number ' + str(i))

box.pack()
frame.pack()
root.mainloop()

