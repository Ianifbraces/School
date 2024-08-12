#https://leetcode.com/problems/string-compression-iii/description/
# Difficulty: midium
class Solution:
    def compressedString(self, word: str) -> str:
        comp = ''
        prev = word[0]
        count = 1
        for i in range(1,len(word)):
            if word[i] != prev:
                #print(f'{prev},------------------->{count%9}<-------------------')
                if count >= 9:
                    for _ in range((count)//9):
                        comp+=f'9{prev}'
                if count%9!=0:
                    comp+=f'{count%9}{prev}'
                prev = word[i]
                count = 0
            count +=1
        if count >= 9:
            for _ in range((count)//9):
                comp+=f'9{prev}'
        if count%9!=0:
            comp+=f'{count%9}{prev}'
        return comp
        