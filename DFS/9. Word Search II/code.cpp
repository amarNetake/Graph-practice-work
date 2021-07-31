#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> matrix,string word,vector<vector<bool>> visited,int row,int col,int index)
{
    if(row<0||row>matrix.size()-1||col<0||col>matrix[0].size()-1||visited[row][col]==true)
    {
        return false;
    }
    visited[row][col]=true;
    
    if(matrix[row][col]!=word[index])
    {
        return false;
    }
    if(index>=word.length()-1)
    {
        return true;
    }
    visited[row][col]=true;
    bool found=dfs(matrix,word,visited,row+1,col,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row-1,col,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row,col+1,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row,col-1,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row+1,col+1,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row+1,col-1,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row-1,col-1,index+1);
    if(found==true)
    {
        return true;
    }
    found=dfs(matrix,word,visited,row-1,col+1,index+1);
    return found; 
}


void findWords(vector<string>& words,vector<vector<char>>& matrix,set<string>& result,unordered_map<char,vector<pair<int,int>>> ma,int r,int c)
{
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    for(auto word: words)
    {
        int row,col;
        bool found=false;
        for(auto x: ma[word[0]])
        {
            row=x.first;
            col=x.second;
            found=dfs(matrix,word,visited,row,col,0);
            if(found==true)
            {
                result.insert(word);
                break;
            }
        }
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<string> words(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>words[i];
	    }
	    int r,c;
	    cin>>r>>c;
	    vector<vector<char>> matrix(r,vector<char>(c));
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>matrix[i][j];
	        }
	    }
	    unordered_map<char,vector<pair<int,int>>> ma;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            ma[matrix[i][j]].push_back(make_pair(i,j));
	        }
	    }
	    set<string> result;
	    findWords(words,matrix,result,ma,r,c);
	    if(result.size()==0)
	    {
	        cout<<-1;
	    }
	    else
	    {
	        for(string word: result)
	        {
	            cout<<word<<" ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}