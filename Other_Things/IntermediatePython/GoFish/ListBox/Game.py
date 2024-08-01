################################
# Game:
################################

# This is where your game logic will reside. A game will have several instance 
# variables such as 2+ players, a deck of cards(possible modeled as a list 
# of Card objects), a status such as GAME_OVER or IN_PROGRESS (perhaps we 
# can model these as class variables and treat them like constants). It also 
# may be helpful to include some methods in this class to deal with animation
# so that it is easier to implement your game from within the SkeletonGraphics 
# framework.
from Hand import Hand
from Card import Card
from Player import Player
from tkinter import *
from random import *

    
COMPUTER_ROW = 0
PLAYER_ROW = 4
COMPUTER_TEXT_ROW = 150
PLAYER_TEXT_ROW = 325   
ONE_SECOND = 1000


class Game(object):

    def createPlayersAndHands(self, model, deck):
        p_hand = []
        c_hand = []

        for i in range(10):
            card = deck.pop(0)
            if i % 2 == 0:
                p_hand.append(card)
            else:
                c_hand.append(card)

        self.player = Player('Player', p_hand)
        self.computer = Player('Computer', c_hand)

    def printCardsToCanvas(self, canvas):
        c_points = self.computer.points
        p_points = self.player.points
        self.computer.hand.printHand(canvas, self.computer.name, COMPUTER_ROW, c_points, self.back_card)
        Hand.printDeck(canvas, self.deck, self.back_card)
        self.player.hand.printHand(canvas, self.player.name, PLAYER_ROW, p_points)

    def playerTurn(self, canvas, box, card_info):

        c_hand = self.computer.hand
        p_hand = self.player.hand
        deck = self.deck
        p_name = self.player.name
        player = self.player

        # Ask the computer for a card, check if it has the card, then computer responds
        askForCard(canvas, card_info, PLAYER_TEXT_ROW)

        player_move = p_name + " has asked for a " + Card.getCardNum(card_info[1:]) 
        box.insert(END, player_move)
        canvas.after(ONE_SECOND)

        computer_has_card = c_hand.checkForCard(card_info)
        self.opponentResponse(canvas, box, p_name, computer_has_card, card_info)
        canvas.after(ONE_SECOND)
        has_pairs = p_hand.checkForPairs(player, box)
        box.insert(END, '')
        return has_pairs

    def computerTurn(self, canvas, model):
        c_hand = self.computer.hand
        p_hand = self.player.hand
        deck = self.deck
        c_name = self.computer.name
        box = model.box # pass the listbox to add the order of turns
        computer = self.computer

        random_num = randint(0, len(c_hand.cards)-1)
        card_to_ask = c_hand.cards[random_num] 
        card_info = card_to_ask['text']

        askForCard(canvas, card_info, COMPUTER_TEXT_ROW)
        computer_move = c_name + ' has asked for a ' + Card.getCardNum(card_info[1:])
        box.insert(END, computer_move)
        canvas.after(ONE_SECOND)

        player_has_card = p_hand.checkForCard(card_info)
        self.opponentResponse(canvas, box, c_name, player_has_card, card_info)
        canvas.after(ONE_SECOND)
        has_pairs = c_hand.checkForPairs(computer, box)
        box.insert(END, '')
        return has_pairs

    def opponentResponse(self, canvas, box, name, has_card, card):
        response = None         # display this on Canvas
        response_text = None    # display this in ListBox

        opponent = 'Computer'
        opponent_hand = self.computer.hand
        p_hand = self.player.hand
        opponent_row = COMPUTER_TEXT_ROW

        if name == 'Computer':
            opponent = 'Player'
            opponent_hand = self.player.hand
            p_hand = self.computer.hand
            opponent_row = PLAYER_TEXT_ROW

        card_num = Card.getCardNum(card[1:])
        if has_card:
            response = canvas.create_text(300, opponent_row, font='Times 20',
                text='Yes I have a ' + card_num + ', here you go')
            response_text = "And " + opponent + " has it!"
        else:
            response = canvas.create_text(300, opponent_row, font='Times 20',
                text='No I don\'t have a ' + card_num + ', go fish')
            response_text = "But " + opponent + " didn't have it..."

        box.insert(END, response_text)
        canvas.update()
        waitAndDeleteMessage(canvas, response)

        if has_card:    
            p_hand.takeCard(box, name, card, opponent_hand)
        else:
            p_hand.drawCard(box, name, self.deck)
        canvas.after(50)
        canvas.update()

    def __init__(self):
        self.deck = []  # Tkinter labels to display on the screen
        self.back_card = None
        self.player = None
        self.computer = None

def askForCard(canvas, card, row):
    card_num = card[1:]
    card_name = Card.getCardNum(card_num)

    question = canvas.create_text(300, row, font='Times 20',
        text='Do you have a ' + card_name + "?")
    waitAndDeleteMessage(canvas, question)


# def opponentResponse(canvas, box, name, has_card, card, p_hand, opponent_hand, deck, row):
#     response = None         # display this on Canvas
#     response_text = None    # display this in ListBox
#     opponent = 'Player' if name == 'Computer' else 'Computer'
#     card_num = Card.getCardNum(card[1:])
#     if has_card:
#         response = canvas.create_text(300, row, font='Times 20',
#             text='Yes I have a ' + card_num + ', here you go')
#         response_text = "And " + opponent + " has it!"
#     else:
#         response = canvas.create_text(300, row, font='Times 20',
#             text='No I don\'t have a ' + card_num + ', go fish')
#         response_text = "But " + opponent + " didn't have it..."

#     box.insert(END, response_text)
#     canvas.update()
#     waitAndDeleteMessage(canvas, response)

#     if has_card:    
#         p_hand.takeCard(box, name, card, opponent_hand)
#     else:
#         p_hand.drawCard(box, name, deck)
#     canvas.after(50)
#     canvas.update()


def waitAndDeleteMessage(canvas, text):
    canvas.update()
    canvas.after(1500)
    canvas.delete(text)
    canvas.update()      



        

    # def addSevenCards(player):
    #     hand = player.hand.cards
    #     print("hand length in game: " + len(hand))
    #     for i in range(0, 7):
    #         if(len(deck) > 0):
    #             card = self.deck.pop(0)
    #             hand.append(card)
    #     print("hand length after sevenCards: " + len(hand))