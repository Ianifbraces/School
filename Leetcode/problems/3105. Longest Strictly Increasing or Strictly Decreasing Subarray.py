#https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
#difficulty: easy
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        result = 1
        for i in range(len(nums)-1):
            if len(nums) - i < result:
                break
            if nums[i] == nums[i+1]:
                continue
            tresult = 2
            if nums[i] < nums[i+1]:
                less = False
            else:
                less= True
            for j in range(i+2,len(nums)):
                if nums[j-1] < nums[j] and not less:
                    print(nums[i:j])
                    tresult += 1
                elif nums[j-1] > nums[j] and less:
                    print(nums[i:j])
                    tresult +=1
                else:
                    break
            result = max(result,tresult)
        return result