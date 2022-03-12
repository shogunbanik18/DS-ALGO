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
    
    // WRONG ANSWER AND THINKING TOO  MIGHT FAIL IN CASE WHERE INORDER ARE SAME 
    //     EG  [1,1] AND [1,NULL,1]
//     void inorder(TreeNode*root,vector<int>&ans)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
    
//     bool isSameTree(TreeNode* p, TreeNode* q)
//     {
//         vector<int>v1,v2;
//         inorder(p,v1);
//         inorder(q,v2);
        
//         if(v1.size()!=v2.size())
//         {
//             return false;
//         }
//         else
//         {
//             for(int i=0;i<v1.size();i++)
//             {
//                 if(v1[i]!=v2[i])
//                 {
//                     return false;
//                 }
//             } 
//         }
//         return true;
//     }
    
    
    // tc : o(n)
    // sc: o(n)
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL and q!=NULL)
        {
            return false;
        }
        
        if(p!=NULL and q==NULL)
        {
            return false;
        }
        
        if(p==NULL and q==NULL)
        {
            return true;
        }
        else 
        {
            if(p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right))
            {
                return true;
            }
        }
        return false;
    }
};
