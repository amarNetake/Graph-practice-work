#define map unordered_map<int,unordered_map<int,bool>> 

class Solution {
public:
    bool escapeFromSource(vector<int>& src,vector<int>& tar,bool& catched,vector<vector<int>>& blocked)
    {
        map visited;
        map ma;
        for(auto x: blocked) ma[x[0]][x[1]]=true;
        queue<pair<int,int>> q;
        int dist=0; //If distance becomes > 200 then blocks cannot stop us as there are atmost 200 blocks
        q.push(make_pair(src[0],src[1]));
        visited[src[0]][src[1]]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0) break;
            if(dist>=blocked.size()) return true;
            while(countNodes>0)
            {
                pair<int,int> curr=q.front();
                q.pop();
                int x=curr.first,y=curr.second;
                if(x==tar[0] && y==tar[1])
                {
                    catched=true;
                    return true;
                }
                if(x+1<1e6 && visited[x+1][y]==false && ma[x+1][y]==false) 
                {
                    q.push({x+1,y});
                    visited[x+1][y]=true;
                }
                if(x-1>=0 && visited[x-1][y]==false && ma[x-1][y]==false) 
                {
                    q.push({x-1,y});
                    visited[x-1][y]=true;
                }
                if(y+1<1e6 && visited[x][y+1]==false && ma[x][y+1]==false) 
                {
                    q.push({x,y+1});
                    visited[x][y+1]=true;
                }
                if(y-1>=0 && visited[x][y-1]==false && ma[x][y-1]==false) 
                {
                    q.push({x,y-1});
                    visited[x][y-1]=true;
                }
                countNodes--;
            }
            dist++;
        }
        return false;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& src, vector<int>& tar) {
        if(src[0]==tar[0] && src[1]==tar[1]) return true;
        
        bool catched=false; //When we will catch the target
        bool temp1= escapeFromSource(src,tar,catched,blocked);
        if(catched==true) return true;
        else if(temp1==false) return false;
        bool temp2= escapeFromSource(tar,src,catched,blocked);  //Note that here we changed the order of src and tar now source is target and vice versa
        if(temp1==true && temp2==true) return true;
        return false;
    }
};