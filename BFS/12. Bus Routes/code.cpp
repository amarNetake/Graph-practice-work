class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,set<int>> stopRoutes;
        for(int i=0;i<routes.size();i++)
        {
            for(auto j:routes[i])
            {
                /*
                    i will be the id of the route which in turn is the index of route in routes array.
                    So we are using index of route as the id of that route
                */
                stopRoutes[j].insert(i);  
            }
        }
        unordered_map<int,bool> visited; //Route completely visited or not
        queue<pair<int,int>> q;
        q.push(make_pair(source,0)); //x.first-> stop ; x.second-> Number of routes in which current stop falls
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                auto [curr,totalStops]=q.front();
                q.pop();
                if(curr==target) return totalStops;
                for(auto x:stopRoutes[curr])
                {
                    if(visited.find(x)!=visited.end()) continue;
                    for(auto k:routes[x])
                    {
                        q.push(make_pair(k,totalStops+1));
                    }
                    visited[x]=true; //All the stops of route x are processed so mark route x visited
                }
                countNodes--;
            }
        }
        return -1;
    }
};