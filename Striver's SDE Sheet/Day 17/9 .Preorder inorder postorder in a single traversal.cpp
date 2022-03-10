/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// Coding Ninjas
// tc:o(n)+o(n)+o(n)
// sc: o(n)+o(n)+o(n)
#include<bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>>ds(3);
    
    if(root==NULL)
    {
        return ds;
    }
    
    stack<pair< BinaryTreeNode<int> *,int>>st;
    st.push({root,1});
    
    while(!st.empty())
    {
        auto a=st.top();
        st.pop();
        
//         BinaryTreeNode<int> *node=a.first;
//         int num=a.second;
//         answer will be inorder ,preorder ,postorder
           change order of ds[0] and ds[1] while submitting 
        
//      Preorder
        if(a.second==1)
        {
            ds[0].push_back(a.first->data);
            a.second++;
            st.push(a);
            
            if(a.first->left!=NULL)
            {
                st.push({a.first->left,1});
            }
        }
        
//        Inorder
        else if(a.second==2)
        {
            ds[1].push_back(a.first->data);
            a.second++;
            st.push(a);
            
            if(a.first->right!=NULL)
            {
                st.push({a.first->right,1});
            }
        }
        
//      Postorder
        else
        {
            ds[2].push_back(a.first->data);
        }
    }
    return ds;
}
