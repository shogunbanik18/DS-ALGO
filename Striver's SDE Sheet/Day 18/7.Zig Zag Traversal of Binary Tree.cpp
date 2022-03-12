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

// level order traversal with a bool function
// tc :o(n)
// sc:o(n)
class Solution {
public: 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ds;
        if(root==NULL)
        {
            return ds;
        }
       
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            vector<int>v;
            bool l2r =false;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* p = q.front().first;
                int a = q.front().second;
                if(a%2==0)
                {
                    l2r=true;
                }
                q.pop();
                
                v.push_back(p->val);
                
                if(p->left!=NULL)
                {
                    q.push({p->left,a+1});
                }
                
                if(p->right!=NULL)
                {
                    q.push({p->right,a+1});
                }
            }
            
            if(l2r%2 ==false)
            {
                reverse(v.begin(),v.end());
            }
            
            ds.push_back(v);
        }
        return ds;
    }
};
