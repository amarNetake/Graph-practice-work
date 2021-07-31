class Solution {
public:
    vector<vector<int>> disp={{0,1},{1,0},{1,1},{-1,-1},{0,-1},{-1,0},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        int dist=1;
        int minDist=INT_MAX;
        q.push(make_pair(0,0));
        visited[0][0]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                pair<int,int> curr=q.front();
                q.pop();
                int x=curr.first,y=curr.second;
                if(x==n-1 && y==n-1) 
                {
                    minDist=min(minDist,dist);
                    countNodes--;
                    continue;
                }
                for(auto k: disp)
                {
                    int dx=k[0],dy=k[1];
                    
                    if( (x+dx)>=n || (y+dy)>=n || (x+dx)<0 || (y+dy)<0 || visited[x+dx][y+dy]==true || grid[x+dx][y+dy]==1) continue;
                    q.push(make_pair(x+dx,y+dy));
                    visited[x+dx][y+dy]=true;
                }
                countNodes--;
            }
            dist++;
        }
        return minDist<1e8?minDist:-1;
    }
};