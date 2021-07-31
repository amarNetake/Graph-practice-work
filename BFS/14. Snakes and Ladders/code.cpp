class Solution {
public:
    int findCoordinates(int curr,int jump,int n,vector<vector<int>>& board)
    {
        int next=curr+jump;
        int dx=n - 1 - (next-1)/n;
        int dy;
        if(((next-1)/n)%2==1)  //Odd level up from bottom-most level
        {
            dy= n - 1 - ((next-1)%n);  //Can come up with this easily by taking extreme i.e. if next=6 in 6x6 board
        }
        else dy = (next-1)%n;
        if(dx<0) return -1;
        if(board[dx][dy]==-1) return next;
        else return board[dx][dy];
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,bool> visited;
        int n=board.size();
        int count=0;
        int target=n*n;
        queue<int> q;
        q.push(1);
        visited[1]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                int curr=q.front();
                q.pop();
                if(curr>target)
                {
                    countNodes--;
                    continue;
                }
                cout<<curr<<" ";
                if(curr==target) return count;
                for(int i=1;i<=6;i++)
                {
                    int x=findCoordinates(curr,i,n,board);
                    if(x==-1 || visited[x]==true) continue;
                    q.push(x);   
                    visited[x]=true;
                }
                countNodes--;
            }
            cout<<"\n";
            count++;
        }
        return -1;
    }
};