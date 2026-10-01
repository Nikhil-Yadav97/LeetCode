class Solution {
public:
    bool isValid(string s) {
        stack <char> c;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(' ||ch=='[' ||ch=='{' )
            {
                c.push(ch);
            }
            else{
                if(!c.empty())
                {
                    int top=c.top();
                    if(ch==')'&&top=='('||ch=='}'&&top=='{'||ch==']'&&top=='[')
                    {
                        c.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return c.empty();
    }
    
};