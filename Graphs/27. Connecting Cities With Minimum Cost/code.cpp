class Solution {
public:
    int solve(vector<vector<pair<int,int>>>& adj,int n)
    {
        vector<int> minCost(n+1,INT_MAX); //This is to avoid feeding priority queue with unnecessary vertices which for sure are not the optimal
        vector<bool> visited(n+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int countVisits=0; //If at the end it becomes n implies we visited all nodes
        pq.push({0,1});
        int totalDist=0;
        int countNodes;
        while(1)
        {
            countNodes=pq.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                pair<int,int> curr=pq.top();
                pq.pop();
                if(visited[curr.second]==true) 
                {
                    countNodes--;
                    continue;
                }
                visited[curr.second]=true;
                countVisits++;
                totalDist=totalDist + curr.first;
                for(auto x: adj[curr.second])
                {
                    if(visited[x.first]==false && minCost[x.first]>x.second) 
                    {
                        pq.push({x.second,x.first});
                        minCost[x.first]=x.second; 
                    }
                }
                countNodes--;
            }
        }
        if(countVisits==n) return totalDist;
        return -1;
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n+1); //Since cities are numbered from 1 to n and not 0 to n-1
        for(auto x: connections)
        {
            //Undirected edges
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int result=solve(adj,n);
        return result;
    }
};