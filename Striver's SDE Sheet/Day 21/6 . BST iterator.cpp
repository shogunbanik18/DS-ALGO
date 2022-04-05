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

// using extra stack 
// Designing of BST iterator
// tc : o(1)
// sc : o(H)
class BSTIterator 
{
private:
    stack<TreeNode*>st;
    
    void pushll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root= root->left;
        }
    }
    
public:
    
    BSTIterator(TreeNode* root)
    {
        pushll(root);
    }
   
    int next()
    {
        int ans = 0 ;
    
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
        
        else
        {
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
