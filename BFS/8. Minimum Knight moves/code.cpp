class Solution {
public:
    //BFS
    int minKnightMoves(int X, int Y) {
        
        //Since the chessboard knight moves will follow symmetry so we can take absolute values to reduce the size of search space.
        X=abs(X);
        Y=abs(Y);
        queue<pair<int,int>> q;
        unordered_map<string,bool> visited;
        q.push(make_pair(0,0));
        visited[to_string(0)+"#"+to_string(0)]=true;
        int totalMoves=0;
        vector<vector<int>> delta={{2,-1},{-1,2},{2,1},{1,2},{-2,1},{1,-2},{-1,-2},{-2,-1}};
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)
            {
                break;
            }
            while(countNodes>0)
            {
                
                pair<int,int> curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                if(x==X&&y==Y)
                {
                    return totalMoves;
                }
                for(auto d: delta)
                {
                    int dx=d[0];
                    int dy=d[1];
                    int nx=x+dx;
                    int ny=y+dy;
                    /*
                    	To compact the size of search space we do nx>=-1 and ny>=-1 which is essential for cases like (-1,-1) or (1,1) type of
                    	target location. Also we need to ensure to not go beyond the target coordinates or ensure that we remain in "triangular" 
                    	search space by nx<=X+2 and ny<=Y+2
                    */ 
                    if(visited.find(to_string(nx)+"#"+to_string(ny))==visited.end()&&nx>=-1&&ny>=-1&&nx<=X+2 &&ny<=Y+2)
                    {
                        q.push(make_pair(x+dx,y+dy));
                        visited[to_string(x+dx)+"#"+to_string(y+dy)]=true;
                        if(x+dx==X&&y+dy==Y)
                        {
                            return totalMoves+1;
                        }
                    }
                }
                countNodes--;
            }
            totalMoves++;
        }
        return totalMoves;
    }
};