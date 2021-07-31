class Solution {
public:
    // Basically we need to calculate total number of disconnected components of given graph
    void dfs(vector<vector<int>>& isConnected,int curr,unordered_map<int,bool>& visited)
    {
        
        visited[curr]=true;
        for(int i=0;i<isConnected[curr].size();i++)
        {
            if(isConnected[curr][i]==1 && visited[i]==false)
            {
                dfs(isConnected,i,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int n=isConnected.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true) continue;
            count++;
            dfs(isConnected,i,visited);
        }
        return count;
    }
};