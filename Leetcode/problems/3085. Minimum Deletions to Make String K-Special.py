#https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/
#Difficulty: medium
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:

        def deletions(num: int, res = 0)-> int:

            for v in vals:
                if v < num: res+= v
                if v > num+k: res+= v - num- k

            return res     
        

        vals = Counter(word).values()
        
        return min(map (deletions,vals))