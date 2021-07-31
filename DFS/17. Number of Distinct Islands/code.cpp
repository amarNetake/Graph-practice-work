class Solution {
public:
    void dfs(vector<vector<int>>& grid,string& path,int x,int y,int r,int c)
    {
        if(x<0||x>=r||y<0||y>=c || grid[x][y]==0)
        {
            path.insert(path.end(),'Z');
            return;
        }
        grid[x][y]=0;
        path.insert(path.end(),'U');
        dfs(grid,path,x-1,y,r,c);
        path.insert(path.end(),'R');
        dfs(grid,path,x,y+1,r,c);
        path.insert(path.end(),'D');
        dfs(grid,path,x+1,y,r,c);
        path.insert(path.end(),'L');
        dfs(grid,path,x,y-1,r,c);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_map<string,bool> ma;
        //R->Right ; U->Up  ; D->Down  ;  L->Left  ;  Z->out of bound or if water(0) is detected
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    string path="";
                    dfs(grid,path,i,j,r,c);
                    ma[path]=true;
                }
            }
        }
        return ma.size();
    }
};