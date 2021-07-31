void dfs(vector<int>& result,vector<vector<int>>& adj,unordered_map<int,bool>& visited,int curr)
{
    result.push_back(curr);
    visited[curr]=true;
    for(auto x: adj[curr])
    {
        if(visited[x]==false) dfs(result,adj,visited,x);
    }
}
   
vector<int> dfsOfGraph(int n, vector<int> vect[]){
    
    vector<int> result;
    unordered_map<int,bool> visited;
    vector<vector<int>> adj(vect,vect+n);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true) continue;
        dfs(result,adj,visited,i);
    }
    return result;
}