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
class Solution {
public: 
    int findpathsum(TreeNode* root,int &maxi) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int sum = root->val;
        
        int left  = max(0,findpathsum(root->left,maxi));
        int right = max(0,findpathsum(root->right,maxi));
        
        // Backtracking step 
        maxi = max(maxi,sum + (left + right));
        
        return sum + max(left,right);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int maxi =INT_MIN;
        findpathsum(root,maxi);
        return maxi;
    }
};
