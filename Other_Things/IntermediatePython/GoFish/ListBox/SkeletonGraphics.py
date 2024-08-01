from tkinter import *
from Game import Game
from Card import Card
from Hand import Hand
from Player import Player
from PIL import Image, ImageTk
from random import shuffle

##################################
# put your customized code here
##################################

# intializes the data storage model at launch of application
def initialize(canvas, model, mainWindow):
    # put stuff in here that you want to happen at application launch
    
    model.game = Game()
    deck = model.game.deck 
    createDeck(deck, canvas)
    shuffle(deck)

    # create a blank card back object in game, used to setup computer back card
    # it's created here because it's too early to create it inside Game,py
    card_back_img = ImageTk.PhotoImage(Image.open('cards/x1.gif'))
    model.game.back_card = card_back_img


    # initialize player and computer hands
    model.game.createPlayersAndHands(model, deck)

    # model.game.player.hand.cards = []

    frame = Frame(mainWindow)
    vbar = Scrollbar(frame, orient=VERTICAL)
    vbar.pack(side=RIGHT, fill=Y)
    box = Listbox(frame, yscrollcommand=vbar.set, width=50, height=500)
    box.pack(side=RIGHT, fill=Y)
    vbar.config(command=box.yview)
    frame.pack(side=RIGHT)

    # auto-scroll text to the bottom
    # https://stackoverflow.com/questions/3699104/how-to-add-autoscroll-on-insert-in-tkinter-listbox

    model.box = box

# gets called whenever the mouse is pressed
def mousePressed(event, canvas, model):
    # put stuff in here that you want to happen when mouse is pressed

    # see what the computer has when we click on a card
    card = event.widget["text"]

    has_pairs = model.game.playerTurn(canvas, model.box, card)
    redraw(canvas,model)
    if has_pairs:
        return # stops the computer having its turn if player has_pairs
    computer_has_turn = True
    while(computer_has_turn):
        computer_has_turn = model.game.computerTurn(canvas, model)
        redraw(canvas,model)

    

 
# called at every tick of the timer to redraw/refresh the contents on screen
def redraw(canvas, model):
    # put your graphics/art/drawings in here, this will be constantly refreshed
    canvas.delete(ALL)
    model.game.printCardsToCanvas(canvas)
    canvas.update()

def createDeck(deck, canvas):
    suits = ['d', 'c', 'h', 's']
    for i in range(len(suits)):
        for j in range(1,14):
            card = Card(suits[i], j)
            card_image = ImageTk.PhotoImage(card.card_image)
            label = Label(canvas, image = card_image, text=suits[i]+str(j))
            label.image = card_image # VERY IMPORTANT
            # The card won't show if you don't have this line
            deck.append(label)







    







####################################################################
####################################################################
# don't change the code below this point!!!!!!
####################################################################
####################################################################


def run(width = 500, height = 500):
    #sets up an empty data structure to store arbitrary data
    class Struct(): pass

    # create the model to store your program runtime data
    model = Struct()
    # store the width and height of the window
    model.width = width
    model.height = height
    
    # create a main window and canvas
    mainWindow = Tk()
    canvas = Canvas(mainWindow, width = model.width, height = model.height)
    canvas.pack()

    # initialize your model to store the appropriate data at launch
    initialize(canvas, model, mainWindow)

    #####################################
    # wrapper functions to handle events
    #####################################

    def redrawWrapper(canvas, model):
        canvas.delete(ALL)  # delete the contents of the canvas
        redraw(canvas, model) # redraw the new conents
        canvas.update() # update the display

    def mousePressWrapper(event, canvas, model):
        mousePressed(event, canvas, model) # call mouse pressed function
        redrawWrapper(canvas, model) # use redraw to display any changes

    ################################################
    # bind events to wrappers using lambda functions
    ################################################

    #bind mouse pressed to the mousePressWrapper
    mainWindow.bind("<Button-1>", lambda event:
                            mousePressWrapper(event, canvas, model))

    # print the first part of the game
    redrawWrapper(canvas, model)

    # LAUNCH THE APPLICATION!!!
    mainWindow.mainloop()

run(1250) #optional: provide width and height arguments in the call to run





