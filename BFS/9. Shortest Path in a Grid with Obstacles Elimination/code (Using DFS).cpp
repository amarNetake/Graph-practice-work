class Solution {
public:
    bool found;
    int distance;
    int obstacles;
    void shortestPathUtil(vector<vector<int>>& vect,vector<vector<bool>>& visited,int n,int m,int i,int j,int k,Solution& s,int dist)
    {
        if(dist>s.distance||i<0||i>n-1||j<0||j>m-1||visited[i][j]==true)
        {
            return;
        }
        if(vect[i][j]==1)
        {
            s.obstacles++;
            if(s.obstacles>k)
            {
                s.obstacles--;
                return;
            }
        }
        if(i==n-1&&j==m-1)
        {
            if(dist<s.distance)
            {
                s.found=true;
                s.distance=dist;
            }
            return;
        }
        visited[i][j]=true;
        shortestPathUtil(vect,visited,n,m,i+1,j,k,s,dist+1);
        shortestPathUtil(vect,visited,n,m,i,j+1,k,s,dist+1);
        shortestPathUtil(vect,visited,n,m,i-1,j,k,s,dist+1);
        shortestPathUtil(vect,visited,n,m,i,j-1,k,s,dist+1);
        visited[i][j]=false;
        if(vect[i][j]==1)
        {
            s.obstacles-=1;
        }
    }
    int shortestPath(vector<vector<int>>& vect, int k) {
        Solution s;   //Class object
        s.distance=INT_MAX;
        s.found=false;
        s.obstacles=0;
        int n=vect.size();
        int m=vect[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m));
        shortestPathUtil(vect,visited,n,m,0,0,k,s,0);
        if(s.found==true)
        {
            return s.distance;
        }
        return -1;
    }
};