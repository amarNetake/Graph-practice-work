int shortestPath(vector<vector<int>>& vect, int k) {
        int n=vect.size();
        int m=vect[0].size();
        queue<pair<int,int>> q;  //To store the location of current position in grid
        /*
            We need a 2-D vector "visited" of pair of boolean to specify if visited already 
            and number of obstacles faced to reach there as there could be multiple paths to reach to that node and
            we need to consider the current status to be considering all such paths as the cases can be as follows:-
            1. We can visit to current node from the node who had suffered more obstacles but the path through the previous
               node to current node till the destination could be the lowest and obstacles could be inbound(less than k) then
               we shall consider that possiblility as well.
            2. We can visit to current node from the node who had suffered more obstacles and the path through the previous
               node to current node till the destination could be the lowest but obstacles could be out of bound(more than k) then
               we shall consider the path to current node through any other node as well even if that node is already visited and
               the path through this node may be longer and have lesser obstacles in the path.
            3. We can visit the destination through multiple paths in that case whichever reaches the first be it have faced more
               number of obstacles or be it has faced lesser number of obstacles we will consider that path.
            4. We can visit position (x,y) through many paths but some paths may be reaching to the destination and some may not
               be reaching to the destination in that case we need to consider the shortest path that reaches the destination so
               it is needed to push (x,y) in queue multiple times in case we reached the (x,y) with lesser obstacles than through
               previous node then we push (x,y) in queue again and updating the total obstacles it faced.
            5. BFS is level order traversal so whichever path reaches first to destination will be the shortest path by itself
               from the source.
        */
        vector<vector<pair<bool,int>>> visited(n,vector<pair<bool,int>>(m));  
        q.push(make_pair(0,0));
        visited[0][0]=make_pair(true,0);
        int distance=0;
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
                pair<int,int> temp=q.front();
                q.pop();

                //If the current position is reached by facing obstacles more than k then omit
                if(visited[temp.first][temp.second].second>k)
                {
                    countNodes--;
                    continue;
                }

                //If we reached the destionation then return the distance traversed to reach as whichever path reaches first
                //to this will be the shortest path.
                if(temp.first==n-1&&temp.second==m-1)
                {
                    return distance;
                }
                
                if(temp.first<n-1)
                {
                    if(visited[temp.first+1][temp.second].first==false)
                    {
                        if(vect[temp.first+1][temp.second]==1)
                        {
                            q.push(make_pair(temp.first+1,temp.second));
                            visited[temp.first+1][temp.second]=make_pair(true,visited[temp.first][temp.second].second+1);
                        }
                        else
                        {
                            q.push(make_pair(temp.first+1,temp.second));
                            visited[temp.first+1][temp.second]=make_pair(true,visited[temp.first][temp.second].second);
                        }
                    }
                    else if(visited[temp.first+1][temp.second].first==true)
                    {
                        if(vect[temp.first+1][temp.second]==1)
                        {
                            if(visited[temp.first+1][temp.second].second>visited[temp.first][temp.second].second+1)
                            {
                                q.push(make_pair(temp.first+1,temp.second));
                                visited[temp.first+1][temp.second].second=visited[temp.first][temp.second].second+1;
                            }
                        }
                        else if(vect[temp.first+1][temp.second]==0)
                        {
                            if(visited[temp.first+1][temp.second].second>visited[temp.first][temp.second].second)
                            {
                                q.push(make_pair(temp.first+1,temp.second));
                                visited[temp.first+1][temp.second].second=visited[temp.first][temp.second].second;
                            }
                        }
                    }
                }
                if(temp.second<m-1)
                {
                    if(visited[temp.first][temp.second+1].first==false)
                    {
                        if(vect[temp.first][temp.second+1]==1)
                        {
                            q.push(make_pair(temp.first,temp.second+1));
                            visited[temp.first][temp.second+1]=make_pair(true,visited[temp.first][temp.second].second+1);
                        }
                        else
                        {
                            q.push(make_pair(temp.first,temp.second+1));
                            visited[temp.first][temp.second+1]=make_pair(true,visited[temp.first][temp.second].second);
                        }
                    }
                    else if(visited[temp.first][temp.second+1].first==true)
                    {
                        if(vect[temp.first][temp.second+1]==1)
                        {
                            if(visited[temp.first][temp.second+1].second>visited[temp.first][temp.second].second+1)
                            {
                                q.push(make_pair(temp.first,temp.second+1));
                                visited[temp.first][temp.second+1].second=visited[temp.first][temp.second].second+1;
                            }
                        }
                        else if(vect[temp.first][temp.second+1]==0)
                        {
                            if(visited[temp.first][temp.second+1].second>visited[temp.first][temp.second].second)
                            {
                                q.push(make_pair(temp.first,temp.second+1));
                                visited[temp.first][temp.second+1].second=visited[temp.first][temp.second].second;
                            }
                        }
                    }
                }
                if(temp.first>0)
                {
                    if(visited[temp.first-1][temp.second].first==false)
                    {
                        if(vect[temp.first-1][temp.second]==1)
                        {
                            q.push(make_pair(temp.first-1,temp.second));
                            visited[temp.first-1][temp.second]=make_pair(true,visited[temp.first][temp.second].second+1);
                        }
                        else
                        {
                            q.push(make_pair(temp.first-1,temp.second));
                            visited[temp.first-1][temp.second]=make_pair(true,visited[temp.first][temp.second].second);
                        }
                    }
                    else if(visited[temp.first-1][temp.second].first==true)
                    {
                        if(vect[temp.first-1][temp.second]==1)
                        {
                            if(visited[temp.first-1][temp.second].second>visited[temp.first][temp.second].second+1)
                            {
                                q.push(make_pair(temp.first-1,temp.second));
                                visited[temp.first-1][temp.second].second=visited[temp.first][temp.second].second+1;
                            }
                        }
                        else if(vect[temp.first-1][temp.second]==0)
                        {
                            if(visited[temp.first-1][temp.second].second>visited[temp.first][temp.second].second)
                            {
                                q.push(make_pair(temp.first-1,temp.second));
                                visited[temp.first-1][temp.second].second=visited[temp.first][temp.second].second;
                            }
                        }
                    }
                }
                if(temp.second>0)
                {
                    if(visited[temp.first][temp.second-1].first==false)
                    {
                        if(vect[temp.first][temp.second-1]==1)
                        {
                            q.push(make_pair(temp.first,temp.second-1));
                            visited[temp.first][temp.second-1]=make_pair(true,visited[temp.first][temp.second].second+1);
                        }
                        else
                        {
                            q.push(make_pair(temp.first,temp.second-1));
                            visited[temp.first][temp.second-1]=make_pair(true,visited[temp.first][temp.second].second);
                        }
                    }
                    else if(visited[temp.first][temp.second-1].first==true)
                    {
                        if(vect[temp.first][temp.second-1]==1)
                        {
                            if(visited[temp.first][temp.second-1].second>visited[temp.first][temp.second].second+1)
                            {
                                q.push(make_pair(temp.first,temp.second-1));
                                visited[temp.first][temp.second-1].second=visited[temp.first][temp.second].second+1;
                            }
                        }
                        else if(vect[temp.first][temp.second-1]==0)
                        {
                            if(visited[temp.first][temp.second-1].second>visited[temp.first][temp.second].second)
                            {
                                q.push(make_pair(temp.first,temp.second-1));
                                visited[temp.first][temp.second-1].second=visited[temp.first][temp.second].second;
                            }
                        }
                    }
                }
                countNodes--;
            }
            distance++;
        }
        return -1;
    }