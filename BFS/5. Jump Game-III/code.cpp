    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(start);
        visited[start]=true;
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)
            {
                break;
            }
            while(countNodes>0)
            {
                int index=q.front();
                q.pop();
                if(arr[index]==0)
                {
                    return true;
                }
                if(index+arr[index]<=n-1 && visited[index+arr[index]]==false)
                {
                    q.push(index+arr[index]);
                    visited[index+arr[index]]=true;
                }
                if(index-arr[index]>=0 && visited[index-arr[index]]==false)
                {
                    q.push(index-arr[index]);
                    visited[index-arr[index]]=true;
                }
                countNodes--;
            }
        }
        return false;
    }