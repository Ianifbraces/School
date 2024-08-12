#https://leetcode.com/problems/maximize-happiness-of-selected-children/description/
# Difficulty: medium
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        
        happiness.sort(reverse = True)
        
        arr = list(enumerate(happiness[:k]))
 
        sm = sum(map(lambda x: max(x[1]-x[0], 0), arr))
        return sm