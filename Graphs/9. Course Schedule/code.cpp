/*
		This question is all about whether we can apply topological sort on it or not. 
		As we know topological sort can only be applied on directed acyclic graph.
		So we will detect for cycle. If there exists a cycle we will simply say that we cannot schedule the course
*/

class Solution {
public:
    
    void addEdge(vector<int> adj[],int x,int y)
    {
        adj[x].push_back(y);
    }
    
    bool dfs(vector<int> adj[],unordered_map<int,bool>& visited,unordered_map<int,bool>& record,int curr)
    {
        if(visited[curr]==false)
        {
            visited[curr]=true;
            record[curr]=true;
        }
        for(int x:adj[curr])
        {
            if(visited[x]==false && dfs(adj,visited,record,x)==true)  return true;
            
            else if(record[x]==true)  return true;
        }
        record[curr]=false;    //backtrack
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[n];  //We first need to create the adjacency list
        for(auto x: prerequisites)
        {
            addEdge(adj,x[0],x[1]);
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> record;
        bool result=false;     //result will hold if there is loop result==false => no loop => course schedule possible as topological sort possible
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)  continue;
            result=dfs(adj,visited,record,i);
            if(result==true)   return false;   //result=true implies cycle detected and topological sort fails for cycles
        }
        
        return true;   //No cycle detected implies we can complete the whole course
    }
};