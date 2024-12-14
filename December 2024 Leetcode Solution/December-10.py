class Solution:
    def maximumLength(self, s: str) -> int:
        def is_valid(s, n, x):
            freq = [0] * 26
            i = 0
            while i < n:
                j = i + 1
                while j < n and s[j] == s[i]:
                    j += 1
                freq[ord(s[i]) - ord('a')] += max(0, j - i - x + 1)
                if freq[ord(s[i]) - ord('a')] >= 3:
                    return True
                i = j
            return False
        
        n, l, r = len(s), 0, len(s)
        while l < r:
            mid = (l + r + 1) // 2
            if is_valid(s, n, mid):
                l = mid
            else:
                r = mid - 1
        return -1 if l == 0 else l
