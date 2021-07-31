/*
    Note:-
    1. Here we are considering for BFS traversal on directed graph only through node 0.
    2. Here it is not mandatory to visit all the nodes. So it may be possible few nodes are node reachable through node 0
       those nodes shall be skipped.
    3. Iff it was asked or question demanded to visit all nodes through BFS then only we would have used the code2 in the
       current folder.
*/

vector <int> bfs(vector<int> vect[], int n)   //BFS with starting node 0. Skip those which are not reachable
{

    // Your code here
    vector<bool> visited(n,false);
    vector<int> result;
    queue<int> q;
    q.push(0);

    /*
        Note that we need to mark visited[item]=true as soon 
        as we push it in queue to avoid to push it multiple times before processing it.
    */
    visited[0]=true;  
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
            for(int x: vect[curr])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true; //As soon as item pushed to queue mark visited[item]=1 to avoid multiple pushes before processing
                }
            }
            countNodes--;
        }
    }
    return result;
}