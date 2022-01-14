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
     int sumofRange;
    void dfs(TreeNode* root, int low, int high)
    {
        // base case 
        if(root==NULL)
        {
            return ;
        }
        
        if(root->val>=low and root->val<=high)
        {
            sumofRange+=root->val;
        }
        dfs(root->left,low,high);
        dfs(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        
        int sum=0;
        dfs(root,low,high);
        return sumofRange;
    }
};
