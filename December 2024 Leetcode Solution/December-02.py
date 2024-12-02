class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, word in enumerate(sentence.split(), 1):
            if word.startswith(searchWord):  
                return i
        return -1  

2)
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        word_index = 1
        i = 0
        n = len(sentence)
        m = len(searchWord)
        
        while i < n:
            if sentence[i:i + m] == searchWord and (i == 0 or sentence[i - 1] == ' '):
                return word_index
            
            while i < n and sentence[i] != ' ':
                i += 1
            word_index += 1
            i += 1  
        
        return -1
