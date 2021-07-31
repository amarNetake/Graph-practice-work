// This is a solution for the leetcode problem
void dfs(int i,int j,vector<vector<char>>& vect,int n,int m)
    {
        vect[i][j]='2';
        if(i>0&&vect[i-1][j]=='1')  //top
        {
            dfs(i-1,j,vect,n,m);
        }
        if(j>0&&vect[i][j-1]=='1')  //left
        {
            dfs(i,j-1,vect,n,m);
        }
        if(j<m-1&&vect[i][j+1]=='1')    //right
        {
            dfs(i,j+1,vect,n,m);
        }
        if(i<n-1&&vect[i+1][j]=='1')    //bottom
        {
            dfs(i+1,j,vect,n,m);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid,grid.size(),grid[i].size());
                }
            }
        }
        return count;
    }