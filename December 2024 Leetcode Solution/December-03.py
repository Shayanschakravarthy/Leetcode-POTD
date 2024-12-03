class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        spaces.append(len(s))
        return ''.join(s[spaces[i - 1] if i > 0 else 0:spaces[i]] + (' ' if i < len(spaces) - 1 else '') for i in range(len(spaces)))

2)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        prev = 0
        
        for space in spaces:
            result.append(s[prev:space])
            result.append(" ")
            prev = space
        
        result.append(s[prev:])
        return ''.join(result)

3)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        n = len(s)
        result = []
        prev = 0
        spaces_idx = 0
        spaces_len = len(spaces)
        for i in range(n):
            if spaces_idx < spaces_len and i == spaces[spaces_idx]:
                result.append(" ")
                spaces_idx += 1
            result.append(s[i])
        
        return ''.join(result)

4)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        spaceIndex = 0
        for i in range(len(s)):
            if spaceIndex < len(spaces) and i == spaces[spaceIndex]:
                result.append(' ')
                spaceIndex += 1
            result.append(s[i])
        return ''.join(result)

5)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        space_index = 0

        for i, char in enumerate(s):
            if space_index < len(spaces) and i == spaces[space_index]:
                result.append(' ')
                space_index += 1
            result.append(char)

        return ''.join(result)
