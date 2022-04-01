/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
// using the concept of binary search 
// tc : o(logn)
// sc : o(1)
int findCeil(BinaryTreeNode<int> *root, int x)
{
    int ans = -1;
    
    while(root!=NULL)
    {
        if(root->data == x)
        {
            ans = root->data;
            return ans;
        }
        
        if(root->data > x)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
			root = root->right;            
        }
    }
    return ans;
}
