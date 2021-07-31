//Adjacency list for directed graph with the nodes numbers from 0 to n-1 for n vertices

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> vect[],int x,int y)
{
    vect[x].push_back(y);
}

void printGraph(vector<int> vect[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i;
        for(int x:vect[i])
        {
            cout<<"->"<<x;
        }
        cout<<"->END";
        cout<<"\n";
    }
}

void removeEdge(vector<int> vect[],int x,int y)
{
	//find(vect[x].begin(),vect[x].end,y) will return an iterator of position of item y in vector x
    auto itr=find(vect[x].begin(),vect[x].end(),y); 
    vect[x].erase(itr);
}

int main()
{
    int v;
    v=6;
    vector<int> vect[v];  // Created an array of vectors with array length as v 
    addEdge(vect,0,1);
    addEdge(vect,0,3);
    addEdge(vect,3,1);
    addEdge(vect,1,2);
    addEdge(vect,2,3);
    addEdge(vect,3,4);
    addEdge(vect,4,5);
    cout<<"The Adjacency list for given graph is:\n";
    printGraph(vect,6);
    cout<<"\n";
    removeEdge(vect,3,1); //Removing an edge between node 3 and node 4
    cout<<"The Adjacency list for the graph after removing an edge is (3->1): \n";
    printGraph(vect,6);
    return 0;
}