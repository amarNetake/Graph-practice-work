class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,int curr,vector<bool>& visited,unordered_map<int,char>& track,char team,bool& result)
    {
        visited[curr]=true;
        track[curr]=team;
        char teamCurr = team=='A'?'B':'A'; //All the vertices adjacent to current vertex should go in opposite team
        for(auto x: graph[curr])
        {
            if(visited[x]==false)
            {
                dfs(graph,x,visited,track,teamCurr,result);
            }
            else if(visited[x]==true)
            {
                if(track[x]!=teamCurr)
                {
                    result=false;
                    return;
                }
            }
            if(result==false) return;
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        // A graph is bipartite if we can seperate vertices in two different groups and vertices together are 
        // mutually exclusive  and exhaustive that is v(A)+v(B)=Total vertices and A intersection B = NULL
        // Also all the edges must be drawn from any vertex in set A to a vertex in set B and there must not be any
        // edge within vertices of same group.
        
        // To find if given graph is bipartite is by
        // 1) If a graph has no cycle then it can be drwan as bipartite graph always
        // 2) If a graph has a cycle but all the cycles in graph are of even length then it can be drawn as bipartite graph
        // It is not bipartite if given graph has a cycle of odd length.
        
        unordered_map<int,char> track;
        vector<bool> visited(graph.size(),false);
        bool result=true; //Initiallly assuming it is a bipartite graph
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==false)
            {
                dfs(graph,i,visited,track,'A',result);
            }
        }
        return result;
    }
};