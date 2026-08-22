class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,div=1,num=n;
        while(num)
            {
                int digit=num%10;
                sum+=digit;
                div=div*digit;
                num=num/10;
            }
        return n%(sum + div)==0;
    }
};