class Solution {
public:
    bool dfs(int len1,int len2,int len3,int len4,int curr,int side,vector<int>& msticks)
    {
        if(curr==msticks.size())
        {
            if(len1==len2 && len3==len4 && len1==len3) return true;
            return false;
        }
        bool check=false;
        if(len1+msticks[curr]<=side)check=dfs(len1+msticks[curr],len2,len3,len4,curr+1,side,msticks);
        if(check==true) return true;
        
        if(len2+msticks[curr]<=side)check=dfs(len1,len2+msticks[curr],len3,len4,curr+1,side,msticks);
        if(check==true) return true;
        
        if(len3+msticks[curr]<=side)check=dfs(len1,len2,len3+msticks[curr],len4,curr+1,side,msticks);
        if(check==true) return true;
        
        if(len4+msticks[curr]<=side)check=dfs(len1,len2,len3,len4+msticks[curr],curr+1,side,msticks);
        return check;
    }
    
    bool makesquare(vector<int>& msticks) {
        
        int perimeter=0;
        for(int x: msticks) perimeter=perimeter+x;
        if(perimeter%4!=0) return false;
        int side=perimeter/4; //Each side must be exactly perimeter/4. If we exceed this for any string we immediately go back
        int len1=0,len2=0,len3=0,len4=0;
        return dfs(len1,len2,len3,len4,0,side,msticks);
    }
};