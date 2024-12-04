class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        j, m = 0, len(str2)
        for c in str1:
            if j < m and (c == str2[j] or chr((ord(c) - ord('a') + 1) % 26 + ord('a')) == str2[j]):
                j += 1
                if j == m:
                    return True
        return j == m
