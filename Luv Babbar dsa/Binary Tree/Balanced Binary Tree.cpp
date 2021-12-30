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
    // tc : O(N*N)
    int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(!isBalanced(root->left))
        {
            return false;
        }
        
        if(!isBalanced(root->right))
        {
            return false;
        }
        
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


// tc :O(N )
bool isBalanced(TreeNode* root,int *height) 
{
    int lh=0;
    int rh=0;
    if(isBalanced(root->left,&lh)==false)
    {
        return false;
    }
    
    if(isBalanced(root->right,&rh)==false)
    {
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh,rh)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
