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
// class Solution 
// {
// public:
    
//     TreeNode* findgreater(TreeNode* curr ,TreeNode*p)
//     {
//         if(curr->val>p->val)
//         {
//             return curr;
//         }
            
//         findgreater(curr->left,p);
//         findgreater(curr->right,p);
//     }
    
//     void recoverTree(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         TreeNoe*p = root;
//         while(root!=NULL)
//         {
//             if(root->left!=NULL)
//             {
//                 TreeNode*a = findgreater(root->left,p);
//                 swap(p->val,a->val);
//             }
            
//             if(root->right!=NULL)
//             {
//                 TreeNode* b = findsmaller(root->right,p);
//                 swap(p->val,b->val;)
//             }
//         }
        
//         root = p;
//         return root;
//     }
// };

// // using brute force
// // tc : o(n)
// // sc : o(n) + o(n)
// class Solution 
// {
// public:
//     vector<int>v;
//     int i = 0;
//     void inorder(TreeNode*root)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
    
//     void check(TreeNode*root)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         check(root->left);
//         if(v[i]!=root->val)
//         {
//             swap(v[i],root->val);
//         }
//         i++;
//         check(root->right);
//     }
    
    
//     void recoverTree(TreeNode* root)
//     {
//         inorder(root);
//         sort(v.begin(),v.end());
//         check(root);
//     }
// };


// using Optimised brute force
// tc : o(n)
// sc : o(n)
class Solution 
{
public:
    
    TreeNode* first,*last,*prev;
    
    void inorder(TreeNode*root)
    {
        if(root==NULL)
        {
            return;
        }
        
        inorder(root->left);
        
        // if(prev!=NULL and (prev->val > root->val) )
        if(prev !=NULL && (root->val<prev->val))
        {
            if(first==NULL)
            {
                first = prev;
                last = root;
            }
            
            else
            {
                last = root;
            }
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root)
    {
        first = last = prev = NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};
