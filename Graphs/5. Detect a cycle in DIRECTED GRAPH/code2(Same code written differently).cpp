class Solution
{
    public:
    
    void dfs(int s,vector<int> adj[],vector<bool>& visited,vector<bool>& fullyVisited,bool& result)
    {
        if(visited[s]==true) 
        {
            result=true;
            return;
        }
        visited[s]=true;
        fullyVisited[s]=true;
        for(auto x: adj[s])
        {
            if(fullyVisited[x]==false) 
            {
                dfs(x,adj,visited,fullyVisited,result);
                if(result==true) return;
            }
            else if(fullyVisited[x]==true && visited[x]==true) 
            {
                result=true;
                return;
            }
        }
        visited[s]=false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int n, vector<int> adj[]) 
	{
	   	vector<bool> visited(n,false);
	   	vector<bool> fullyVisited(n,false);
	   	bool result=false;
	   	for(int i=0;i<n;i++)
	   	{
	   	    if(fullyVisited[i]==false)
	   	    {
	   	        dfs(i,adj,visited,fullyVisited,result);
	   	        if(result==true) return result;
	   	    }
	   	}
	   	return result;
	}
};