class Solution 
{
    public:
    void dfs(int s,vector<int> adj[],vector<int>& visited,vector<bool>& fullyVisited,bool& result,int parent)
    {
        visited[s]+=1;
        fullyVisited[s]=true;
        if(visited[s]==2)
        {
            result=true;  //Cycle detected
            return;
        }
        for(auto x: adj[s])
        {
            if(x!=parent) dfs(x,adj,visited,fullyVisited,result,s); //Since a single edge is not a cycle.
            if(result==true) return;
        }
        visited[s]-=1; //Backtrack
    }
    
	bool isCycle(int n, vector<int>adj[])
	{
	    // 0->Not visited, 1->Visited, 2-> Revisited(Cycle)
	    vector<int> visited(n,0);
	    vector<bool> fullyVisited(n,false);
	    bool result=false;
	    for(int i=0;i<n;i++)
	    {
	        if(fullyVisited[i]==false)  //To traverse each disjoint components
	        {
	            dfs(i,adj,visited,fullyVisited,result,-1);
	            if(result==true) return result;
	        }
	    }
	    return result;
	}
};