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
// // using recusion 
class Solution {
public:
    void preorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};


// using Iteration stack 
class Solution {
public:
    // using stack (lifo) so put right first then left 
    vector<int> preorderTraversal(TreeNode* root) \
    {
        stack<TreeNode*>st;
        vector<int>v;
        TreeNode*a=root;
        if(a==NULL)
        {
            return v;
        }
        st.push(a);
        while(!st.empty())
        {
            a=st.top();
            v.push_back(a->val);
            st.pop();
            if(a->right!=NULL)
            {
                st.push(a->right);
            }
            if(a->left!=NULL)
            {
                st.push(a->left);
            }
        }
        return v;
    }
};
