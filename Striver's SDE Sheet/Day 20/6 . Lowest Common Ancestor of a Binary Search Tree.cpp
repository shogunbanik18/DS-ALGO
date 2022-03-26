/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive Approach same as LCA of Binary Tree 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL or root==p or root==q)
        {
            return root;
        }
        
        TreeNode* left  = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL)
        {
            return right;
        }
        
        else if(right==NULL)
        {
            return left;
        }
        
        else
        {
            return root;
        }
    }
};


// Recursive Approach using the roperty of binary search 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val > p->val and root->val > q->val )
        {
            return lowestCommonAncestor(root->left , p,q);
        }
        
        else if(root->val < p->val and root->val < q->val )
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        
        else
        {
            return root;
        }
    }
};


// using binary search concept + iteration 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* curr = root;
        
        while(true)
        {
            if(curr->val > p->val and curr->val > q->val )
            {
                curr=curr->left;
            }

            else if(curr->val < p->val and curr->val < q->val )
            {
                curr=curr->right;
            }
            
            else
            {
                break;
            }
        }
        
        return curr;
    }
};
