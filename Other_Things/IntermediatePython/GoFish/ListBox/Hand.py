################################
# Hand Class:
################################

# This class will be useful as it can serve as a data structure to group
# each of a players cards together into one hand object. Think about the
# instance variables you will need to implement this class. For example,
# it would make sense to treat a hand as a list of Card objects. We also
# might need to know the size of the hand. Do we need an instance variable
# for this or would that be redundant information? Why or why not? Also,
# make sure to consider writing methods for the various actions that it may
# make sense to do with a hand.
from tkinter import *
from Card import Card
from PIL import Image, ImageTk
import Game

OFFSET = 75
CARD_HEIGHT = 96
CARD_STACK_NUMBER = 25

def setCardFront(card):
    card_img_string = 'cards/' + card['text'] + '.gif'
    img = ImageTk.PhotoImage(Image.open(card_img_string))
    card.configure(image=img)
    card.image = img # prevents the garbage collector from sweeping the img away

class Hand(object):

    # prints the player hands everytime we redraw the canvas
    def printHand(self, canvas, name, row, points, back_card = ''): 
        column = 0
        for card in self.cards:
            card.place(x = OFFSET + column * CARD_STACK_NUMBER, y = row * CARD_HEIGHT)
            card.lift()
            column = column + 1
            print(card['text'])
            if back_card != '':
                card.configure(image=back_card)
                card.image = back_card
        print()
        canvas.create_text(250 + column*25,  row * 96 + 50, font='Times 20', text=name + ' Score: ' + str(points))

    def printDeck(canvas, deck, back_card):
        column = 0
        for card in deck:
            card.configure(image=back_card)
            card.image = back_card
            card.place(x = 75 + column * 10, y=192)
            card.lower()
            column = column + 1

    # checks a player hand for a specific card
    def checkForCard(self, player_card_name):
        for card in self.cards:         
            this_card_rank = card["text"][1:]
            other_card_rank = player_card_name[1:]
            # print("This: " + this_card_rank + ", Other: " + other_card_rank)
            if this_card_rank == other_card_rank:
                return True
        return False


    # take the card from one player, give it to the other
    def takeCard(self, box, player_name, card_name, opponent_hand):
        # i = 0
        # cards_to_remove = []       

        # # checks what cards the computer has, adds them to cards_to_remove if right card
        # for c in opponent_hand.cards:   
        #     if card_name[1:] == c["text"][1:]:
        #         cards_to_remove.append(c)

        # # remove the cards from computer, put them in player, and change them to front-facing cards
        # for c in cards_to_remove:
        #     setCardFront(c) 
        #     opponent_hand.cards.remove(c)
        #     self.cards.append(c)
        #     rank = Card.getCardNum(c['text'][1:])
        #     suit = Card.getCardSuit(c['text'][:1])
        #     box.insert(END, player_name + " has taken " + rank + " of " + suit) 
        for card in opponent_hand.cards[::-1]:  # go in reverse order 
            if card_name[1:] == card['text'][1:]:
                opponent_hand.cards.remove(card)
                setCardFront(card)
                self.cards.append(card)
                rank = Card.getCardNum(card['text'][1:])
                suit = Card.getCardSuit(card['text'][:1])
                box.insert(END, player_name + " has taken " + rank + " of " + suit) 

    def drawCard(self, box, player_name, deck):
        card = deck.pop(0)
        self.cards.append(card)
        card_info = "a card"
        if player_name == "Player":
            rank = Card.getCardNum(card['text'][1:])
            suit = Card.getCardSuit(card['text'][:1])
            card_info = rank + " of " + suit
            card_image = ImageTk.PhotoImage(Image.open('cards/' + card['text'] + '.gif'))
            print('cards/' + card['text'] + '.gif')
            card.configure(image=card_image)
            card.image = card_image
        box.insert(END, player_name + " has drawn " + card_info)

    

    def checkForPairs(self, player, box):
        has_pairs = False
        hand = self.cards
        hand_length = len(hand)
        cards_to_remove = []
        indexes_to_remove = []

        for i in range(hand_length - 1):
            card1 = hand[i]['text']
            card1_num = card1[1:]
            for j in range(i+1, hand_length):
                card2 = hand[j]['text']
                card2_num = card2[1:]
                if card1_num == card2_num and card1 not in cards_to_remove and card2 not in cards_to_remove:
                    cards_to_remove.append(card1)
                    cards_to_remove.append(card2)
                    indexes_to_remove.append(i)
                    indexes_to_remove.append(j)
                    # prints out the card info
                    card1_info = Card.getCardNum(card1[1:]) + ' of ' + Card.getCardSuit(card1[1])
                    card2_info = Card.getCardNum(card2[1:]) + ' of ' + Card.getCardSuit(card2[:1])
                    message = player.name + ' has matched ' + card1_info + ' and ' + card2_info
                    box.insert(END, message)
        # removes pairs from hand
        print('cards_to_remove: ' + str(cards_to_remove))
        indexes_to_remove.sort()

        for i in range(len(indexes_to_remove)-1, -1, -1):
            popped_card = hand.pop(indexes_to_remove[i])
            popped_card.destroy() # removes the card from the screen 

            if i % 2 == 0: # increment once for 2 cards
                player.increaseScore()
                has_pairs = True

        #checkIfNoMoreCards(player)
        return has_pairs

   
    def __init__(self, hand):
        self.cards = hand
        
# def checkIfNoMoreCards(player):
#         if len(player.hand.cards) == 0:
#             Game.addSevenCards(player)