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

// intuition : just simply traverse in the graph and store it in a new 
// using dfs 
// tc: o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution 
{
public:
    
    void dfs(Node* node ,Node* p,vector<Node*> &vis)
    {
        vis[p->val] = p ;
        for(auto x : node->neighbors)
        {
            if(vis[x->val]==NULL)
            {
                Node* new1 = new Node(x->val);
                
                (p->neighbors).push_back(new1);
                
                dfs(x,new1,vis);
            }
            
            // node already visited 
            else
            {
                (p->neighbors).push_back(vis[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)
        {
            return NULL;
        }
        
        vector<Node*>vis(1000,NULL);
        Node* p = new Node(node->val);
        dfs(node,p,vis);
        return p;
    }
};
