class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def canDivide(mx: int) -> bool:
            operations = 0
            for x in nums:
                operations += (x - 1) // mx
                if operations > maxOperations:
                    return False
            return True

        left, right = 1, max(nums)
        while left < right:
            mid = (left + right) // 2
            if canDivide(mid):
                right = mid
            else:
                left = mid + 1
        return left

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def canDivide(maxSize: int) -> bool:
            operations = sum((num - 1) // maxSize for num in nums)
            return operations <= maxOperations

        left, right = 1, max(nums)
        while left < right:
            mid = (left + right) // 2
            if canDivide(mid):
                right = mid
            else:
                left = mid + 1
        return left

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def canDivide(maxSize: int) -> bool:
            return sum((num - 1) // maxSize for num in nums) <= maxOperations

        left, right = 1, max(nums)
        while left < right:
            mid = left + (right - left) // 2
            if canDivide(mid):
                right = mid  
            else:
                left = mid + 1  
        return left

