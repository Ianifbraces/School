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
from Player import Player
from Card import Card 
from Hand import Hand
from random import *

COMPUTER_ROW = 0
PLAYER_ROW = 4
ONE_SECOND = 1000
COMPUTER_TEXT_ROW = 150
PLAYER_TEXT_ROW = 325 


class Game(object):
   def __init__(self):
      self.player1 = None
      self.player2 = None
      self.deck = []
      self.back_card = None

   def createPlayersAndHand(self, deck):
      pHand = []
      cHand = []
      for i in range(5):
         pHand.append(deck.pop())
      for i in range(5):
         cHand.append(deck.pop())
      
      self.player1 = Player('Player', pHand)
      self.player2 = Player('Computer', cHand)

      
   def printCardsToCanvas(self, canvas):
      c_points = self.player2.score
      p_points = self.player1.score
      self.player2.hand.printHand(canvas, self.player2.name, COMPUTER_ROW ,c_points, self.back_card)
      Hand.printdeck(canvas, self.deck, self.back_card)
      self.player1.hand.printHand(canvas, self.player1.name, PLAYER_ROW ,p_points)
   
   
   
   def playerTurn(self, canvas, model, card_info):
      c_hand = self.player2.hand
      p_hand = self.player1.hand

      self.checkHand(p_hand, canvas)
      
      deck = self.deck
      p_name = self.player1.name
      player = self.player1

      askForCard(canvas, card_info, PLAYER_TEXT_ROW)

      canvas.after(ONE_SECOND)

      opponent_has_card = c_hand.checkForCard(card_info)

      self.opponentResponse(canvas, p_name, opponent_has_card, card_info)
      somethingrandom = p_hand.checkForPairs(player, canvas)

      self.checkHand(p_hand, canvas)
      self.checkWinner(canvas)
      
      return somethingrandom

   def opponentResponse(self, canvas, name, has_card, card_info):
      response = None
      opponent = "Computer"
      opponent_hand = self.player2.hand
      p_hand = self.player1.hand
      opponent_row = COMPUTER_TEXT_ROW

      if name == "Computer":
         opponent_row = PLAYER_TEXT_ROW
         opponent = "Player"
         opponent_hand = self.player1.hand
         p_hand = self.player2.hand

      card_num = Card.getCardNum(card_info[1:])
      if has_card:
         response = canvas.create_text(300, opponent_row, font='Times 20',
            text = "Yes I have a " + card_num + ", here you go.")
      else:
         response = canvas.create_text(300, opponent_row, font='Times 20',
            text = "No I don't have a " + card_num + ", go fish.")
      waitAndDeleteMessage(canvas,response)
      if has_card:
         p_hand.takeCard(card_info, opponent_hand, name)
      else:
         p_hand.drawCard(self.deck, name)


   def computerTurn(self, canvas, model):
      c_hand = self.player2.hand
      self.checkHand(c_hand, canvas)
      if len(c_hand.cards) == 0:
         waitAndDeleteMessage(canvas, canvas.create_text(300, COMPUTER_TEXT_ROW, font='Times 20', text='I\'m out of cards'))
         canvas.after(ONE_SECOND)
         c_hand.draw7Cards(self.deck, 'Computer')
         return False
      p_hand = self.player1.hand
      deck = self.deck
      c_name = self.player2.name
      computer = self.player2

      card = c_hand.cards[randint(0, len(c_hand.cards)-1)]
      card_info = card['text']
      askForCard(canvas, card_info, COMPUTER_TEXT_ROW)
      canvas.after(ONE_SECOND)
      opponent_has_card = p_hand.checkForCard(card_info)
      self.opponentResponse(canvas, c_name, opponent_has_card, card_info)
      somethingrandom = c_hand.checkForPairs(computer, canvas)
      self.checkWinner(canvas)
      self.checkHand(c_hand, canvas)
      return somethingrandom
   
   def checkHand(self, hand, canvas):
      if len(hand.cards) == 0:
         waitAndDeleteMessage(canvas, canvas.create_text(300, COMPUTER_TEXT_ROW, font='Times 20', text='I\'m out of cards'))
         canvas.after(ONE_SECOND)
         hand.draw7Cards(self.deck, 'Computer')
   
   def checkWinner(self, Canvas):
      P_cards = self.player1.hand.cards
      P_name = self.player1.name
      P_score = self.player1.score
      C_cards = self.player2.hand.cards
      C_name = self.player2.name
      C_score = self.player2.score

      if len(P_cards) == 0 and len(C_cards) == 0 and len(self.deck) == 0:
         if P_score > C_score:
            Canvas.create_text(300, PLAYER_TEXT_ROW, font='Times 30', text='Player wins!')
         elif C_score > P_score:
            Canvas.create_text(300, COMPUTER_TEXT_ROW, font='Times 30', text='Computer wins!')
         else:
            Canvas.create_text(300, (COMPUTER_TEXT_ROW + PLAYER_TEXT_ROW)/2, font='Times 30', text='Tie Game!')
         Canvas.after(10000)

      


def askForCard(canvas, card_info, row):
   card_num = card_info[1:]
   card_name = Card.getCardNum(card_num)

   question = canvas.create_text(300, row, font='Times 20', text='Do you have any ' + card_name + '?')
   waitAndDeleteMessage(canvas,question)


def waitAndDeleteMessage(canvas,text):
   canvas.update()
   canvas.after(1500)
   canvas.delete(text)
   canvas.update()

