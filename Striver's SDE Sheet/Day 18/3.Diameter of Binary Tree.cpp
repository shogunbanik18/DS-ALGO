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

// Brute Force 
class Solution {
public:
    
    tc :o(n*n)
    sc:o(1)
    int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left= height(root->left);
        int right =height(root->right);
        return 1 + max(left,right);
    }
    
    int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        maxi = max(maxi,lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
    }
    
    // tc:o(n^2)
    //     int diameterOfBinaryTree(TreeNode* root) 
//     {
//         int maxi=0;
//         if(root==NULL)
//         {
//             return 0;
//         }
        
//         int lh = height(root->left);
//         int rh = height(root->right);
        
//         int d1 = lh+ rh;
//         int d2 =diameterOfBinaryTree(root->left);
//         int d3 =diameterOfBinaryTree(root->right);
//         return max(d1,max(d2,d3));
//     }
    
    
    // tc : o(n)
    // sc : o(n) auxiliary stack space 
    int height(TreeNode*root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int lh = height(root->left,ans);
        int rh = height(root->right,ans);
        ans = max(ans,lh+rh);
        return 1 + max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans=0;
        int k = height(root,ans);
        return ans;
    }
};
