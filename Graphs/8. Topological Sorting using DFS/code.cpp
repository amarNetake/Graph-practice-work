void dfs(vector<int> adj[],unordered_map<int,bool>& visited,int curr,stack<int>& s)
{
    visited[curr]=true;
    for(int x: adj[curr])
    {
        if(visited[x]==true)  continue;
        dfs(adj,visited,x,s);
    }
    s.push(curr);
}

vector<int> topoSort(int n, vector<int> adj[]) {
    // Your code here
    
    unordered_map<int,bool> visited;
    stack<int> s;
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true)  continue;
        dfs(adj,visited,i,s);
    }
    
    while(s.empty()==false)
    {
        result.push_back(s.top());
        s.pop();
    }
    
    /*
            NOTE:-
             If you are given u->v implies 'v' must be done after 'u' or 'v' is dependent on u then simply return
             If you are givne u->v implies 'u' is dependent on 'u' then to do v you must complete 'v' then you must reverse the result
    */
    
    
    //reverse(result.begin(),result.end()); --> Do this is u->v implies 'u' is dependent on 'v' or 'v' must be done before 'u'
    return result;
}