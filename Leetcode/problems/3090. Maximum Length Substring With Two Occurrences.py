#https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
#Difficulty: easy
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        result = 1
        for j in range(len(s)-1):
            found = [s[j]]
            doubled = []
            maxx = 0
            for i in range(j+1,len(s)):
                if s[i] in doubled:
                    maxx = len(s[j:i])
                    break
                if s[i] in found:
                    doubled.append(s[i])
                found.append(s[i])
            if maxx == 0:
                maxx = len(s[j:i]) + 1
            result = max(result,maxx)
        return result