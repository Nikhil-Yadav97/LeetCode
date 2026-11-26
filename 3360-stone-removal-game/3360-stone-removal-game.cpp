class Solution {
public:
    bool canAliceWin(int n) {
        if(n-10==0)
            return true;
        if (n - 10 < 0) {
            return false;
        }
        

        int stonesleft = n - 10;
        int b =10-1;
        int flag = 0;
        while (1) {
            if (flag == 0) {
                if (stonesleft - b < 0)
                    return true;
                else {
                    if(stonesleft-b==0)
                        return false;
                    stonesleft = stonesleft - b;
                    b= b - 1;
                }
            } else {
                if (stonesleft-b < 0)
                    return false;
                else {
                    if(stonesleft-b==0)
                        return true;
                    stonesleft = stonesleft - b;

                    b = b - 1;
                }
            }
            flag = flag == 1 ? 0 : 1;
        }
        return true;
    }
};