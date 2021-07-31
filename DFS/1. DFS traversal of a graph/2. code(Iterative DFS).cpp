vector <int> dfs(vector<int> adj[], int n)
{
    
    // Your code here
    stack<int> s;
    unordered_map<int,bool> visited;
    vector<int> result;
    s.push(0);
    while(s.empty()==false)
    {
        int curr=s.top();
        s.pop();
        if(visited[curr]==false)
        {
            result.push_back(curr);
            visited[curr]=true;
            for(int i=adj[curr].size()-1;i>=0;i--)   //pushing the items in reverse order as stack is LIFO 
            {
                s.push(adj[curr][i]);
            }
        }
    }
    return result;
}