class Solution:
    def countCommas(self, n: int) -> int:
        if n < 1000:
            return 0
        commas =1
        lower=1000
        total=0
        while lower<=n:
            upper=1000*lower-1
            if upper >n :
                upper=n
            total+=commas*(upper-lower+1)
            lower=lower*1000
            commas+=1
        return total
            
        
