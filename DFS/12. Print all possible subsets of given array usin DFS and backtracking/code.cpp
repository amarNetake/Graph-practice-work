void dfs(vector<int>& nums,vector<vector<int>>&subset,int n,int curr,vector<int>& result)
    {
        subset.push_back(result);
        for(int i=curr;i<n;i++)
        {
            result.push_back(nums[i]);
            dfs(nums,subset,n,i+1,result);
            result.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) // main() calls this function
    {
        vector<vector<int>> subset;
        int n=nums.size();
        vector<int> result={};
        dfs(nums,subset,n,0,result);
        return subset;
    }