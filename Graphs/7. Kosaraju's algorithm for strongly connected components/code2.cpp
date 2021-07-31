class Solution
{
	public:
	void dfs1(int src,vector<int> adj[],stack<int>& s,vector<bool>& visited)
	{
	    if(visited[src]==true) return;
	    visited[src]=true;
	    for(auto x: adj[src])
	    {
	        dfs1(x,adj,s,visited);
	    }
	    s.push(src);
	}
	
	void dfs2(int src,vector<vector<int>>& adj2,vector<bool>& visited)
	{
	    if(visited[src]==true)  return;
	    visited[src]=true;
	    for(auto x: adj2[src])
	    {
	        dfs2(x,adj2,visited);
	    }
	}
	
	void reverse(vector<int> adj[],vector<vector<int>>& adj2,int n)
	{
	    for(int i=0;i<n;i++)
	    {
	        for(auto x: adj[i])
	        {
	            adj2[x].push_back(i);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        vector<bool> visited(n,false);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs1(i,adj,s,visited);
            }
        }
        vector<vector<int>> adj2(n);
        reverse(adj,adj2,n);
        int count=0;
        fill(visited.begin(),visited.end(),false); //Reinitializing visited array to all false
        while(s.empty()==false)
        {
            int curr=s.top();
            s.pop();
            if(visited[curr]==true) continue;
            count++; //If curr is not visited implies it is part of another new SCC
            dfs2(curr,adj2,visited);
        }
        return count;
    }
};