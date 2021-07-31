#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>& adj,unordered_map<int,int>& visited,int curr,int parent,bool& result,int dist)
{
    visited[curr]=dist;
    for(auto x: adj[curr])
    {
        if(x==parent) continue;
        if(visited.find(x)!=visited.end())
        {
            if((dist+1-visited[x])%2==1)
            {
                result=false;
                return;
            }
        }
        else   dfs(adj,visited,x,curr,result,dist+1);
        if(result==false) return;
    }
}


bool findOddLoop(vector<vector<int>>& links,int mid)
{
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<=mid;i++)
    {
        auto x=links[i];
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    unordered_map<int,int> visited; // key->it's distance from source node
    bool result=true;
    for(auto x: adj)
    {
        if(visited.find(x.first)==visited.end())  dfs(adj,visited,x.first,-1,result,0);
        if(result==false) return result;
    }
    return result;
}

int bSearch(vector<vector<int>>& links,int n,int m)
{
    int start=0,end=m-1;
    int result=1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        bool temp=findOddLoop(links,mid);
        if(temp==false) //Not bipartite
        {
            end=mid-1;
        }
        else  //Bipartite till mid
        {
            result=mid;
            start=mid+1;
        }
    }
    return result+1;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> links;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            links.push_back({x,y});
        }
        int result=bSearch(links,n,m);
        cout<<result<<"\n";
    }
    return 0;
}