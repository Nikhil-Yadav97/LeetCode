class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2,
                      int y2) {
        int nx, ny;
        if (x2 < xc)
            nx = x2;
        else {
            if (x1 > xc) {
                nx = x1;
            } else
                nx = xc;
        }
        if (yc > y2)
            ny = y2;
        else {
            if (y1 > yc) {
                ny = y1;
            } else
                ny = yc;
        }

        int dis=sqrt(pow(xc-nx,2)+pow(yc-ny,2));
        if(radius>=dis)
        return true;
        return false;
    }
};