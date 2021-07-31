#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>>& grid,int r,int c)
{
    int modulo=1e9+7;
    int count=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    int countNodes;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0) break;
        while(countNodes>0)
        {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==r-1 && y==c-1)
            {
                count=(count+1)%modulo;
                countNodes--;
                continue;
            }
            for(int i=x+1;i<r;i++)
            {
                if(grid[i][y]=='#') break;
                q.push({i,y});
            }
            for(int i=y+1;i<c;i++)
            {
                if(grid[x][i]=='#') break;
                q.push({x,i});
            }
            for(int i=x+1,j=y+1;i<r && j<c;i++,j++)
            {
                if(grid[i][j]=='#') break;
                q.push({i,j});
            }
            countNodes--;
        }
    }
    return count;
}

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        cin>>grid[i][j];
	    }
	}
	int result=solve(grid,n,m);
	cout<<result<<"\n";
	return 0;
}
