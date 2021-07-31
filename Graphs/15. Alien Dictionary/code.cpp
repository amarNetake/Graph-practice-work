class Solution {
public:
    void dfs1(unordered_map<int,vector<int>>&adj,int curr,vector<bool>& visited,vector<bool>& finalVisited,bool& result)
    {
        visited[curr]=true;
        finalVisited[curr]=true;
        for(auto x:adj[curr])
        {
            if(visited[x]==true && finalVisited[x]==true)
            {
                result=true;
                return;
            }
            else if(finalVisited[x]==true && visited[x]==false) continue;
            dfs1(adj,x,visited,finalVisited,result);
            if(result==true) return;
        }
        visited[curr]=false;
    }
    
    bool isCycle(unordered_map<int,vector<int>>& adj)
    {
        vector<bool> visited(26,false);
        vector<bool> finalVisited(26,false);
        bool result=false;
        for(auto x: adj)
        {
            if(finalVisited[x.first]==false)
            {
                dfs1(adj,x.first,visited,finalVisited,result);
                if(result==true) return result;
            }
        }
        return result;
    }
    
    void dfs2(unordered_map<int,vector<int>>& adj,int curr,vector<bool>& visited,stack<int>& s)
    {
        visited[curr]=true;
        for(auto x: adj[curr])
        {
            if(visited[x]==false) dfs2(adj,x,visited,s);
        }
        s.push(curr);
    }
    
    string topologicalSort(unordered_map<int,vector<int>>& adj)
    {
        stack<int> s;
        string result="";
        vector<bool> visited(26);
        for(auto x: adj)
        {
            if(visited[x.first]==false)
            {
                dfs2(adj,x.first,visited,s);
            }
        }
        while(s.empty()==false)
        {
            result.insert(result.end(),s.top()+'a');
            s.pop();
        }
        return result;
    }
    
    string alienOrder(vector<string>& words) {
        unordered_map<int,vector<int>> adj;
        vector<vector<int>>mapped(26,vector<int>(26,0));
        
        //Just to make sure all the letters are traced and part of sequence even those who are disconnected from our graph
        for(auto word: words)
        {
            for(auto ch: word)
            {
                adj[ch-'a']={};
            }
            if(adj.size()==26) break;
        }
        
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                string word1=words[i];
                string word2=words[j];
                int left=0,right=0;
                while(left<word1.size() && right<word2.size())
                {
                    if(word1[left]!=word2[right])
                    {
                        int x=word1[left] - 'a';
                        int y= word2[right] - 'a';
                        if(mapped[x][y]==0)
                        {
                            mapped[x][y]=1;
                            adj[x].push_back(y);
                        }
                        break;
                    }
                    left++,right++;
                }
                if(right==word2.size() && left<word1.size()) return "";
            }
        }
        bool loop= isCycle(adj);
        if(loop==true) return "";
        string result=topologicalSort(adj);
        return result;
    }
};