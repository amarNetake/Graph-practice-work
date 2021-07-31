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
    printGraph(vect,6);
    return 0;
}