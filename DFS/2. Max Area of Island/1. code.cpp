class Solution {
public:
    int area(vector<vector<int>>& grid,int x,int y,int r,int c,vector<vector<int>>& visited)
    {
        if(visited[x][y]==true) return 0;
        visited[x][y]=true;
        vector<vector<int>> disp={{0,-1},{0,1},{-1,0},{1,0}};
        int count=1;  //For self 
        for(auto k: disp)
        {
            int dx=k[0];
            int dy=k[1];
            if(x+dx>=0&&x+dx<r && y+dy>=0 && y+dy<c) 
            {
                if(grid[x+dx][y+dy]==1)  count=count + area(grid,x+dx,y+dy,r,c,visited);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,false));
        int count=0;
        int maxCount=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(visited[i][j]==true||grid[i][j]==0) continue;
                count=area(grid,i,j,r,c,visited);
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};