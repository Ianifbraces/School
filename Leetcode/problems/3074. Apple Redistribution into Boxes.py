#https://leetcode.com/problems/apple-redistribution-into-boxes/description/
#Difficulty: easy
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse = True)
        total = sum(apple)
        boxes = 0
        for i, box in enumerate(capacity):
            boxes += box
            if boxes >= total:
                return i+1
            