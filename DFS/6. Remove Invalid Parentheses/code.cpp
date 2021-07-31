class Solution {
public:
    bool isValid(string str)
    {
        int count=0;
        for(auto ch: str)
        {
            if(ch==')') count--;
            else if(ch=='(') count++;
            if(count<0) return false;
        }
        return count==0?true:false;
    }
    
    int findMinLen(string str)
    {
        if(str.length()<2) return 0;
        stack<int> s;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
            {
                s.push(i);
            }
            else if(str[i]==')')
            {
                if(s.empty()==true)
                {
                    s.push(i);
                }
                else if(str[s.top()]=='(')
                {
                    s.pop();
                }
                else if(str[s.top()]==')')
                {
                    s.push(i);
                }
            }
        }
        return s.size();
    }
    vector<string> removeInvalidParentheses(string str)  //driver function
    {
        int n=findMinLen(str);
        vector<string> result;
        unordered_map<string,bool> marked;
        dfs(str,n,result,marked);
        if(result.size()==0) result.push_back("");
        return result;
    }
    
    void dfs(string& str,int n,vector<string>& result,unordered_map<string,bool>& marked)
    {
        if(n==0)
        {
            if(marked[str]==false && isValid(str)==true)
            {
                result.push_back(str);
                marked[str]=true;
                return;
            }
        }
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!='(' && str[i]!=')') continue;
            string curr;
            if(i==0) curr=str.substr(i+1);
            else if(i==str.length()-1) curr=str.substr(0,i);
            else curr=str.substr(0,i)+str.substr(i+1);
            if(marked[curr]==true) continue;
            dfs(curr,n-1,result,marked);
            marked[curr]=true;
        }
    }
};