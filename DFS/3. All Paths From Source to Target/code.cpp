class Solution {
public:
    void dfs(int src,int target,vector<vector<int>>& graph,vector<bool>& visited,vector<vector<int>>& result,vector<int>& temp)
    {
        visited[src]=true;
        temp.push_back(src);
        if(src==target)
        {
            result.push_back(temp);
            visited[src]=false; //Bracktrack
            temp.pop_back();  //Bracktrack
            return;
        }
        for(auto x: graph[src])
        {
            if(visited[x]==false)  dfs(x,target,graph,visited,result,temp);
        }
        visited[src]=false; //Bracktrack
        temp.pop_back();  //Bracktrack
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //Since there may be nodes which could be part of more than one paths.
        //But all we have to ensure that is same node should not be traversed twice in a single path
        //So pass by value type visited array will be used
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<vector<int>> result;
        vector<int> temp;
        dfs(0,n-1,graph,visited,result,temp);
        return result;
    }
};