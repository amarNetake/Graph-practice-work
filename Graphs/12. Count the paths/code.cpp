void dfs(vector<vector<int>>& adj,int s,int d,int n,vector<bool> visited,int& count)
{
    if(visited[s]==true) return;
    visited[s]=true;
    if(s==d)
    {
        count+=1;
        return;
    }
    for(auto x: adj[s])
    {
        dfs(adj,x,d,n,visited,count);
    }
    
}
   
int possible_paths(vector<vector<int>>edges, int n, int s, int d)  //Driver function
{
    // Code here
    vector<bool> visited(n,false);
    int count=0;
    vector<vector<int>> adj(n);
    for(auto x: edges)
    {
        adj[x[0]].push_back(x[1]);
    }
    
    dfs(adj,s,d,n,visited,count);
    return count;
}