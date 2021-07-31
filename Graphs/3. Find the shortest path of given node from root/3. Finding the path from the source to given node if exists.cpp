/*
	d[i] will signify the shortest distance of i from the root
	p[i] will signify the parent of node i
	s will be the source vertex
	n will be number of nodes
*/

void BFS(int s,vector<bool>& used,vector<int>& p,int n)
	vector<vector<int>> adj;  // adjacency list representation
	int n; // number of nodes
	queue<int> q;
	vector<int> d(n,0); 
	
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            q.push(u);
	            used[u] = true;
	            d[u] = d[v] + 1;
	            p[u] = v;
	        }
	    }
	}

//If we have to restore and display the shortest path from the source to some vertex u, it can be done in the following manner:

vector<int> printShortestPath(int u,int s,int n)  //u-target node; s-source node; n-Number of nodes
{
	vector<bool> used(n);
	vector<int> p(n);  //p[i] will hold the parent of node i.
	BFS(s,used,p,n);
	if (!used[u]) // If after BFS through source node still the node u is not visited implies there is no path to u from s
	{
	    return {};  //No path exist
	} 
	else 
	{
	    vector<int> path;
	    for (int v = u; v != -1; v = p[v])//From node u traverse p[] array in reverse direction(from index u to the index whose value is -1)
	        path.push_back(v);
	    reverse(path.begin(), path.end());
	}
	return path;
}
