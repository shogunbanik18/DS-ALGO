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
    // iterative way using own stack 
    //   tc:o(n)
    //   sc:o(n)
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>v;
        TreeNode*a=root;
        stack<TreeNode*>st;
        
        while(true)
        {
            if(a!=NULL)
            {
                st.push(a);
                a=a->left;
            }
            else
            {
                if(st.empty()==true)
                {
                    break;
                }
                a=st.top();
                v.push_back(a->val);
                st.pop();
                a=a->right;
            }   
        }
        return v;
    }
    
    // using morris inorder traversal 
    // tc:o(n)
    // sc:o(1)
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>v;
        TreeNode*curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                v.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode*prev=curr->left;
                while(prev->right!=NULL and prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    v.push_back(curr->val);
                    curr=curr->right;
                }
            }   
        }
        return v;
    }
    
};
