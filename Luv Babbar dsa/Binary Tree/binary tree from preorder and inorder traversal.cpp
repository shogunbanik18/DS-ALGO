
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int search(int *in,int x,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==x)
            {
                return i;
            }
        }
        return -1;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0)
        {
            return NULL;
        }
        
        int root=search(in,pre[0],n);
        Node*temp=new Node(pre[0]);
        temp->left=buildTree(in,pre+1,root);
        temp->right=buildTree(in+root+1,pre+root+1,n-root-1);
        return temp;
        // Code here
    }
};




#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
      int data;
      Node*left;
      Node*right;
      Node(int val)
      {
          data=val;
          left=right=NULL;
      }
};

int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node*buildTree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    
    int curr=preorder[idx];
    idx++;
    
    Node*node=new Node(curr);
    if(start==end)
    {
        return node;
    }
    
    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);
}



void inorderprint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node*root=buildTree(preorder,inorder,0,4);
    inorderprint(root);
    return 0;
}
