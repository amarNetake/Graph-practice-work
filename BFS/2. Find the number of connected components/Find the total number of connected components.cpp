// BFS traversal in directed graph( If the condition is to visit all the nodes) 


/*
	This is the best way when there are more than 1 components in the graph or the graph is disconnected. This will help to traverse 
	entire graph.
*/
void bfsUtil(int item,vector<int> vect[],vector<bool>& visited,vector<int>& result,int n)
{
    queue<int> q;
    q.push(item);
    visited[item]=true;
    int countNodes=0;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        while(countNodes>0)
        {
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for(int x:vect[curr])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true;
                }
            }
            countNodes--;
        }
    }
}

int bfs(vector<int> vect[], int n) {

    // Your code here
    vector<bool> visited(n,false);
    int count=0;		//This will hold the count of total connected components or total number of disconnected components
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
        	count++;  
            bfsUtil(i,vect,visited,result,n);
        }
    }
    return count;
}