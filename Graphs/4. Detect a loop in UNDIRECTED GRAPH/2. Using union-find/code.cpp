//We cannot find cycle in directed graph using union find as union operation is non-directional.

// Time Complexity through this method for detecting cycle in undirected graph is O(V*E).
// Hence we prefer DFS method to detect loop in undirected graph which has time complexity O(V+E).
#include<bits/stdc++.h>
using namespace std;

//Find operation returns the parent of given node.
int find(int node,vector<int>& parents)
{
    if(parents[node]==-1) return node;
    return find(parents[node],parents);
}

//Union operation takes the union of 2 disjoint sets by giving access of one parent to other parent.
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
        /*
        	Cycle detected( if 2 nodes already have same parent implies there is already a path
        	between 2 nodes now if we introduce another direct path/edge then it will cause cycle
        	as it is like introducing an extra edge in a tree)
        */
        if(fromParent==toParent) return true;  
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