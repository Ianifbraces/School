#https://leetcode.com/problems/harshad-number/description/
#Difficulty: easy
class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        sumx = 0
        for num in str(x):
            sumx += int(num)
        if x/sumx == int(x/sumx):
            return sumx
        return -1