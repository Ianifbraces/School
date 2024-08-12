#https://leetcode.com/problems/longest-common-suffix-queries/description/
#Difficulty: hard
class Solution:
    class Node:
        def __init__(self):
            self.nxt = {}
            self.larger = ('$',10**9)
            
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        
        wordsContainer = [word[::-1] for word in wordsContainer]
        wordsQuery = [word[::-1] for word in wordsQuery]
        
        n = len(wordsQuery)
        trie = [self.Node()]
        
        def createNode(id,c):
            trie[id].nxt[c] = len(trie)
            trie.append(self.Node())
            
        
        def addWord(s,id):
            u = 0 
            for i in range(len(s)):
                c = s[i]
                if c not in trie[u].nxt:
                    createNode(u,c)
                u = trie[u].nxt[c]
                
                                    
                if(len(s)<len(trie[u].larger[0])) or trie[u].larger[0] == '$':
                    trie[u].larger = (s,id)
        
                if len(s) == len(trie[u].larger[0]) and id < trie[u].larger[1]:
                    trie[u].larger = (s.id)
                    
                    
        default = 0
        for i,word in enumerate(wordsContainer):
            addWord(word,i)
            
            if len(word)<len(wordsContainer[default]):
                default = i
    
        ans = [default]*n
        
        print(default)
        for id,word in enumerate(wordsQuery):
            u = 0 
            for i in range(len(word)):
                c = word[i]
                if c not in trie[u].nxt: 
                    break
                u = trie[u].nxt[c]
                
                ans[id] = trie[u].larger[1]
                
        return ans
        