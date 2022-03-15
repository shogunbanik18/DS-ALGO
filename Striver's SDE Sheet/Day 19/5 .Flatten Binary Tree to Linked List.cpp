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

// // using recursion 
// // tc: o(n)
// // sc: o(n)
// // Reverse Preorder 
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
        {
            return ;
        }
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev=root;
    }
};

// using iteration + stack
// tc: o(n)
// sc: o(n)
// Reverse Preorder 
class Solution {
public:
    
    void flatten(TreeNode* root) 
    {
        stack<TreeNode*>st;
        if(root==NULL)
        {
            return ;
        }
        
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode*curr=st.top();
            st.pop();
            
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }
            
            if(curr->left!=NULL)
            {
                st.push(curr->left);
            }
            
            if(!st.empty())
            {
                curr->right = st.top();
            }
            curr->left=NULL;
        }
    }
};


// Most Optimised Approach 
// using Morris Traversal of Binary Tree
// tc: o(n)
// sc: o(1)
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode*curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode*prev =curr->left;
                while(prev->right!=NULL)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
           
        } 
    }
};

