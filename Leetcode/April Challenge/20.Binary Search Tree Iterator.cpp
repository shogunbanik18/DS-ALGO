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

// // tc : o(n)
// // sc : o(n) + stack space o(h)

// class BSTIterator 
// {
// public:
    
//     vector<int>v;
    
//     stack<int>st;
    
//     void inorder(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
    
//     BSTIterator(TreeNode* root) 
//     {
//         inorder(root);
//         int n = v.size();
//         for(int i = n-1;i>=0;i--)
//         {
//             st.push(v[i]);
//         }
//     }
    
//     int next() 
//     {
//         auto a = st.top();
//         st.pop();
        
//         int x = a;
//         return x;
//     }
    
//     bool hasNext() 
//     {
//         if(!st.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your BSTIterator object will be instantiated and called as such:
//  * BSTIterator* obj = new BSTIterator(root);
//  * int param_1 = obj->next();
//  * bool param_2 = obj->hasNext();
//  */

// // tc : o(n)
// // sc : stack space o(h)
// class BSTIterator 
// {
// public:    
//     stack<int>st;
    
//     void reverse_inorder(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         reverse_inorder(root->right);
//         st.push(root->val);
//         reverse_inorder(root->left);
//     }
    
//     BSTIterator(TreeNode* root) 
//     {
//         reverse_inorder(root);
//     }
    
//     int next() 
//     {
//         auto a = st.top();
//         st.pop();
//         return a;
//     }
    
//     bool hasNext() 
//     {
//         if(!st.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your BSTIterator object will be instantiated and called as such:
//  * BSTIterator* obj = new BSTIterator(root);
//  * int param_1 = obj->next();
//  * bool param_2 = obj->hasNext();
//  */

// using the property of BST
// tc : o(1)
// sc : stack space o(h)
class BSTIterator 
{
public:    
    stack<TreeNode*>st;
    
    void pushll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) 
    {
        pushll(root);
    }
    
    int next() 
    {
        int ans;
        auto a = st.top();
        ans = a->val;
        
        st.pop();
        
        pushll(a->right);
        
        return ans;
    }
    
    bool hasNext() 
    {
        if(!st.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
