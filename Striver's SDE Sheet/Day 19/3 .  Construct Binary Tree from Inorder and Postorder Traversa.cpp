/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 // *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// tc: o(n) or o(nlogn)
// sc:o(n) + o(n)
class Solution {
public:
    
    TreeNode* construct(vector<int>&inorder , int instart, int inend,
                        vector<int> &postorder, int poststart, int postend, map<int,int>&mp)
    {
        if(poststart>postend or instart>inend)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        int nele = inroot- instart;
        
        root->left = construct(inorder,instart,inroot-1,postorder,poststart,poststart +nele-1 ,mp);
        
        root->right = construct(inorder,inroot+1,inend,postorder,poststart + nele,postend-1,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size()!=postorder.size())
        {
            return NULL;
        }
        
        map<int,int>mp;
        int n= inorder.size();
        
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        return construct(inorder,0,n-1,postorder,0,n-1,mp);
    }
};
