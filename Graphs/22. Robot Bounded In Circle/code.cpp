class Solution {
public:
    bool isRobotBounded(string instructions) {
        //Since the set of instructions will remain the same for each iteration.
        //So it is expected to return to (0,0) it atmost next 4 iterations.
        unordered_map<string,pair<int,int>> ma;
        int x=0,y=0;
        char dir='N';
        char curr='N';
        for(int i=1;i<=4;i++)
        {
            for(auto k: instructions)
            {
                if(k=='G')
                {
                    if(curr=='N') y++;
                    else if(curr=='S') y--;
                    else if(curr=='E') x++;
                    else x--;
                }
                else if(k=='L')
                {
                    if(curr=='N') curr='W';
                    else if(curr=='S')  curr='E';
                    else if(curr=='E') curr='N';
                    else curr='S';
                }
                else if(k=='R')
                {
                    if(curr=='N') curr='E';
                    else if(curr=='S')  curr='W';
                    else if(curr=='E') curr='S';
                    else curr='N';
                }
            }
            if(x==0 && y==0) return true;
        }
        return false;
    }
};