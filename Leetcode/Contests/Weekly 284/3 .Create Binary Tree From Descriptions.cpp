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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        map<int,TreeNode*>mp;
        set<TreeNode*>p,c;
        
        int n=descriptions.size();
        
        for(int i=0;i<n;i++)
        {
            TreeNode* parent;
            if(mp.find(descriptions[i][0])!=mp.end())
            {
                parent =mp[descriptions[i][0]];
            }
            else
            {
                parent = new TreeNode(descriptions[i][0]);
            }
            
            TreeNode*child;
            if(mp.find(descriptions[i][1])!=mp.end())
            {
                child = mp[descriptions[i][1]];
            }
            else
            {
                child = new TreeNode(descriptions[i][1]);
            }
            
            if(descriptions[i][2]==1)
            {
                parent->left=child;
            }
            else
            {
                parent->right=child;
            }
            
            mp.insert({parent->val,parent});
            mp.insert({child->val,child});
            p.insert(parent);
            c.insert(child);
        }
        for(auto x:p)
        {
            if(c.find(x)==c.end())
            {
                return x;
            }
        }
        return NULL;
    }
};
