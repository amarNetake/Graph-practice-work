class Solution {
public:
    
    void dfs(string curr,string parent,string target,double& answer,unordered_map<string,vector<pair<string,double>>>& adj,unordered_map<string,bool>& visited,double value )
    {
        if(curr==target)
        {
            answer=value;
            return;
        }
        visited[curr]=true;
        for(auto x: adj[curr])
        {
            if(x.first!=parent && visited[x.first]==false)
            {
                dfs(x.first,curr,target,answer,adj,visited,value*x.second);
                if(answer!=-1) return;
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>> adj;
        unordered_map<string,bool> mapped;
        for(int i=0;i<equations.size();i++)
        {
            string str1=equations[i][0];
            string str2=equations[i][1];
            mapped[str1]=true;
            mapped[str2]=true;
            adj[str1].push_back(make_pair(str2,values[i]));
            adj[str2].push_back(make_pair(str1,1/values[i]));
        }
        
        vector<double> result;
        for(auto x: queries)
        {
            string str1=x[0];
            string str2=x[1];
            if(mapped[str1]==false || mapped[str2]==false) result.push_back(-1);
            else if(str1==str2)   result.push_back(1); 
            else
            {
                unordered_map<string,bool> visited;
                double answer=-1;
                dfs(str1,"",str2,answer,adj,visited,1);
                result.push_back(answer);
            }
        }
        return result;
    }
};