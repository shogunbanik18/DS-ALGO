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
    // iterative solution 
    // tc:O(n)
    // sc:O(1)+O(N) for vector
//     void inorder(TreeNode*root,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    
//     bool isValidBST(TreeNode* root) 
//     {
//         vector<int>v;
//         inorder(root,v);
//         for(int i=1;i<v.size();i++)
//         {
//             if(v[i]<=v[i-1])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
    
    // Recursive 
     // tc:O(n)
    // sc:O(N)
    
    bool check(TreeNode*root,long min,long max)
    {
        if(root==NULL)
        {
            return true;
        }
        if((root->val<=min) or root->val>=max)
        {
            return false;
        }
        return check(root->left,min,root->val) and check(root->right,root->val,max);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return check(root,LONG_MIN,LONG_MAX);
    }
    
};
    
