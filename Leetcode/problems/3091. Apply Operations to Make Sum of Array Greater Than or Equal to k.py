#https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/
#Difficulty: medium
class Solution:
    def minOperations(self, k: int) -> int:
        while True:
            #if k == 1:
             #   return 0
            for i in range(1,k//2+2):
                if k/i == i or k/i-1 == i:
                    return int(i+k/i-2)
            k += 1