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
    
    TreeNode* construct(vector<int>& preorder,int prestart,int preend,vector<int>& postorder,int poststart,int postend,map<int,int>&mp)
    {
        if(prestart>preend or poststart>postend)
        {
            return NULL;
        }
        
        TreeNode* root =new TreeNode( preorder[prestart]);
        
        if(prestart+1<=preend)
        {
            int ele = mp[preorder[prestart+1]];
            int nele = ele -poststart + 1;
            
            root->left = construct(preorder,prestart+1 ,prestart + nele,postorder,poststart,ele,mp);
            
            root->right = construct(preorder,prestart + nele +1,preend,postorder,ele+1,postend-1,mp);
        }
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        map<int,int>mp;
        
        int n = postorder.size();
        int m = preorder.size();
        if(n!=m)
        {
            return NULL;
        }
        
        for(int i=0;i<n;i++)
        {
            mp[postorder[i]]=i;
        }
        
        int prestart=0,preend=n-1;
        int poststart=0,postend=n-1;
        
        return construct(preorder,prestart,preend,postorder,poststart,postend,mp);
        
    }
};
