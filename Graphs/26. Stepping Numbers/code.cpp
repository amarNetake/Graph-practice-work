class Solution {
public:
    //No need of visited array here as we may want to get 121 or 1232 etc.
    //The escape logic is when num>B as num>=A and num<=B we cannot escape when num<A as it will aggregate and grow to come in range but
    //Surely can escape to come out when 
    void dfs(set<long int>& result,long int curr,vector<vector<int>>& adj,long int num,int A,int B)
    {
        if(num>B) return;
        num=num*10+curr;
        if(num>=A && num<=B) result.insert(num);
        for(auto x: adj[curr])
        {
            dfs(result,x,adj,num,A,B);
        }
    }
    
    vector<int> countSteppingNumbers(int A, int B) {
        vector<vector<int>> adj(10);
        for(int i=0;i<9;i++)
        {
            adj[i].push_back(i+1);
        }
        for(int i=9;i>0;i--)
        {
            adj[i].push_back(i-1);
        }
        set<long int> result;
        for(long int i=0;i<=9;i++)
        {
            long int num=0;
            dfs(result,i,adj,num,A,B);
        }
        vector<int> output;
        for(auto x: result)
        {
            output.push_back(x);
        }
        return output;
    }
};