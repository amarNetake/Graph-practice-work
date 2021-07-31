//Using Dijkstra's algorithm (BFS + Priority Queue)
class compare{
    public:
        bool operator()(const tuple<int,int,int> a,const tuple<int,int,int> b) 
        {
            if(get<0>(a)==get<0>(b)) return get<1>(a)>=get<1>(b);  //a[2]->curr node; a[0]->total distance; a[1]->total jumps from source till a[2]
            return get<0>(a) > get<0>(b);  //get<i>(a) returns the a[i]
        }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x: flights)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        unordered_map<int,int> visited;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,compare> pq;
        pq.push(make_tuple(0,0,src));
        int round=0;
        while(!pq.empty())
        {
            auto [cost,stops,node]=pq.top();
            pq.pop();
            if(node==dst) return cost; //Checking this first as jump to destination will not be considered as  a jump
            if(stops>k) continue;
            if(visited.find(node)!=visited.end() && visited[node]<=stops) continue;
            visited[node]=stops;
            for(auto x:adj[node])
            {
                auto [nextNode,edgeCost]=x;
                pq.push(make_tuple(cost+edgeCost,stops+1,nextNode));
            }
        }
        return -1;
    }
};