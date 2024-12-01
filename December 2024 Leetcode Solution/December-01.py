# from typing import List

# class Solution:
#     def checkIfExist(self, arr: List[int]) -> bool:
#         arr.sort()  
        
#         for i, num in enumerate(arr):
#             target = num * 2
#             left = i + 1 if target >= 0 else 0
#             right = len(arr) - 1
            
#             while left <= right:
#                 mid = left + (right - left) // 2
#                 if arr[mid] == target:
#                     return True
#                 elif arr[mid] < target:
#                     left = mid + 1
#                 else:
#                     right = mid - 1
#         return False


from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        
        for num in arr:
            if num * 2 in seen:
                return True
            if num % 2 == 0 and num // 2 in seen:
                return True
            seen.add(num)
        
        return False
