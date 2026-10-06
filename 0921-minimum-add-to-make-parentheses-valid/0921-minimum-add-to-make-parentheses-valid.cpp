class Solution {
public:
    int minAddToMakeValid(string s) {
        int paren=0,count=0;
        if(s.size()==0)
        return 0;
        for(auto it : s)
        {
            if(it=='(')
            {
                paren++;
            }
            if(it==')')
            {
                paren--;
                if(paren<0)
                {
                    count+=abs(paren);
                    paren=0;
                }
            }

        }
        count+=paren;
        return count;
    }
};