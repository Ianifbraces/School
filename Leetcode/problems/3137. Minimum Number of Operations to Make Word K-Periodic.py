#https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/
# Difficulty: midium
from collections import Counter
class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        #word += 'o'
        words = [word[i:i+k] for i in range(0,len(word),k)]
        counts = list(Counter(words).values())
        return sum(counts) - max(counts)