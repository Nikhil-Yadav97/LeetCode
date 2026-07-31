class Solution {
public:
    int K;
    string num;
    int dp [11][11][11][21][2][2];
    int count(int pos,int even,int odd,int rem,int started,int tight)
    {
        if(pos==num.size())
        return even==odd && started && rem==0;


        if(dp[pos][even][odd][rem][started][tight]!=-1)
        return dp[pos][even][odd][rem][started][tight];
        int limit=tight ? num[pos]-'0': 9;
        int ans=0;
        for(int d=0;d<=limit;d++)
        {
            started=started || d!=0;
            int newtight=tight && d==limit;
            if(!started)
            {
                ans+=count(pos+1,even,odd,rem,false,newtight);
            }else{
                int evencount=even,oddcount=odd;
                int remainder=(rem*10+d)%K;
                if(d%2==0)
                {
                    evencount++;
                }else
                oddcount++;

                ans+=count(pos+1,evencount,oddcount,remainder,started,newtight);
            }
        }
        return dp[pos][even][odd][rem][started][tight]=ans;
    }
    int fn(int n)
    {
        if(n<=0)
        return 0;
        memset(dp,-1,sizeof(dp));
        num=to_string(n);
        return count(0,0,0,0,0,1);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        K=k;
        return fn(high)-fn(low-1);
    }
};