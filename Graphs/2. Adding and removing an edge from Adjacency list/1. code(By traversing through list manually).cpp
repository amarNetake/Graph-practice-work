#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> vect[],int x,int y)
{
    vect[x].push_back(y);
    vect[y].push_back(x);
}

void delEdge(vector<int> vect[],int x,int y)
{
    for(int i=0;i<vect[x].size();i++)
    {
        if(vect[x][i]==y)  //Search for that edge in that vector vect[x]
        {
            vect[x].erase(vect[x].begin()+i);
            break;    //break the loop if the node is found along that vector and that edge deleted.
        }
    }
    for(int i=0;i<vect[y].size();i++)  // Search for the edge or node along the list
    {
        if(vect[y][i]==x)  //Search for that edge in that vector vect[y]
        {
            vect[y].erase(vect[y].begin()+i);  //Get rid of that edge by removing that node in along that vector
            break;   //break the loop if the node is found along that vector and that edge deleted.
        }
    }
}

void printGraph(vector<int> vect[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<vect[i].size();j++)
        {
            cout<<"->"<<vect[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    int V = 5; 
    vector<int> adj[V];  //Better way will be define vector<vector<int>> adj(5); as this is more natural to human
  
    // Adding edge as shown in the example figure 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
  
    // Printing adjacency matrix 
    printGraph(adj, V); 
    cout<<"\n";
  
    // Deleting edge (1, 4) 
    // as shown in the example figure 
    delEdge(adj, 1, 4); 
  
    // Printing adjacency matrix 
    printGraph(adj, V); 
    cout<<"\n";
  
    return 0; 
}