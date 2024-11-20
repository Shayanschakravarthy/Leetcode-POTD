class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = [0] * 3
        for c in s:
            cnt[ord(c) - ord('a')] += 1

        if cnt[0] < k or cnt[1] < k or cnt[2] < k:
            return -1

        mx = j = 0
        for i, c in enumerate(s):
            cnt[ord(c) - ord('a')] -= 1
            while cnt[0] < k or cnt[1] < k or cnt[2] < k:
                cnt[ord(s[j]) - ord('a')] += 1
                j += 1
            mx = max(mx, i - j + 1)
        
        return len(s) - mx 
