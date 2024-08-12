#https://leetcode.com/problems/special-array-i/description/
# Difficulty: Easy
class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        prev = 2
        for num in nums:
            if num % 2 == prev:
                return False
            prev = num%2
        return True