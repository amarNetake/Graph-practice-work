//Implementation of adjacency list for a graph with randomly named vertices 

#include <bits/stdc++.h>
using namespace std;

void addEdge(map<char,vector<char>>& ma,char x,char y)
{
    ma[x].push_back(y);  //Note;- we are dealing with the directed graph
}

void printGraph(map<char,vector<char>> ma)
{
    for(auto x:ma)
    {
        char key=x.first;
        vector<char> nbhrs=x.second;
        cout<<key;
        for(char nb:nbhrs)
        {
            cout<<"->"<<nb;
        }
        cout<<"->END";
        cout<<"\n";
    }
}

int main() {
	
	map<char,vector<char>> ma;
	addEdge(ma,'A','B');
	addEdge(ma,'A','D');
	addEdge(ma,'B','C');
	addEdge(ma,'C','D');
	addEdge(ma,'D','B');
	addEdge(ma,'D','E');
	addEdge(ma,'E','F');
	
	printGraph(ma);
	return 0;
}
