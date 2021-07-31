/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* new_node,Node* curr,vector<Node*>& visited)
    {
        visited[new_node->val]=new_node;
        for(auto x: curr->neighbors)
        {
            if(visited[x->val]==NULL)
            {
                Node* temp=new Node(x->val);
                new_node->neighbors.push_back(temp);
                dfs(temp,x,visited);
            }
            else
            {
                new_node->neighbors.push_back(visited[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<Node*> visited(1000,NULL);
        Node* copy=new Node(node->val);
        visited[node->val]=copy;
        for(auto curr: node->neighbors)
        {
            if(visited[curr->val]==NULL)
            {
                Node* new_node=new Node(curr->val);
                copy->neighbors.push_back(new_node);
                dfs(new_node,curr,visited);
            }
            else
            {
                copy->neighbors.push_back(visited[curr->val]);
            }
        }
        return copy;
    }
};