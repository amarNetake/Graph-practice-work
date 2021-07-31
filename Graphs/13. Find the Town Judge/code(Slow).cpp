class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map<int,bool> notJudge;
        for(auto x: trust)
        {
            notJudge[x[0]]=1;
        }
        if(ma.size()==n) return -1;
        int countJudges=0;
        int judge=-1;
        for(auto x: trust)
        {
            if(notJudge.find(x[1])==notJudge.end() && judge!=x[1])
            {
                countJudges++;
                judge=x[1];
                //Given there should be exactly one judge and also all the rest of people must trust that judge
                //So if there are more than one person that trust nobody then no judge will have trust of n-1
                //people. So we can conclude that there are no judges.
                if(countJudges>1) return -1; 
            }
        }
        for(auto x: trust)
        {
            if(x[1]==judge)
            {
                notJudge.erase(x[0]);
            }
        }
        if(notJudge.size()==0) return judge;
        else return -1;
    }
};