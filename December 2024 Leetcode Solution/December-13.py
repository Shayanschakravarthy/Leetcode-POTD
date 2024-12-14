class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [False] * n
        indexed_nums = sorted((x, i) for i, x in enumerate(nums))  
        ans = 0

        for x, i in indexed_nums:
            if not vis[i]: 
                ans += x
                vis[i] = True
                if i - 1 >= 0:  
                    vis[i - 1] = True
                if i + 1 < n: 
                    vis[i + 1] = True

        return ans
