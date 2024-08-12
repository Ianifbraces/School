#https://leetcode.com/problems/valid-word/submissions/
#difficulty: easy
import re
class Solution:
    def isValid(self, word: str) -> bool:
        if re.search('@|#',word) or '$' in word:
            print('#' in word)
            return False
        if len(word) >= 3:
            newword = ''.join(letter for letter in word if letter.isalpha())
            if re.search('a|A|e|E|i|I|o|O|u|U',newword):
                return len(list(letter for letter in newword if not letter in ['a','e','i','o','u','A','E','I',"O",'U'])) >= 1
        return False