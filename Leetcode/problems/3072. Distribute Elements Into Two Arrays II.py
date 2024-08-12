#https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/
#Difficulty: hard
from sortedcontainers import SortedList
class Solution:

    def greaterCount(self, a, val):
        #cnt = 0
        # Optimal Approach
        # Binary Search -> Upper bound
        low, high = 0, len(a)-1

        while low<=high:
            mid = (low+high)//2
            if a[mid]>val:
                high=mid-1
            else:
                low=mid+1

        return len(a)-low

    def resultArray(self, nums: List[int]) -> List[int]:
        a1, a2 = [nums[0]], [nums[1]]
        # for using in Binary Search
        arr1_s =SortedList([nums[0]])
        arr2_s = SortedList([nums[1]])

        for i in range(2, len(nums)):
            cnt1 = self.greaterCount(arr1_s, nums[i])
            cnt2 = self.greaterCount(arr2_s, nums[i])

            if cnt1 > cnt2:
                a1.append(nums[i])
                arr1_s.add(nums[i])
            elif cnt1 < cnt2:
                a2.append(nums[i])
                arr2_s.add(nums[i])
            else:
                if len(a1) > len(a2):
                    a2.append(nums[i])
                    arr2_s.add(nums[i])
                else:
                    a1.append(nums[i])
                    arr1_s.add(nums[i])

        return a1+a2