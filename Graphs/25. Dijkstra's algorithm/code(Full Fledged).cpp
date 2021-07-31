#include<bits/stdc++.h>
using namespace std;

class status{
    public:
        int distance;
        int Node;
        string path="";
};

class compare{
    public:
        bool operator()(const status a,const status b){
            if(a.distance==b.distance) return a.Node>=b.Node;
            return a.distance>=b.distance;
        }
};

void shortestDistFromSouce(vector<vector<pair<int,int>>>& adj,int n,int source)
{
    /*
        minHeap x.first -> Distance from source ; x.second -> current Node. minheap with respect to distances from source
    */
    priority_queue<status,vector<status>, compare> pq; 
    vector<bool> visited(n,false);
    status s;
    s.Node=source;
    s.path=to_string(source);
    s.distance=0;
    pq.push(s);
    while(pq.empty()==false)
    {
        status curr=pq.top();  //curr.first will be distance from source and curr.second will be node
        pq.pop();
        if(visited[curr.Node]==true) continue;
        cout<<curr.Node<<" via "<<curr.path<<" @ "<<curr.distance<<"\n";
        visited[curr.Node]=true;
        for(auto x:adj[curr.Node])
        {
            if(visited[x.first]==false) 
            {
                status s;
                s.path=curr.path+to_string(x.first);
                s.Node=x.first;
                s.distance=curr.distance+x.second;
                pq.push(s);
            }
        }
    }
}

int main()
{
    int n,e;  // n->number of edges ; e->number of vertices
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++)
    {
        int v1,v2,w; // v1->vectex 1 ; v2->vectex 2 ; w->weight of edge
        cin>>v1>>v2>>w;
        //weighted undirected graph
        adj[v1].push_back(make_pair(v2,w));
        adj[v2].push_back(make_pair(v1,w));
    }
    int source;
    cin>>source;
    shortestDistFromSouce(adj,n,source);
}

