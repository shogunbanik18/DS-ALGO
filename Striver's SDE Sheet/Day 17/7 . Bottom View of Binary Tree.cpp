class Solution {
  public:
  
    // using the concept of vertical order traversal usng queue(FIFO)
    // using iteration 
    // tc:o(n)
    // sc:o(n)
    vector <int> bottomView(Node *root) 
    {
        vector<int>v;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        
        if(root==NULL)
        {
            return v;
        }
        q.push({root,0});
        
        while(!q.empty())
        {
            auto a =q.front();
            q.pop();
            Node*node=a.first;
            int lines=a.second;
            mp[lines]= node->data;
            
            if(node->left!=NULL)
            {
                q.push({node->left,lines-1});
            }
            
            if(node->right!=NULL)
            {
                q.push({node->right,lines+1});
            }
        }
        
        for(auto x: mp)
        {
            v.push_back(x.second);
        }
        return v;
    }
};
