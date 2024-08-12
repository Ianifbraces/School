#https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/
#Difficulty: medium
class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        num = s.count(c)
        total = 0
        for i in range(num):
            total += i+1
        return total