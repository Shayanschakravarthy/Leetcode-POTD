from collections import deque
from typing import List

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        start = 0
        total_subarrays = 0
        max_deque, min_deque = deque(), deque()
        for end, num in enumerate(nums):
            while max_deque and nums[max_deque[-1]] <= num:
                max_deque.pop()
            max_deque.append(end)
            while min_deque and nums[min_deque[-1]] >= num:
                min_deque.pop()
            min_deque.append(end)
            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                if max_deque[0] == start:
                    max_deque.popleft()
                if min_deque[0] == start:
                    min_deque.popleft()
                start += 1
            total_subarrays += end - start + 1

        return total_subarrays
