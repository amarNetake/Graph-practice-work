class Solution {
public:
    void bfs(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& result,int m,int n)
    {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q.push({x,y});
        visited[x][y]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                pair<int,int> curr=q.front();
                q.pop();
                x=curr.first;
                y=curr.second;
                if(grid[x][y]!=0)
                {
                    int up= (x-1>=0)?result[x-1][y]:1e8;
                    int left=(y-1>=0)?result[x][y-1]:1e8;
                    result[x][y]=min(result[x][y],min(up,left)+1);
                }
                else result[x][y]=0;
                if(x+1<m && visited[x+1][y]==false) 
                {
                    q.push({x+1,y});
                    visited[x+1][y]=true;
                }
                if(y+1<n && visited[x][y+1]==false)
                {
                    q.push({x,y+1});
                    visited[x][y+1]=true;
                }
                countNodes--;
            }
        }
    }
    
    void revBfs(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& result,int m,int n)
    {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q.push({x,y});
        visited[x][y]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                pair<int,int> curr=q.front();
                q.pop();
                x=curr.first;
                y=curr.second;
                if(grid[x][y]!=0)
                {
                    int down= (x+1<m)?result[x+1][y]:1e8;
                    int right=(y+1<n)?result[x][y+1]:1e8;
                    result[x][y]=min(result[x][y],min(down,right)+1);
                }
                else result[x][y]=0;
                if(x-1>=0 && visited[x-1][y]==false) 
                {
                    q.push({x-1,y});
                    visited[x-1][y]=true;
                }
                if(y-1>=0 && visited[x][y-1]==false)
                {
                    q.push({x,y-1});
                    visited[x][y-1]=true;
                }
                countNodes--;
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //If the closest 0 is in above or left then it will be covered in bfs from (0,0)
        //If the closest 0 is below or right then it will be covered in bfs from (m-1,n-1);
        vector<vector<int>> result(m,vector<int>(n,INT_MAX)); 
        bfs(grid,0,0,result,m,n);
        revBfs(grid,m-1,n-1,result,m,n);
        return result;
    }
};