#https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/
#Difficulty: easy
class Solution:
    def findLatestTime(self, s: str) -> str:
        s = list(s)
        if s[0] == '?':
            if s[1] == '?' or int(s[1]) <= 1:
                s[0] = '1'
            else:
                s[0] = '0'
        if s[3] == '?':
            s[3] = '5'
        if s[4] == '?':
            s[4] = '9'
        if s[1] =='?':
            if str(s) == '1?:59':
                return '12:00'
            if s[0] == '1':
                s[1] = '1'
            else:
                s[1] = '9'
        return "".join(s)