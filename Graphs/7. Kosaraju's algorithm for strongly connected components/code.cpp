void dfs(vector<int> adj[],unordered_map<int,bool>& visited,stack<int>& s,int curr)
{
    visited[curr]=true;
    for(int x:adj[curr])
    {
        if(visited[x]==false)
        {
            dfs(adj,visited,s,x);
        }
    }
    s.push(curr);
}

void transposeGraph(vector<int> adj[],vector<int> transpose[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int x: adj[i])
        {
            transpose[x].push_back(i);
        }
    }
}

void dfsOnTransposeGraph(vector<int> transpose[],unordered_map<int,bool>& visited,int curr)
{
    visited[curr]=true;
    for(int x:transpose[curr])
    {
        if(visited[x]==false)
        {
            dfsOnTransposeGraph(transpose,visited,x);
        }
    }
}

int kosaraju(int n, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(adj,visited,s,i);
        }
    }
    vector<int> transpose[n];
    
    transposeGraph(adj,transpose,n);
    
    visited.clear();    // clear the visited for next use.
    int count=0;
    while(s.empty()==false)
    {
        int x=s.top();
        s.pop();
        if(visited[x]==false)
        {
            dfsOnTransposeGraph(transpose,visited,x);
            count++;
        }
    }
    return count;
}