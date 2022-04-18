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

// using Recursion 
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root->val == val)
        {
            return root;
        }
        
//         if(root->left!=NULL and root->val > val)
//         {
//             return searchBST(root->left,val);
//         }
        
//         if(root->right!=NULL and root->val< val)
//         {
//             return searchBST(root->right,val);
//         }
        
        return root->val > val ? searchBST(root->left,val) : searchBST(root->right,val);
    }
};
