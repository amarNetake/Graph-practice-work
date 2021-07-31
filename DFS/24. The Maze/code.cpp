class Solution {
public:
    vector<vector<int>> disp={{0,1},{1,0},{0,-1},{-1,0}};
    int encrypt(int x,int y,int columns)
    {
        return x*columns+y;
    }
    pair<int,int> decrypt(int pos,int columns)
    {
        int x=pos/columns;
        int y=pos%columns;
        return {x,y};
    }
    
    void dfs(vector<vector<int>>& maze,int src,int dest,vector<bool>& visited, bool& result)
    {
        int r=maze.size();
        int c=maze[0].size();
        pair<int,int> curr=decrypt(src,c);
        int x=curr.first,y=curr.second;
        if(x<0 || x>=r || y<0|| y>=c || visited[src]==true) return;
        visited[src]=true;
        if(src==dest)
        {
            result=true;
            return;
        }
        for(auto k: disp)
        {
            int dx=k[0],dy=k[1];
            int newX=x,newY=y;
            while(newX+dx>=0 && newX+dx<r && newY+dy>=0 && newY+dy<c && maze[newX+dx][newY+dy]!=1)
            {
                newX=newX+dx;
                newY=newY+dy;
            }
            if(visited[encrypt(newX,newY,c)]==false)
            {
                int newSrc=encrypt(newX,newY,c);
                dfs(maze,newSrc,dest,visited,result);
            }
            if(result==true) return;
        }
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& s, vector<int>& d) {
        int r=maze.size();
        int c=maze[0].size();
        vector<bool> visited(1e5,false); //item= (total columns)*x + y ; For deciphering row=item/total cols ; col=item%total cols
        int src=encrypt(s[0],s[1],c);
        int dest=encrypt(d[0],d[1],c);
        bool result=false;
        dfs(maze,src,dest,visited,result);
        return result;
    }
};