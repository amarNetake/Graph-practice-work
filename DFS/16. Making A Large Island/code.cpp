class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y,vector<vector<bool>>& visited,int& strength,int id,int n)
    {
        if(x>=n||x<0||y>=n||y<0||visited[x][y]==true|| grid[x][y]==0) return;
        visited[x][y]=true;
        strength++;
        dfs(grid,x+1,y,visited,strength,id,n);
        dfs(grid,x,y+1,visited,strength,id,n);
        dfs(grid,x-1,y,visited,strength,id,n);
        dfs(grid,x,y-1,visited,strength,id,n);
        grid[x][y]=id;
    }
    
    void fillGridWithIds(vector<vector<int>>& grid,unordered_map<int,int>& ma,int n)
    {
        int id=2; //Starting ids with 2 as 0 and 1 are  representing water and island
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                int strength=0;
                if(visited[i][j]==false) dfs(grid,i,j,visited,strength,id,n);
                ma[id]=strength;
                id++;
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> ma; //island id -> size of island
        fillGridWithIds(grid,ma,n);
        int maxCount=0;
        for(auto x: ma) maxCount=max(maxCount,x.second); //If there are no zeros so we must have the size of largest island
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0) continue;
                unordered_map<int,bool> temp;
                int count=1; //Current 0 turned into 1
                if(i-1>=0 && grid[i-1][j]!=0 && temp[grid[i-1][j]]==false)
                {
                    count=count+ma[grid[i-1][j]];
                    temp[grid[i-1][j]]=true;
                }
                if(j-1>=0 && grid[i][j-1]!=0 && temp[grid[i][j-1]]==false)
                {
                    count=count+ma[grid[i][j-1]];
                    temp[grid[i][j-1]]=true;
                }
                if(i+1<n && grid[i+1][j]!=0 && temp[grid[i+1][j]]==false)
                {
                    count=count+ma[grid[i+1][j]];
                    temp[grid[i+1][j]]=true;
                }
                if(j+1<n && grid[i][j+1]!=0 && temp[grid[i][j+1]]==false)
                {
                    count=count+ma[grid[i][j+1]];
                    temp[grid[i][j+1]]=true;
                }
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};