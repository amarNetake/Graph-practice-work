bool isCyclicUtil(vector<int> adj[],unordered_map<int,bool>& visited,unordered_map<int,bool>& record,int curr)
{
    if(visited[curr]==false)
    {
        visited[curr]=true;
        record[curr]=true;  //This is needed to be backtracked whenever the current iteration ends as it holds status only of  current DFS 
    }
    for(int x:adj[curr])
    {
        /*
            If visited[x]==false then definately for sure record[x]==false. So x will be visited for the first time
            If visited[x]==true then 
                1. if record[x]==false   implies x was visited in previous dfs not in current dfs so simply return
                2. if record[x]==true    implies x is visited 2 times in the current dfs implies there exists a cycle
        */
        if(visited[x]==false && isCyclicUtil(adj,visited,record,x)==true) return true;
        
        /*
            Control will reach in below elseif only reach here if 
             1. visited[x]==true  -> In this case record[x] may be true or may be false. If record[x]==true then we detected a cycle
             2. visited[x]==false && isCyclicUtil(x)==false  -> In this case it will backtrack and record[x] will be having false
        */
        else if(record[x]==true) return true;  // This will be returning true iff (visited[x]==true && record[x]==true)
    }
    record[curr]=false;      // Backtrack
    return false;
}

bool isCyclic(int n, vector<int> adj[])   // main() calls this function
{
    // Your code here
    unordered_map<int,bool> visited;  // This will hold the nodes that are visited in all previous iterations
    unordered_map<int,bool> record;  //This will hold the status of current DFS traversal
    bool result=false;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            result=isCyclicUtil(adj,visited,record,i);
            if(result==true) return true;
        }
    }
    return false;
}