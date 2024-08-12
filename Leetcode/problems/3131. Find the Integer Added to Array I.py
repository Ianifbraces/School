#https://leetcode.com/problems/find-the-integer-added-to-array-i/description/
#difficulty: easy
class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        diff = sum(nums2) - sum(nums1)
        return int(diff/len(nums1))