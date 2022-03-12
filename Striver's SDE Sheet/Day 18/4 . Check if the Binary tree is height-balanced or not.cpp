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
    // tc: o(n) * o(h)
    // sc: o(1)
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left  = height(root->left);
        int right = height(root->right);
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        // base condition 
        if(!isBalanced(root->left))
        {
            return false;
        }
        
        if(!isBalanced(root->right))
        {
            return false;
        }
        
        
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh)<=1)
        {
            return true;
        }
        return false;
    }
};
