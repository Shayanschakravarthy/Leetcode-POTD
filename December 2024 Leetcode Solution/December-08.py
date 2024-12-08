from bisect import bisect_right
from typing import List

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        max_values = [0] * n
        max_values[-1] = events[-1][2]

        for i in range(n - 2, -1, -1):
            max_values[i] = max(max_values[i + 1], events[i][2])

        start_times = [event[0] for event in events]
        max_result = 0

        for start, end, value in events:
            idx = bisect_right(start_times, end)
            if idx < n:
                value += max_values[idx]
            max_result = max(max_result, value)

        return max_result
