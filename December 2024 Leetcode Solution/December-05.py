
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if start.replace('_', '') != target.replace('_', ''):
            return False
        
        n = len(start)
        i, j = 0, 0

        for i in range(n):
            if start[i] != '_':
                while target[j] == '_':
                    j += 1
                
                if (start[i] == 'L' and i < j) or (start[i] == 'R' and i > j):
                    return False
                
                j += 1

        return True
