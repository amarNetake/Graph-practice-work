//0 => not island   ;  1 => island but not yet visited    ;   2 => island and visited
void dfs(int i,int j,vector<int> vect[],int n,int m)
{
    vect[i][j]++;
    if(i>0&&vect[i-1][j]==1)  //top
    {
        dfs(i-1,j,vect,n,m);
    }
    if(j>0&&vect[i][j-1]==1)  //left
    {
        dfs(i,j-1,vect,n,m);
    }
    if(j<m-1&&vect[i][j+1]==1)    //right
    {
        dfs(i,j+1,vect,n,m);
    }
    if(i<n-1&&vect[i+1][j]==1)    //bottom
    {
        dfs(i+1,j,vect,n,m);
    }
    if(i>0&&j>0&&vect[i-1][j-1]==1)  //top-left
    {
        dfs(i-1,j-1,vect,n,m);
    }
    if(i>0&&j<m-1&&vect[i-1][j+1]==1)  //top-right
    {
        dfs(i-1,j+1,vect,n,m);
    }
    if(i<n-1&&j>0&&vect[i+1][j-1]==1)  //bottom-left
    {
        dfs(i+1,j-1,vect,n,m);
    }
    if(i<n-1&&j<m-1&&vect[i+1][j+1]==1)  //bottom-right
    {
        dfs(i+1,j+1,vect,n,m);
    }
}

int findIslands(vector<int> vect[], int n, int m) {

    // Your code here
    int countIslands=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vect[i][j]==1)
            {
                countIslands++;
                dfs(i,j,vect,n,m);
            }
        }
    }
    return countIslands;
}