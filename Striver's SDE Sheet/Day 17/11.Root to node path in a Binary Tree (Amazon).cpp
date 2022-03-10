/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool f(TreeNode* A,vector<int>&arr,int V)
{
    if(A==NULL)
    {
        return false;
    }

    arr.push_back(A->val);
    if(A->val==V)
    {
        return true;
    }

    if(f(A->left,arr,V) or f(A->right,arr,V))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>a;
    f(A,a,B);
    return a;
}
