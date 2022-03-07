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
    // using Recursion 
//     tc:o(n)
//   sc:o(n)
    void inorder(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }    
    
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
}; 
    // using iterative way 
    // tc:o(n)
    // sc:o(n)
    class Solution {
public:
    // iterative way using own stack 
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
    
};
