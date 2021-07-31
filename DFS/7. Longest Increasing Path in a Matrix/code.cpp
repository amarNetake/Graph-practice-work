class Solution {
public:
    int dfs(vector<vector<int>>& dp,vector<vector<int>>& matrix,int i,int j)
    {
        if(dp[i][j]>0) return dp[i][j];
        int dir1=0,dir2=0,dir3=0,dir4=0;
        if(i>0 && matrix[i-1][j]>matrix[i][j]) dir1=dfs(dp,matrix,i-1,j);
        if(i<matrix.size()-1 && matrix[i+1][j]>matrix[i][j]) dir2=dfs(dp,matrix,i+1,j);
        if(j>0 && matrix[i][j-1]>matrix[i][j]) dir3=dfs(dp,matrix,i,j-1);
        if(j<matrix[0].size()-1 && matrix[i][j+1]>matrix[i][j]) dir4=dfs(dp,matrix,i,j+1);
        dp[i][j]=max({dir1,dir2,dir3,dir4})+1;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]>0)
                {
                    maxLen=max(maxLen,dp[i][j]);
                    continue;
                }
                else
                {
                    dp[i][j]=dfs(dp,matrix,i,j);
                    maxLen=max(maxLen,dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};