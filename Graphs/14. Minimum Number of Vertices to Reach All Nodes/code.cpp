class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Basically it is kind of topological sort where we will need 
        // exactly those vertices that are not having any incoming edge.
        
        //Let us create a vector to keep the track of number of incoming edges in a particular vertex
        vector<int> incomingEdges(n,0);
        for(auto x: edges)
        {
            incomingEdges[x[1]]++;
        }
        vector<int> result;
        for(int i=0;i<incomingEdges.size();i++)
        {
            if(incomingEdges[i]==0) result.push_back(i);
        }
        return result;
    }
};