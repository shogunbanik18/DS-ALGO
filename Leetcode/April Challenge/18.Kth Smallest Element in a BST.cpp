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

// // Extememe Brute Force 
// // tc : o(n)
// // sc  : o(n)
// class Solution
// {
// public:
    
//     void inorder(TreeNode* root,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    
//     int kthSmallest(TreeNode* root, int k) 
//     {
//         vector<int>v;
//         inorder(root,v);
        
//         int ans = v[k-1];
//         return ans;
//     }
// };

// // Optimisation 1 
// // tc : o(n)
// // sc  : o(1) + auxiliary stack space
// class Solution
// {
// public:
//     int count  =0, ans =1;
//     void inorder(TreeNode* root,int k)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,k);
//         count++;
        
//         if(count==k)
//         {
//             ans = root->val;
//             return;
//         }
        
//         inorder(root->right,k);
//     }
    
//     int kthSmallest(TreeNode* root, int k) 
//     {
//         inorder(root,k);
//         return ans;
//     }
// };


// // Optimisation 1 
// // tc : o(n)
// // sc  : o(1) + auxiliary stack space
// class Solution
// {
// public:
//     int count  =0, ans =1;
//     void morrisinorder(TreeNode* root,vector<int>&v)
//     {
//         TreeNode*prev=root;
        
//         while(prev!=NULL)
//         {
//             if(prev->left==NULL)
//             {
//                 v.push_back(prev->val);
//                 prev = prev->right;
//             }
            
//             else
//             {
//                 TreeNode* curr = prev->left;
                
//                 while(curr->right!=NULL and curr->right!=prev)
//                 {
//                     curr = curr ->right;
//                 }
                
//                 if(curr->right ==NULL)
//                 {
//                     curr->right = prev;
//                     prev = prev->left;
//                 }
                
//                 else 
//                 {
//                     curr->right = NULL;
//                     v.push_back(prev->val);
//                     prev = prev ->right;
//                 }
//             }
//         }
//     }
    
//     int kthSmallest(TreeNode* root, int k) 
//     {
//         vector<int>v;
//         morrisinorder(root,v);
    
//         for(auto x : v)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         int ans = v[k-1];
//         return ans;
//     }
// };



// Optimisation 1 
// tc : o(n)
// sc  : o(1)
class Solution
{
public:
    int count  =0, ans =1;
    void morrisinorder(TreeNode* root,int k)
    {
        TreeNode*prev=root;
        
        while(prev!=NULL)
        {
            if(prev->left==NULL)
            {
                count++;
                
                if(count==k)
                {
                    ans = prev->val;
                }
                
                prev = prev->right;
            }
            
            else
            {
                TreeNode* curr = prev->left;
                
                while(curr->right!=NULL and curr->right!=prev)
                {
                    curr = curr ->right;
                }
                
                if(curr->right ==NULL)
                {
                    curr->right = prev;
                    prev = prev->left;
                }
                
                else 
                {
                    curr->right = NULL;
                    count++;
                    
                     if(count==k)
                    {
                        ans = prev->val;
                    }

                    
                    prev = prev ->right;
                }
            }
        }
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        morrisinorder(root,k);
        return ans;
    }
};
