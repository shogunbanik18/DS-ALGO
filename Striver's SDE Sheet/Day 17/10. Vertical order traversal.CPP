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
    
    //using lines concept 
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        queue<pair<TreeNode*, pair<int,int>>>q;
        map<int ,map<int, multiset<int>> >mp;
        
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto a =q.front();
            q.pop();
            TreeNode*temp = a.first;
            int line = a.second.first;
            int level = a.second.second;
            
            mp[line][level].insert(temp->val);
            
            if(temp->left != NULL)
            {
                q.push(
                    {temp->left, {line-1,level+1}
                    });
            }
            
            if(temp->right!=NULL)
            {
                q.push(
                    {temp->right,{line+1,level+1}
                    });
            }
        }
        
        vector<vector<int>>ds;
        for(auto p:mp)
        {
            vector<int>col;
            for(auto q: p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ds.push_back(col);
        }
        return ds;
    }
};
