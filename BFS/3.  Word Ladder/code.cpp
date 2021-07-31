int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int len=beginWord.length();
        unordered_map<string,bool> visited;
        for(string x: wordList)
        {
            visited[x]=false;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=true;
        int totalMoves=1;
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
                string current=q.front();
                q.pop();
                if(current==endWord)
                {
                    return totalMoves;
                }
                for(int i=0;i<current.length();i++)
                {
                    string temp=current;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(visited.find(temp)!=visited.end()&&visited[temp]==false)
                        {
                            q.push(temp);
                            visited[temp]=true;
                        }
                    }
                }
                countNodes--;
            }
            totalMoves++;
        }
        return 0;
    }