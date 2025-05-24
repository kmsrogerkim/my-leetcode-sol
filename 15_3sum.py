# Runtime: 370ms, 98.24%
# https://leetcode.com/problems/3sum/description/

from typing import *
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        print(nums)
        ans = []
        for i, n in enumerate(nums):
            if i > 0 and n == nums[i-1]:
                continue
            if n > 0:
                break
                # since array in sorted
        
            target = n * -1
            l = i + 1
            r = len(nums) - 1
            while (l < r):
                sum = nums[l] + nums[r]
                if sum < target:
                    l += 1
                elif sum > target:
                    r -= 1
                else:
                    ans.append([nums[l], nums[r], n])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        # to avoid duplicates
                        l += 1
        return ans
            
