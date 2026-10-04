class Solution {
public:
    bool checkValidString(string s) {
        int openbrackets=0,n=s.size(),closebrackets=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='*')
            openbrackets++;
            else
            openbrackets--;

            if(openbrackets<0)
            return false;
        }   
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'||s[i]=='*')
            closebrackets++;
            else
            closebrackets--;

            if(closebrackets<0)
            return false;
        }   
        return true;
    }
};