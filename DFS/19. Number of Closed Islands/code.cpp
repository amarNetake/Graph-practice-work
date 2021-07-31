class Solution {
public:
    vector<vector<int>> disp={{0,-1},{-1,0},{1,0},{0,1}};
    void dfs(vector<vector<int>>& grid,int x,int y,bool& closed,vector<vector<bool>>& visited,int r,int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || visited[x][y]==true || grid[x][y]==1) return;
        if(x==0 || x==r-1 || y==0 || y==c-1) closed=false;
        visited[x][y]=true;
        for(auto k:disp)
        {
            int dx=x+k[0],dy=y+k[1];
            dfs(grid,dx,dy,closed,visited,r,c);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0 && visited[i][j]==false)
                {
                    bool closed=true;
                    dfs(grid,i,j,closed,visited,r,c);
                    if(closed==true) count++;
                }
            }
        }
        return count;
    }
};