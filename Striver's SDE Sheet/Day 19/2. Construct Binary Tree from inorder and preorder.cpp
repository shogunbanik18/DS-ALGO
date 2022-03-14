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
 
//  tc: o(n) or o(nlogn)
//  sc: o(n) stack space + o(n) map 
class Solution {
public:
    
    TreeNode* construct(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend, map<int,int>&mp)
    {
        if(prestart>preend or instart>inend)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int nele = inroot-instart;
        
        root->left = construct(preorder,prestart+1,prestart + nele,inorder,instart,inroot-1,mp);
        
        root->right = construct(preorder,prestart+ nele +1 ,preend,inorder,inroot+1 ,inend,mp);
        
        return root;
    }
        
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int,int>mp;
        int n=inorder.size();
        
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        int prestart=0,preend=n-1;
        int instart=0, inend =n-1;
        
        return construct(preorder,prestart,preend,inorder,instart,inend,mp);
    }
};
