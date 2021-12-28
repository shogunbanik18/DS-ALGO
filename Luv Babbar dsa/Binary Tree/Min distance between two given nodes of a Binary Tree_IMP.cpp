/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node*lca(Node*root,int n1,int n2)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data==n1 or root->data==n2)
        {
            return root;
        }
        
        Node*left=lca(root->left,n1,n2);
        Node*right=lca(root->right,n1,n2);
        if(left!=NULL and right!=NULL)
        {
            return root;
        }
        
        if(left==NULL and right==NULL)
        {
            return NULL;
        }
        
        else if(left!=NULL)
        {
            return lca(root->left,n1,n2);
        }
        
        else if(right!=NULL)
        {
            return lca(root->right,n1,n2);
        }
    }
    
    int finddistance(Node*root,int k,int dis)
    {
        if(root==NULL)
        {
            return -1;
        }
        
        if(root->data==k)
        {
            return dis;
        }
        
        int left=finddistance(root->left,k,dis+1);
        if(left!=-1)
        {
            return left;
        }
        
        return finddistance(root->right,k,dis+1);
    }
    
    int findDist(Node* root, int a, int b)
    {
        Node*LCA=lca(root,a,b);
        int d1=finddistance(LCA,a,0);
        int d2=finddistance(LCA,b,0);
        return d1+d2;
        // Your code here
    }
};
