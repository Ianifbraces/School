#https://leetcode.com/problems/length-of-last-word/description/
#Difficulty: easy
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.split()
        return len(s[-1])