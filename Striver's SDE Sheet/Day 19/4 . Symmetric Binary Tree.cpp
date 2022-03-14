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

// tc: o(n)
// sc: o(n)
class Solution {
public:
    
    bool check(TreeNode*root1,TreeNode*root2)
    {
        if(root1==NULL or root2==NULL)
        {
            return root1==root2;
        }
        
        return (check(root1->left,root2->right) and check(root1->right,root2->left) and (root1->val==root2->val));
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        return check(root->left,root->right);
    }
};
