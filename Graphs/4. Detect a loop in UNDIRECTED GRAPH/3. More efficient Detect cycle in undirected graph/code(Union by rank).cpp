#include<bits/stdc++.h>
using namespace std;

class status
{
    public:
        int rank=0;
        int parent=-1;
};

status find(int node,vector<status>& parents)
{
    if(parents[node].parent==-1) 
    {
        status s;
        s.parent=node;
        s.rank=0;
        return s;
    }
    else
    {
        status s=find(parents[node].parent,parents);
        parents[node].parent=s.parent;
        parents[node].rank=s.rank+1;
        return parents[node];
    }
}

void Union(status fromParent,status toParent,vector<status>& parents)
{
    if(fromParent.rank==toParent.rank)
    {
        parents[fromParent.parent].parent=toParent.parent;
        toParent.rank=1;
    }
    else if(fromParent.rank>toParent.rank)
    {
        parents[toParent.parent].parent=fromParent.parent;
        fromParent.rank=1;
    }
    else
    {
        parents[fromParent.parent].parent=toParent.parent;
        toParent.rank=1;
    }
}

bool isCyclic(vector<pair<int,int>>& edges,vector<status>& parents)
{
    for(auto e: edges)
    {
        status fromParent=find(e.first,parents);
        status toParent=find(e.second,parents);
        if(fromParent.parent==toParent.parent) return true;  //Cycle detected
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
    vector<status> parents(v+1);
    if(isCyclic(edges,parents)==true)
    {
        cout<<"Given Undirected graph has a cycle.\n";
    }
    else
    {
        cout<<"No cycle in given undirected graph.\n";
    }
}