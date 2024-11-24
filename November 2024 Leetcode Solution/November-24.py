class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum = sum(abs(value) for row in matrix for value in row)
        min_abs_value = min(abs(value) for row in matrix for value in row)
        negative_count = sum(1 for row in matrix for value in row if value < 0)
        
        return total_sum - (2 * min_abs_value if negative_count % 2 != 0 else 0)
