/*
struct Node
{ 
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    // using the concept of vertical order traversal
    // tc: o(n)
    // sc:o(H) height of the tree Amortised
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        vector<int>v;
        
        q.push({root,0});
        while(!q.empty())
        {
            auto a= q.front();
            q.pop();
            Node*node=a.first;
            int line=a.second;
            
            if(mp.find(line)==mp.end())
            {
                mp[line]= node->data;
            }
            
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        return v;
    }

};
