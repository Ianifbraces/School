from tkinter import *
from PIL import Image, ImageTk

root = Tk()
canvas = Canvas(root, width=500, height=500)

d1_img_to_open = Image.open('cards/d1.gif')
d1_img = ImageTk.PhotoImage(d1_img_to_open)
d1 = Label(canvas, image=d1_img)


c1_img_to_open = Image.open('cards/c1.gif')
c1_img = ImageTk.PhotoImage(c1_img_to_open)
c1 = Label(canvas, image = c1_img)

h1_img_to_open = Image.open('cards/h1.gif')
h1_img = ImageTk.PhotoImage(h1_img_to_open)
h1 = Label(canvas, image = h1_img)

s1_img_to_open = Image.open('cards/s1.gif')
s1_img = ImageTk.PhotoImage(s1_img_to_open)
s1 = Label(canvas, image = s1_img)

d1.pack()
c1.pack()
h1.pack()
s1.pack()

d1.place(x=0,y=0)
c1.place(x=75,y=0)
h1.place(x=150,y=0)
s1.place(x=225,y=0)

canvas.pack()
root.mainloop()

