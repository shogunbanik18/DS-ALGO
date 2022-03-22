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

// using stack
// tc: o(n)
// sc : o(n) stack space 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n = preorder.size();
        stack<TreeNode*>st;
        
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        
        for(int i=1;i<n;i++)
        {
            TreeNode* curr = st.top();
            TreeNode* p = new TreeNode(preorder[i]);
            
            if(p->val < curr->val)
            {
                curr->left = p;
                st.push(p);
            }
            
            else
            {
                TreeNode* a;
                while(!st.empty() and st.top()->val < preorder[i])
                {
                    a = st.top();
                    st.pop();
                }
                
                if(p!=NULL)
                {
                    a->right = p;
                }
                st.push(p);
            }
            
        }
        return root;
    }
};


// using recursive approach 
// using 2 vectors (left and right ) and calling the function recursively 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       int n = preorder.size();
       if(n==0)
       {
           return NULL;
       }
        
         TreeNode* root = new  TreeNode(preorder[0]);
        
        if(n==1)
        {
            return root;
        }
        
        vector<int>left,right;
        
        for(int i=1;i<n;i++)
        {
            if(preorder[i]>preorder[0])
            {
                right.push_back(preorder[i]);
            }
            else
            {
                left.push_back(preorder[i]);
            }
        }
        
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};
