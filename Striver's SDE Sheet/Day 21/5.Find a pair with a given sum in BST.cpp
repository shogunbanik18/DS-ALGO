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

// using extra space 
// tc : o(n) + o(n)
// sc : o(n)
// class Solution 
// {
// public:
    
//     void inorder(TreeNode * root ,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    
//     bool findTarget(TreeNode* root, int k) 
//     {
//         vector<int>v;
//         inorder(root,v);
        
//         // debug
//         for(auto x : v)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         int i=0;
//         int j = v.size()-1;
        
//         while(i<j)
//         {
//             if(v[i] + v[j] == k)
//             {
//                 return true;
//             }
            
//             else if(v[i] + v[j] > k)
//             {
//                 j--;
//             }
            
//             else
//             {
//                 i++;
//             }
//         }
        
//         return false;
//     }
// };

// using the concept of bst iterator 
class BSTIterator 
{
private:
    stack<TreeNode*>st;
    
    // true for before
    // false for next 
    bool reverse = true;
    
    void pushll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            
            if(reverse == false)
            {
                root= root->left;
            }
            
            else
            {
                root = root->right;
            }
        }
    }
    
public:
    
    BSTIterator(TreeNode* root,bool isreverse)
    {
        reverse = isreverse;
        pushll(root);
    }
   
    int next()
    {
        auto a = st.top();
        st.pop();
        
        if(reverse ==false)
        {
            pushll(a->right);
        }
       
        else
        {
            pushll(a->left);
        }
        
        return a->val;
    }
    
    bool hasNext() 
    {
        if(!st.empty())
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
};

class Solution 
{
public:
    
     bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        for (int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
    
//     bool findTarget(TreeNode* root, int k) 
//     {
//         if(root==NULL)
//         {
//             return false;
//         }
        
//         BSTIterator l(root,false);
//         BSTIterator r(root,true);
        
//         int i = l.next();
//         int j = r.next();
        
//         while(i<=j)
//         {
//             if(i+j==k)
//             {
//                 return true;
//             }
            
//             else if(i+j<k)
//             {
//                 i = l.next();
//             }
            
//             else
//             {
//                 j = r.next();
//             }
//         }
//         return false;
//     }
};
