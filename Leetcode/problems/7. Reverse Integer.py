#https://leetcode.com/problems/reverse-integer/description/
#Difficulty: medium
class Solution:
    def reverse(self, x: int) -> int:
        neg = False
        if x < 0:
            x = x*-1
            neg = True
        x = str(x)
        x = x[::-1]
        result = int(x)
        if neg:
            result = result *-1
        if result <= -2147483648 or result >= 2147483647:
            result = 0
        return result