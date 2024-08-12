# https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/
# Dificulty: Hard

class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        from math import comb
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        a, b = 0, nums[0]
        arr1 = [a]
        arr2 = [b]
        for i in nums[1:]:
            # min a possible
            a = max(a, i - b)
            b = i - a
            arr1.append(a)
            arr2.append(b)
        # probablity question
        # bars and stars
        # we have to convert 5, 5, 5, 5 to 0, 0, 0, 0 in the end
        # xi can be {0, 1, 2, 3, 4, 5}
        # to find the number of times xi appears is the problem
        # x0 + x1 + x2 + x3 + x4 + x5 = 4
        
        # number of bars = 5
        # number of stars = 4
        # 9 choose 4 
        arr_2_min = min(arr2)
        if arr_2_min < 0:
            return 0
        res = comb(arr_2_min + len(arr2), len(arr2))
        
        return res % MOD
