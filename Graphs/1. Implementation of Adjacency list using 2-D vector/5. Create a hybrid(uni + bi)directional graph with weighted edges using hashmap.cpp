// Create a hybrid(uni + bi)directional graph with weighted edges using hashmap.

#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	unordered_map<string,list<pair<string,int>>> ma;
	
	void addEdge(string x,string y, bool bidir,int wt)
	{
		ma[x].push_back(make_pair(y,wt));
		if(bidir==true)
		{
			ma[y].push_back(make_pair(x,wt));
		}
	}
	void printAdjList()
	{
		for(auto x: ma)
		{
			string city=x.first;
			list<pair<string,int>> neighbours=x.second;
			cout<<city<<" ->";
			for(auto nbhr:neighbours)
			{
				cout<<"("<<nbhr.first<<","<<nbhr.second<<"),";
			}
			cout<<"\n";
		}
	}
};


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
    Graph* g=new Graph();
    g->addEdge("A","B",true,20);
    g->addEdge("B","C",true,30);
    g->addEdge("D","C",true,40);
    g->addEdge("C","A",true,10);
    g->addEdge("A","D",false,50);
    g->printAdjList();
	return 0;
}