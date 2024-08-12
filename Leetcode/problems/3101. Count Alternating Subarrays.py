#https://leetcode.com/problems/count-alternating-subarrays/description/
#Difficulty: medium
class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        result = 0 #len(nums)
        prev = -1
        i = 1
        for val in nums:
                print(result)
                if val == prev:
                    i=2
                    result += 1
                    prev = val
                    continue
                prev = val
                result += i
                i+=1
                
        return result