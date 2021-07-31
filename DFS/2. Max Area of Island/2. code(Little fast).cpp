class Solution {
public:

	// Execution time: 100ms
    //Defined globally as no need to be created each time in recursive calls eats a lot of space due to recursive stack and also time
    vector<vector<int>> disp={{1,0},{-1,0},{0,1},{0,-1}};   
    
    int dfs(vector<vector<int>>& grid,int x,int y)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0)
        {
            return 0;
        }
        grid[x][y]=0;
        int count=1;
        
        for(auto k: disp)
        {
            int dx=k[0];
            int dy=k[1];
            count=count+dfs(grid,x+dx,y+dy);
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount=0;
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    count=dfs(grid,i,j);
                    maxCount=max(maxCount,count);
                }
            }
        }
        return maxCount;
    }
};