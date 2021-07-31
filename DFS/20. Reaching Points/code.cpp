class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy)
        {
            int tempx,tempy;
            if(tx==sx && ty==sy) return true;
            else if(tx==sx)
            {
                tempy=ty-sy;
                if(tempy%tx==0) return true;
                return false;
            }
            else if(ty==sy)
            {
                tempx=tx-sx;
                if(tempx%ty==0) return true;
                return false;
            }
            if(tx>=ty) 
            {
                tempx=tx-ty;
                tempy=ty;
            }
            else
            {
                tempy=ty-tx;
                tempx=tx;
            }
            tx=tempx;
            ty=tempy;
        }
        return false;
    }
};