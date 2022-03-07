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
    // using recursion 
    // tc: exponential
    // sc:  o(n) stack space 
    void postorder(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return ;
        }
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>v;
        postorder(root,v);
        return v;
    }
    
    // using 2 stacks 
    // iterative 
    // tc: o(n)
    // sc: o(n)+o(n)
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        TreeNode*a=root;
        vector<int>v;
        
        if(a!=NULL)
        {
            s1.push(a);
        }
        
        while(!s1.empty())
        {
            a=s1.top();
            s1.pop();
            s2.push(a);
            
            if(a->left)
            {
                s1.push(a->left);
            }
            if(a->right)
            {
                s1.push(a->right);
            }
        }
        
        while(!s2.empty())
        {
            a=s2.top();
            s2.pop();
            v.push_back(a->val);
        }
        return v;
    }
    
    // using single stack 
    // iterative 
    // tc: o(2* n) 2 time traversal one for child then for root
    // sc: o(n)
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*>st;
        TreeNode*curr=root;
        vector<int>v;
        
        while(curr!=NULL or !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode*temp=st.top()->right;
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                    v.push_back(temp->val);
                    while(!st.empty() and temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        v.push_back(temp->val);
                    }
                }
                else
                {
                    curr=temp;
                }
            }
        }
        return v;
    }
};
