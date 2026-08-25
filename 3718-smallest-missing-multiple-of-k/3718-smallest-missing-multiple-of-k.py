class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        seen={}
        for ele in nums:
            seen[ele]=1
        
        for i in range(1,len(nums)+1):
            if k*i not in seen :
                return k*i
        return k*(len(nums)+1)
