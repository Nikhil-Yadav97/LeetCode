class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        count=[0]*3
        for ele in stones:
            count[ele%3]+=1
        
        if count[0]%2==0:
            return (count[1]>=1 and count[2]>=1) and (count[1]>=count[2] or count[2]>=count[1])
        
        return abs(count[1]-count[2])>=3
