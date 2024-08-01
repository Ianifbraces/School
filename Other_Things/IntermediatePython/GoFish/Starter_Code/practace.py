# Ensure PIL (Python Imaging Library) is installed. If not, install it via pip:
# pip install Pillow

from tkinter import *
from Card import Card
# Import Image and ImageTk modules correctly after ensuring Pillow is installed
from PIL import Image, ImageTk

card_width = 71
card_hieght = 96
deck = []
suits = ['d', 'h', 'c', 's']


root = Tk()
canvas = Canvas(root, width=925, height=400)

for suit in suits:
    for i in range(1, 14):
        card = Card(i, suit)
        image = ImageTk.PhotoImage(card.card_image)
        W = Label(canvas, image=image)
        W.image = image
        deck.append(W)

for j in range(13):
    for i in range(4):
        deck[i*13+j].pack()
        deck[i*13+j].place(x=j*card_width, y=i*card_hieght)
canvas.pack()
root.mainloop()