class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int& area)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1) return;
        area++;
        //Make visited islands -1 to remove the toil of maintaining the separate map or vector<vector<int>> visited
        //array to track the status of visited nodes as we are after all going to visit each node once.
        grid[i][j]=-1;  
        dfs(grid,i+1,j,area);
        dfs(grid,i,j+1,area);
        dfs(grid,i-1,j,area);
        dfs(grid,i,j-1,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=1) continue;
                int area=0;
                dfs(grid,i,j,area);
                maxArea=max(maxArea,area);
                
            }
        }
        return maxArea;
    }
};