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
    void traverse(TreeNode* root,vector<vector<int>>&ds,int level)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(ds.size()==level)
        {
            ds.push_back({});
        }
        
        ds[level].push_back(root->val);
        traverse(root->left,ds,level+1);
        traverse(root->right,ds,level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ds;
        traverse(root,ds,0);
        return ds;
    }
    
    // using bfs 
    // level order traversal using queue 
    // using itertion 
//     vector<vector<int>> levelOrder(TreeNode* root) 
//     {
//         vector<vector<int>>ds;
//         if(root==NULL)
//         {
//             return ds;
//         }
        
//         queue<TreeNode*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             vector<int>v;
//             int size=q.size();
            
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode* node =q.front();
//                 q.pop();
//                 v.push_back(node->val);
                
//                 if(node->left!=NULL)
//                 {
//                     q.push(node->left);
//                 }

//                 if(node->right!=NULL)
//                 {
//                     q.push(node->right);
//                 }
                
//             }
//             ds.push_back(v);
//         }
//         return ds;
//     }
};
