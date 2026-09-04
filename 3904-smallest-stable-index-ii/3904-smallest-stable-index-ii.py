class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        maxi=[]
        maxi.append(nums[0])
        for i in range(1,len(nums)):
            maxi.append(max(nums[i],maxi[-1]))

        mini=[0]*len(nums)
        mini[-1]=nums[-1]
        for i in range(len(nums)-2,-1,-1):
            mini[i]=min(nums[i],mini[i+1])
        
        ans=len(nums)
        for i in range(len(nums)):
            if (maxi[i]-mini[i])<=k:
                ans=min(ans,i)

        return -1 if ans==len(nums) else ans