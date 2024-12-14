from typing import List

class Solution:
    def maximumBeauty(self, flowers: List[int], steps: int) -> int:
        max_flower = max(flowers)
        max_range = max_flower + steps * 2 + 2
        prefix_sum = [0] * max_range

        for flower in flowers:
            prefix_sum[flower] += 1
            if flower + steps * 2 + 1 < max_range:
                prefix_sum[flower + steps * 2 + 1] -= 1

        max_beauty = running_sum = 0

        for value in prefix_sum:
            running_sum += value
            if running_sum > max_beauty:
                max_beauty = running_sum

        return max_beauty
