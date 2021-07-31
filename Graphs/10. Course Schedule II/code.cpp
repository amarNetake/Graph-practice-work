class Solution {
public:
    
    void addEdge(vector<int> adj[],int x,int y)
    {
        adj[x].push_back(y);
    }
    
    bool dfs(vector<int> adj[],unordered_map<int,bool>& visited,unordered_map<int,bool>& record,int curr,stack<int>& s)
    {
        if(visited[curr]==false)
        {
            visited[curr]=true;
            record[curr]=true;
        }
        for(int x: adj[curr])
        {
            if(visited[x]==false && dfs(adj,visited,record,x,s)==true)  return true;
            
            else if(record[x]==true)  return true;
        }
        record[curr]=false;
        s.push(curr);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        if(n==1)
        {
            return {0};
        }
        vector<int> adj[n];
        for(auto x: prerequisites)
        {
            addEdge(adj,x[0],x[1]);
        }
        
        stack<int> s;
        unordered_map<int,bool> visited;
        unordered_map<int,bool> record;
        bool cycle=false;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)  continue;
            cycle=dfs(adj,visited,record,i,s);
            if(cycle==true)  return {};
        }
        vector<int> result;
        while(s.empty()==false)
        {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());  // since u->v means u is dependent on v so v must be completed first and then u
        return result;
    }
};