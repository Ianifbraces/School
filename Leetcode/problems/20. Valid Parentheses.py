#https://leetcode.com/problems/valid-parentheses/description/
# Difficulty: Easy
class Solution:
    def isValid(self, s: str) -> bool:
        unclosed = []
        opentoclose = {'(':')','[':']','{':'}'}
        for brac in s:
            if not brac in opentoclose:
                if len(unclosed) == 0:
                    return False
                if opentoclose[unclosed[-1]] == brac:
                    unclosed.pop()
                else:
                    return False
            else:
                unclosed.append(brac)
        if len(unclosed)==0:
            return True
        return False