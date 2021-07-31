#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int V;  //Total vertices
	list <int>* l;
	Graph(int V)
	{
		this->V=V; 
		l= new list<int>[V]; // l is the pointer to an array of list with V members. Where each vertex has a list of its adjacent members
	}
	void addEdge(int x,int y)
	{
		/*
			Note that here Node y is pushed at list at index x in linked list 
			representing an edge between Node x and y. But if the names of nodes is
			not int or are unevenly numbered then we prefer to use hashmap.
		*/
		//CONSIDERING BIDIRECTIONAL EDGES
		l[x].push_back(y);
		l[y].push_back(x);
	} 
	void printAdjList(){
		//Iterate over all the vertices
		for(int i=0;i<V;i++)
		{
			cout<<"Vertex:"<<i<<" ->";
			for(auto nbhr:l[i])
			{
				cout<<nbhr<<", ";
			}
			cout<<"\n";
		}
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	Graph* g=new Graph(4);
	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(1,2);
	g->addEdge(2,3); 
	g->printAdjList();
}