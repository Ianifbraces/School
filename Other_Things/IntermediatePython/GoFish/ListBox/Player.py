################################
# Player Class:
################################

# Every player will have several instance variables and many methods 
# associated with it. For example, every player has a hand, a name, 
# the ability to ask another player for a card, the ability to 'go fish', etc.
# This class should be able to nicely group these intance variables and methods 
# together. Make sure that you include an appropriate __init__ method so that
# you can properly create a new player object.


from Hand import Hand
class Player(object):
	def __init__(self, name, hand):
		self.name = name
		self.hand = Hand(hand)
		self.points = 0

	def increaseScore(self):
		self.points = self.points + 1
