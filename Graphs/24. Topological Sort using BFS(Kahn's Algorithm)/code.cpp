class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(n,0);
	    //Count the indegree of each node
	    for(int i=0;i<n;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    queue<int> q;
	    //Store the nodes with 0 indegree in queue
	    for(int i=0;i<n;i++) 
	    {
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int> result;
	    int countNodes;
	    while(1)
	    {
	        countNodes=q.size();
	        if(countNodes==0) break;
	        while(countNodes>0)
	        {
	            int curr=q.front();
	            q.pop();
	            result.push_back(curr);
	            for(auto x: adj[curr])
	            {
	                indegree[x]--;
	                if(indegree[x]==0) q.push(x);
	            }
	            countNodes--;
	        }
	    }
	    return result;
	}
};