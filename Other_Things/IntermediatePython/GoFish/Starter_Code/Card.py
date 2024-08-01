################################
# Card Class:
################################

# This class is meant to model a card object. In here put the relevant
# instance data for cards (i.e. maybe you need to track rank and suit).
# We should also include any methods that it might be useful to have 
# when interacting with card objects. One example might be an __eq__ method
# that we can use to tell if we chould treat two cards as equal. (Think of
# what it means for two cards to be equal in Go-Fish)
from PIL import Image

class Card(object):
    def __init__(self, card_rank, card_suit):
        self.rank = card_rank
        self.suit = card_suit
        self.image_file = str("cards/" + self.suit) + str(self.rank) + ".gif"
        self.card_image = Image.open(self.image_file)
    
    def getCardSuit(card_suit):
        if card_suit == 's':
            return 'Spades'
        elif card_suit == 'd':
            return 'Diamonds'
        elif card_suit == 'h':
            return 'Hearts'
        else:
            return 'Clubs'
    pass

    def getCardNum(card_num):
        card_num = str(card_num)
        if card_num == '1':
            return "Ace"
        elif card_num == '11':
            return "Jack"
        elif card_num == '12':
            return "Queen"
        elif card_num == '13':
            return "King"
        else:
            return card_num

