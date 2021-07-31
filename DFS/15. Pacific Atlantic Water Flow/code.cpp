class Solution {
public:
    vector<vector<int>> disp={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>& ocean,int r,int c,vector<vector<int>>& visited,char curr)
    {
        ocean[x][y]=true;
        
        if(curr=='p')
        {
            visited[x][y]=1; 
            for(auto k: disp)
            {
                int dx=k[0],dy=k[1];
                if(x+dx==r || y+dy==c || x+dx<0 || y+dy<0 || visited[x+dx][y+dy]==1) continue;
                if(x+dx==0 || y+dy==0 || heights[x+dx][y+dy]>=heights[x][y]) dfs(x+dx,y+dy,heights,ocean,r,c,visited,curr);
            }
        }
        else
        {
            visited[x][y]=2; 
            for(auto k: disp)
            {
                int dx=k[0],dy=k[1];
                if(x+dx==r || y+dy==c || x+dx<0 || y+dy<0 || visited[x+dx][y+dy]==2) continue;
                if(x+dx==r-1 || y+dy==c-1 || heights[x+dx][y+dy]>=heights[x][y]) dfs(x+dx,y+dy,heights,ocean,r,c,visited,curr);
            }
        }
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));
        vector<vector<int>> visited(r,vector<int>(c,0)); // visited[x][y]=1 => visited Pacific; visited[x][y]=2 => visited Atlantic
        //DFS
        dfs(0,0,heights,pacific,r,c,visited,'p');
        dfs(r-1,c-1,heights,atlantic,r,c,visited,'a');
        
        //Finding intersection
        vector<vector<int>> result;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(pacific[i][j]==true && atlantic[i][j]==true) result.push_back({i,j});
            }
        }
        return result;
    }
};