from tkinter import *
from PIL import Image, ImageTk

CARD_WIDTH = 71
CARD_HEIGHT = 96    

class Card(object):

    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
        
        self.image_file = str('cards/' + self.suit) + str(self.rank) + '.gif'
        self.card_image = Image.open(self.image_file)

def createDeck(deck):
    suits = ['d', 'c', 'h', 's']
    for i in range(len(suits)):
        for j in range(1,14):
            card = Card(suits[i], j)
            card_image = ImageTk.PhotoImage(card.card_image)
            label = Label(canvas, image = card_image)
            label.image = card_image # VERY IMPORTANT
            # The card won't show if you don't have this line
            deck.append(label)

def printCards(deck):
    column = 0
    row = 0
    for card in deck:
        card.place(x=column * CARD_WIDTH, y=row*CARD_HEIGHT)
        column = column + 1
        if column == 13:
            column = 0
            row = row + 1

root = Tk()
canvas = Canvas(root, width=925, height=400)

deck = []
createDeck(deck)
printCards(deck)

canvas.pack()
root.mainloop()


