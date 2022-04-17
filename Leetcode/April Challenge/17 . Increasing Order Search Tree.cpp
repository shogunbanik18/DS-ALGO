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
// Brute Force approach 
// tc : o(n) + o(n)
// sc : o(n)
// class Solution 
// {
// public:
    
//     void inorder(TreeNode* root ,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    
//     TreeNode* increasingBST(TreeNode* root) 
//     {
//         vector<int>v;
//         inorder(root,v);
        
//         // debug 
//         // for(auto x : v)
//         // {
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
        
//         TreeNode* p = new TreeNode(v[0]);
//         TreeNode* main = p;
//         p->left=NULL;
        
//         int n = v.size();
//         for(int i =1;i<n;i++)
//         {
//             TreeNode* a = new TreeNode(v[i]);
//             a->left=NULL;
            
//             if(i==n-1)
//             {
//                 a->right=NULL;
//             }
            
//             p->right = a;
            
//             p = a;
//         }
//         return main;
//     }
// };

// optimised approach
// tc : o(n)
// sc : o(1)
class Solution 
{
public:
    TreeNode* head = new TreeNode();
    TreeNode* p = head;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        inorder(root->left);
        p->left = NULL;
        
        TreeNode* a = new TreeNode(root->val);
        p->right = a; 
        p = p->right;
    
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        inorder(root);
        return head->right;
    }
};
