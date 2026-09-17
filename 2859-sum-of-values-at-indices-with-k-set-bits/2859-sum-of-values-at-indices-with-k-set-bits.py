import math


class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        sum = 0
        for i in range(len(nums)):
            bits=i.bit_count()
            if bits == k:
                sum += nums[i]
        return sum
