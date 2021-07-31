// True => cycle detected    ;    False => cycle not detected
bool isCyclicUtil(vector<int> adj[],unordered_map<int,bool>& visited,int curr,int parent)
{
    visited[curr]=true;
    for(int x: adj[curr])
    {
        if(visited[x]==true && x!=parent) return true;   // Cycle Detected
        else if(visited[x]==true && x==parent) continue;
        if(isCyclicUtil(adj,visited,x,curr)==true)  return true;     // Cycle Detected
    }
    return false;   
}

bool isCyclic(vector<int> adj[], int n)
{
   // Your code here
   unordered_map<int,bool> visited;
   bool result;
   for(int i=0;i<n;i++)  //Applied loop just coz there may exist some disconnected components
   {
       if(visited[i]==false)
       {
           result=isCyclicUtil(adj,visited,0,-1);
           if(result==true) return result;
       }
   }
   return result;
}