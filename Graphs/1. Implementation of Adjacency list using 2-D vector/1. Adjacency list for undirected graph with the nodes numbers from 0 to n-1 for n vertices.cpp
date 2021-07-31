//Adjacency list for undirected graph with the nodes numbers from 0 to n-1 for n vertices

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&vect,int x,int y)
{
    //Creating an undirected edge for an undirected graph.
    vect[x].push_back(y);
    vect[y].push_back(x);
}

void printAdjList(vector<vector<int>> vect,int v)
{
    for(int i=0;i<vect.size();i++)
    {
        cout<<i;
        for(int j=0;j<vect[i].size();j++)
        {
            cout<<"-> "<<vect[i][j];
        }
        cout<<"\n";
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int v,e;
	    cin>>v>>e;
	    vector<vector<int>> vect(v);  //So here we set the size or total rows as number of vertices as v
	    for(int i=0;i<e;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        addEdge(vect,x,y);
	    }
	    printAdjList(vect,v);
	}
	return 0;
}