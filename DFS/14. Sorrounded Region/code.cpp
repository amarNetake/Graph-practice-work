class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& board)
    {
        int rows=board.size();
        int cols=board[0].size();
        board[x][y]='1';
        if(x+1<rows && board[x+1][y]=='O') dfs(x+1,y,board);
        if(y+1<cols && board[x][y+1]=='O') dfs(x,y+1,board);
        if(x-1>=0 && board[x-1][y]=='O') dfs(x-1,y,board);
        if(y-1>=0 && board[x][y-1]=='O') dfs(x,y-1,board);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        int i=0,j=0;
        int count=1;
        while(count!=2)
        {
            if(board[i][j]=='O') dfs(i,j,board);
            
            if(j<cols-1 && i==0) j++;
            else if(j==cols-1 && i<rows-1) i++;
            else if(i==rows-1 && j>0) j--;
            else if(i>0 && j==0)i--;
            if(i==0 && j==0) count++;
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]=='1') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};