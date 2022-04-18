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

// // preorder traversal
// class Solution
// {
// public:
    
//     void preorder(TreeNode* root,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
        
//         v.push_back(root->val);
//         preorder(root->left,v);
//         preorder(root->right,v);
//     }
    
//     TreeNode* trimBST(TreeNode* root, int low, int high) 
//     {
//         vector<int>v;
//         preorder(root,v);
        
//         vector<int>a;
//         for(auto x : v)
//         {
//             if(x>=low and x<=high)
//             {
//                 a.push_back(x);
//             }
//         }
        
//         // for(auto x : a)
//         // {
//         //     cout<<x<<" ";
//         // }
        
//         TreeNode* curr1 = new TreeNode(a[0]);
        
//         for(int i = 1; i<a.size();i++)
//         {
//             TreeNode* curr2 = new TreeNode(a[i]);
//             if(curr2->val > curr1->val)
//             {
//                 curr1->left = curr2;
//             }
//         }
        
//     }
// };


// dfs traversal + properties of bst
class Solution
{
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        // if(root->val >= low and root->val<=high)
        // {
            // skip
        // }
        
        if(root->val<low)
        {
            return trimBST(root->right,low,high);
        }
        else if(root->val > high)
        {
            return trimBST(root->left,low,high);
        }
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        return root;
    }
};
