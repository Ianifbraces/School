#https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/
#Difficulty: medium
class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        mid = (len(nums)//2)
        counter = 0  
        if nums[mid] > k :
            for i in range(mid+1):
                if nums[i] > k:
                    counter += nums[i] - k
        else:
            for i in range(mid,len(nums)):
                if nums[i] < k:
                    counter += k - nums[i]
        return counter