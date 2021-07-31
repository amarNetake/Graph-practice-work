class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int totalRooms=rooms.size();
        unordered_map<int,bool> visited;
        
        q.push(0);
        visited[0]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            while(countNodes>0)
            {
                int curr=q.front();
                q.pop();
                for(auto x: rooms[curr])
                {
                    if(visited[x]==false)
                    {
                        q.push(x);
                        visited[x]=true;
                    }
                }
                countNodes--;
            }
        }
        if(visited.size()==totalRooms) return true;
        return false;
    }
};