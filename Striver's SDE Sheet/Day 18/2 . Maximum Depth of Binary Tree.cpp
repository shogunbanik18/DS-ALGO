/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // using recursion 
    // tc: o(n)
    // sc: recursion stackspace 
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        int maxheight = 1 + max(left,right);
        return maxheight;
    }
    
    
    // using level order traversal using bfs 
    // tc:o(n)
    // sc:o(n)
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        vector<int>v;
        int level=0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                auto node =q.front();
                q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }  
            }
            level++;
           
        }
        return level;
    }
};
