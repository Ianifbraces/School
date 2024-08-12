#https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/
#Difficulty: medium
class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        result = s
        alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        for i,char in enumerate(s):
            if char == 'a':
                continue
            if min(len(alpha)-alpha.index(char),alpha.index(char)) <= k:
                k -= min((len(alpha)-alpha.index(char)),alpha.index(char))
                result = result[:i] + 'a' + result[i+1:]
            else:
                result = result[:i] + alpha[alpha.index(char)-k] + result[i+1:]
                return result
        return result