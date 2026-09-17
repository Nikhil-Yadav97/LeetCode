class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sum=nums[0]
        maxsum=nums[0]
        for i in range(1,len(nums)):
            num=nums[i]
            sum=max(num,num+sum)
            maxsum=max(maxsum,sum)
        return maxsum