#https://leetcode.com/problems/permutation-difference-between-two-strings/description/
# Difficulty: Easy
class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        result = 0
        s = list(s)
        t = list(t)
        for i, char in enumerate(s):
            result += abs(i - t.index(char))
        return result