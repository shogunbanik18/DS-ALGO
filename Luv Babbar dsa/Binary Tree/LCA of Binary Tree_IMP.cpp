#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
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
       //Your code here 
    }
};
