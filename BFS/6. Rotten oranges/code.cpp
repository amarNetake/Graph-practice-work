#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int timeframe;
        int x,y;
};

void calcTime(vector<vector<int>>& vect,int n,int m,queue<Node>& q,int& t)
{
    int countNodes=0;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        while(countNodes>0)
        {
            Node temp=q.front();
            q.pop();
            if(temp.x>0&&vect[temp.x-1][temp.y]==1)  //Move top
            {
                vect[temp.x-1][temp.y]=2;
                Node nd;
                nd.x=temp.x-1;
                nd.y=temp.y;
                nd.timeframe=temp.timeframe+1;
                q.push(nd);
            }
            if(temp.y<m-1&&vect[temp.x][temp.y+1]==1)  //Move right
            {
                vect[temp.x][temp.y+1]=2;
                Node nd;
                nd.x=temp.x;
                nd.y=temp.y+1;
                nd.timeframe=temp.timeframe+1;
                q.push(nd);
            }
            if(temp.x<n-1&&vect[temp.x+1][temp.y]==1)  //Move bottom
            {
                vect[temp.x+1][temp.y]=2;
                Node nd;
                nd.x=temp.x+1;
                nd.y=temp.y;
                nd.timeframe=temp.timeframe+1;
                q.push(nd);
            }
            if(temp.y>0&&vect[temp.x][temp.y-1]==1)
            {
                vect[temp.x][temp.y-1]=2;
                Node nd;
                nd.x=temp.x;
                nd.y=temp.y-1;
                nd.timeframe=temp.timeframe+1;
                q.push(nd);
            }
            countNodes--;
            t=temp.timeframe;
        }
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> vect(n,vector<int>(m));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>vect[i][j];
	        }
	    }
	    queue<Node> q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(vect[i][j]==2)
	            {
	                Node nd;
	                nd.x=i;
	                nd.y=j;
	                nd.timeframe=0;
	                q.push(nd);
	            }
	        }
	    }
	    int tim;  //time
	    calcTime(vect,n,m,q,tim);
	    

	    /*
	    	We again need to run the loop below because
	    	To check if after BFS traversal still any oranges remained unrotten 
	    	if so then it is impossible to rot them hence print time as -1
	    */
	    for(int i=0;i<n;i++)  
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(vect[i][j]==1)
	            {
	                tim=-1;
	                break;
	            }
	        }
	    }
	    cout<<tim<<"\n";
	}
	return 0;
}