//Transpose of given graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> vect[],int x,int y)
{
    vect[x].push_back(y); //Since it is a directed graph so no bidirectionality
}

void printGraph(vector<int> vect[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i;
        for(int x:vect[i])
        {
            cout<<"->"<<x;
        }
        cout<<"\n";
    }
}

void transposeGraph(vector<int>vect[],vector<int> transpose[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int x: vect[i])
        {
            addEdge(transpose,x,i);
        }
    }
}

int main()
{
    int n=5;
    vector<int> vect[n];
    
    addEdge(vect, 0, 1); 
    addEdge(vect, 0, 4); 
    addEdge(vect, 0, 3); 
    addEdge(vect, 2, 0); 
    addEdge(vect, 3, 2); 
    addEdge(vect, 4, 1); 
    addEdge(vect, 4, 3); 
    
    printGraph(vect,n);
    cout<<endl;
    
    vector<int> transpose[n];
    
    transposeGraph(vect,transpose,n);
    
    printGraph(transpose,n);
    
    return 0;
}

