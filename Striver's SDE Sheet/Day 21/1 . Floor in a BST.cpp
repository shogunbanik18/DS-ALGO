/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// using the concept of binary search 
int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    
    while(root!=NULL)
    {
        if(root->val == X)
        {
            ans = root->val;
            return ans;
        }
        
        if(root->val > X)
        {
           root=root->left;
        }

        else
        {
            ans = root->val;
            root = root->right;
        }
     }
    return ans;
}
