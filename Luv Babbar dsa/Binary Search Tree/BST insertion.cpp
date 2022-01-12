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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==NULL)
        {
            TreeNode* newNode =new TreeNode(val);
            return newNode;
        }
        
        TreeNode*curr=root;
        if(curr->val>val)
        {
            root->left=insertIntoBST(curr->left,val);
        }
        else if(curr->val<val)
        {
            root->right=insertIntoBST(curr->right,val);
        }
        return root;
    }
};
