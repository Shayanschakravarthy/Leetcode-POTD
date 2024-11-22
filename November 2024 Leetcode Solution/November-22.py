from collections import defaultdict
from typing import List

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        count = defaultdict(int)

        for row in matrix:
            row_key = tuple(row) if row[0] == 0 else tuple(1 - n for n in row)
            count[row_key] += 1

        return max(count.values()) 
