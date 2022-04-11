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
// Brute Force 
// using the concept of validate bst 
// optimised approach 

// class Solution
// {
// public:
    
//    bool check(TreeNode*root , long mini,long maxi)
//    {
//        if(root==NULL)
//        {
//            return true;
//        }
       
//        if(root->val <= mini or root->val>=maxi )
//        {
//            return false;
//        }
       
//        return check(root->left ,mini,root->val) and check(root->right ,root->val,maxi);
//    }

//    bool isValid(TreeNode * root)
//    {
//        long mini = LONG_MIN;
//        long maxi = LONG_MAX;
       
//        return check(root,mini,maxi);
//    }
    
//     void inorder(TreeNode*root , vector<int>&v )
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    
//     int maxSumBST(TreeNode* root) 
//     {
//         int sum =0;
//         if(isValid(root))
//         {
//             // cout<<"Yes"<<endl;
//             vector<int> v;
//             inorder(root,v);
            
//             for(auto x : v)
//             {
//                 cout<<x<<" ";
//                 sum +=x;
//             }
//             cout<<endl<<sum<<endl;
//         }
        
//         else
//         {
//             if(isValid(root->left))
//             {
//                 cout<<"yo"<<endl;
//             }
            
//             if(isValid(root->right))
//             {
//                 vector<int> v;
//                 inorder(root->right,v);

//                 for(auto x : v)
//                 {
//                     cout<<x<<" ";
//                     sum +=x;
//                 }
//                 cout<<endl<<sum<<endl;
//             }
//         }
        
//         return sum;
//     }
// };

// optimised approach using the concept of postorder traveersal + class
// tc : o(n)
// sc : o(1)
class Solution
{
public:
    
    int res = INT_MIN;
    
    class bst
    {
       public:
            
        bool isbst;
        int max;
        int min;
        int sum;
        // int size;
    };
    
    bst solve(TreeNode* root)
    {
        if(root==NULL)
        {
            bst a;
            a.isbst = true;
            a.max = INT_MIN;
            a.min = INT_MAX;
            a.sum = 0;
            
            return a;
        }
        
        // solving the left substree then right subtree
        bst l = solve(root->left);
        bst r = solve(root->right);
        
        bst ans;
        ans.max = max(root->val , max(l.max,r.max));
        ans.min = min(root->val , min(l.min,r.min));
        
        ans.isbst = l.isbst and r.isbst and (l.max < root->val and root->val< r.min);
        
        if(ans.isbst)
        {
            ans.sum = l.sum + r.sum + root->val;
            ans.max = max(root->val, max(l.max,r.max));
            ans.min = min(root->val, min(l.min,r.min));
        }
        else
        {
            ans.sum = max(l.sum,r.sum);
        }
        
        res = max(res,ans.sum);
        return ans;
    }
    
    
    int maxSumBST(TreeNode* root) 
    {
        solve(root);
        return res>0 ? res : 0;
    }
   
};
