#include<bits/stdc++.h>
using namespace std;

int find(int node,vector<int>& parents)
{
    if(parents[node]==-1) return node;
    return parents[node]=find(parents[node],parents);  //path compression
}

void Union(int fromParent,int toParent,vector<int>& parents)
{
    parents[fromParent]=toParent;
}

bool isCyclic(vector<pair<int,int>>& edges,vector<int>& parents)
{
    for(auto e: edges)
    {
        int fromParent=find(e.first,parents);
        int toParent=find(e.second,parents);
        if(fromParent==toParent) return true;  //Cycle detected
        Union(fromParent,toParent,parents);
    }
    return false;
}

int main()
{
    int e,v;  //e for edges, v for vertices
    cin>>e>>v;
    vector<pair<int,int>> edges;
    for(int i=0;i<e;i++)
    {
        int from,to;
        cin>>from>>to;
        edges.push_back(make_pair(from,to));
    }
    vector<int> parents(v+1,-1);
    if(isCyclic(edges,parents)==true)
    {
        cout<<"Given Undirected graph has a cycle.\n";
    }
    else
    {
        cout<<"No cycle in given undirected graph.\n";
    }
}