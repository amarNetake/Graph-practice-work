/*
 Modified DFS traversal to ensure to visit all nodes and we do not miss nodes which is not having any incoming edge
 or if the graph is disconnected.
*/

void dfsUtil(int curr,vector<int> vect[],vector<int>& result,vector<bool>& visited)
{
    result.push_back(curr);
    visited[curr]=true;
    for(int x: vect[curr])
    {
        if(visited[x]==false)
        {
            dfsUtil(x,vect,result,visited);
        }
    }
}

vector <int> dfs(vector<int> vect[], int n)
{
    // Your code here
    vector<bool> visited(n,false);
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfsUtil(i,vect,result,visited);
        }
    }
    return result;
}