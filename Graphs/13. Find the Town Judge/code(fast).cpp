class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<bool> notJudge(n+1,false);
        vector<int> followers(n+1,0);
        for(auto x: trust)
        {
            notJudge[x[0]]=true;
            followers[x[1]]++;
        }
        int countJudges=0;
        int judge=-1;
        for(int i=1;i<=n;i++)
        {
            if(followers[i]==n-1 && notJudge[i]==false)
            {
                countJudges++;
                judge=i;
                if(countJudges>1) return -1;
            }
        }
        return judge;
    }
};