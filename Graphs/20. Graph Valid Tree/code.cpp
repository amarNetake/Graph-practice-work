class Solution {
public:
    void dfs(vector<vector<int>>& adj,int curr,int parent,unordered_map<int,bool>& visited,bool& cycle)
    {
        visited[curr]=true;
        for(auto x: adj[curr])
        {
            if(visited[x]==true)
            {
                if(x!=parent)
                {
                    cycle=true;
                    return;
                }
            }
            else dfs(adj,x,curr,visited,cycle);
        }
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //A graph is a tree if all nodes are accessible or graph is fully connected and has no cycles.
        vector<vector<int>> adj(n);
        for(auto x: edges) 
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        unordered_map<int,bool> visited;
        bool cycle=false;
        dfs(adj,0,-1,visited,cycle);
        if(cycle==true) return false;
        if(visited.size()==n) return true;
        return false;
    }
};