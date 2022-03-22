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

// using recursion 
// tc : o(2^n)
// sc : o(n) stack space
class Solution 
{
private:
    
    bool check(TreeNode* root, long mini, long maxi)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(root->val <= mini or root->val >=maxi)
        {
            return false;
        }
        
        return check(root->left,mini,root->val) and check(root->right,root->val,maxi);
    }
    
public:
    bool isValidBST(TreeNode* root)
    {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        return check(root,mini,maxi);   
    }
};
