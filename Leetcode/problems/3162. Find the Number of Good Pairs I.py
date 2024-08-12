# https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/
# Difficulty: easy
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        result = 0
        for num in nums1:
            for num2 in nums2:
                if num % (num2*k) == 0:# and num>num2:
                    print(num,num2)
                    result +=1
        return result