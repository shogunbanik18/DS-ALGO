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
// class Solution {
// public:
//     // using level order traversal 
//     int widthOfBinaryTree(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
        
//         int ans=0;
//         queue<pair<TreeNode* ,int>>q;
//         q.push({root,0});
        
//         while(!q.empty())
//         {
//             int size= q.size();
//             int mini =q.front().second;
//             int leftmost,rightmost;
            
//             for(int i=0;i<size;i++)
//             {
//                 int curr_id =q.front().second - mini;
//                 TreeNode*temp =q.front().first;
                
//                 q.pop();
                
//                 if(i==0)
//                 {
//                     leftmost =curr_id;
//                 }
//                 if(i==size-1)
//                 {
//                     rightmost =curr_id;
//                 }
                
//                 if(temp->left)
//                 {
//                     q.push({temp->left,2*curr_id+1});
//                 }
//                 if(temp->right)
//                 {
//                     q.push({temp->right,2*curr_id+2});
//                 }
//             }
//             ans =max (ans, rightmost-leftmost+1);
//         }
//         return ans;
//     }

// tc: o(n)
// sc:o(n)
class Solution {
public:
    // using level order traversal 
    int widthOfBinaryTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        queue<pair<TreeNode* ,int>>q;
        q.push({root,0});
        int ans=0;
        
        while(!q.empty())
        {
            int n=q.size();
            int first = q.front().second;
            int last = q.back().second;
            
            ans =max(ans , last-first+1);
            
            for(int i=0;i<n;i++)
            {
                TreeNode* temp= q.front().first;
                int index = q.front().second- first;
                q.pop();
                
                if(temp->left!=NULL)
                {
                    q.push({temp->left, (long long) 2*index+1});
                }
                
                if(temp->right!=NULL)
                {
                    q.push({temp->right,(long long) 2*index+2});
                }
            }
        }
        return ans;
    }
};
