#https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/
#Difficulty: easy
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        for i in range(len(s)-1):
            checkfor = (s[i:i+2])
            if checkfor in s[::-1]:            
                return True
        return False