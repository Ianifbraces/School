#https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/
# Difficulty: Medium
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        result = -float('inf')
        for start in range(k):
            tempres = 0
            for i in range(start,len(energy),k):
                if tempres < 0:
                    tempres = 0
                tempres += energy[i]
            result = max(result,tempres)
        return result