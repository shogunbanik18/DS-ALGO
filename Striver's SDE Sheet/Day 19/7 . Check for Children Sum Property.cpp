/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
// tc: o(n)
// sc: o(n) Auxiliary stack space 
void reorder(BinaryTreeNode < int > * root) 
{
    if(root==NULL)
    {
        return ;
    }
    
    int childsum=0;
    if(root->left!=NULL)
    {
        childsum+= root->left->data;
    }
    
    if(root->right!=NULL)
    {
        childsum+= root->right->data;
    }
    
    if(childsum>=root->data)
    {
        root->data = childsum;
    }
    else
    if(childsum < root->data)
    {
        if(root->left!=NULL)
        {
            root->left->data= root->data;
        }
        else if(root->right!=NULL)
        {
            root->right->data= root->data;
        }
    }
    
    reorder(root->left);
    reorder(root->right);
    
    int tot=0;
    if(root->left)
    {
        tot += root->left->data; 
    }
    
    if(root->right)
    {
        tot += root->right->data;
    }
    
    if(root->left or root->right)
    {
        root->data =tot;
    }
}  

void changeTree(BinaryTreeNode < int > * root) 
{
    return reorder(root);
}
