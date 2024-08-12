#https://leetcode.com/problems/maximum-prime-difference/description/
#Difficulty: medium
def is_prime(number):
    if number <= 1:
        return False
    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False
    return True
class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        Lprime = False
        Rprime = False
        for _ in range(len(nums)+1):
            if not Lprime:
                if is_prime(nums[left]):
                    Lprime = True
                else:
                    left += 1
            if not Rprime:
                if is_prime(nums[right]):
                    Rprime = True
                else:
                    right -= 1
            if Rprime and Lprime:
                return right - left