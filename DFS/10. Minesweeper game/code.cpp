void dfs(vector<vector<char>>& vect,int x,int y,int n,int m)
{
    if(x<0||x>n-1||y<0||y>m-1||vect[x][y]!='E')
    {
        return;
    }
    int count=0;  //Total adjacent Mines to the present square
    if(x>0 && vect[x-1][y]=='M')
    {
        count++;
    }
    if(y>0 && vect[x][y-1]=='M')
    {
        count++;
    }
    if(x<n-1&&vect[x+1][y]=='M')
    {
        count++;
    }
    if(y<m-1 && vect[x][y+1]=='M')
    {
        count++;
    }
    if(x>0&&y>0 && vect[x-1][y-1]=='M')
    {
        count++;
    }
    if(x>0&&y<m-1 && vect[x-1][y+1]=='M')
    {
        count++;
    }
    if(x<n-1&&y>0 && vect[x+1][y-1]=='M')
    {
        count++;
    }
    if(x<n-1&&y<m-1 && vect[x+1][y+1]=='M')
    {
        count++;
    }
    if(count==0)
    {
        vect[x][y]='B';
        //We are asked to reveal the adjacent squares only if the current square unrevealed had no 
        // adjacent squares that had mines. So if the current square becomes 'B' then only reveal it's adjacents 
        dfs(vect,x-1,y,n,m);
        dfs(vect,x,y-1,n,m);
        dfs(vect,x+1,y,n,m);
        dfs(vect,x,y+1,n,m);
        dfs(vect,x-1,y-1,n,m);
        dfs(vect,x-1,y+1,n,m);
        dfs(vect,x+1,y-1,n,m);
        dfs(vect,x+1,y+1,n,m);
    }
    else
    {
        vect[x][y]=count+'0';  //This is the way to convert the int to char to retain the value in it's char form
    }
    
    
}
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
{
    int n=board.size();
    int m=board[0].size();
    int x=click[0];
    int y=click[1];
    if(board[x][y]=='M')
    {
        board[x][y]='X';
        return board;
    }
    else if(board[x][y]=='E')
    {
        dfs(board,x,y,n,m);
    }
    return board;
}