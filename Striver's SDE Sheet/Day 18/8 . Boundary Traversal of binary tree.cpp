/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

// using traversal  + preorder traversal 
class Solution {
public:
    void addleft(Node*root,vector<int>&v)
    {
        Node* curr=root->left;
        while(curr!=NULL)
        {
            if(!isleaf(curr))
            {
                v.push_back(curr->data);
            }
            
            if(curr->left!=NULL)
            {
                curr=curr->left;
            }
            
            else
            {
                curr=curr->right;
            }
        }
    }
    
    void leaf(Node* root,vector<int>& v)
    {
        if(isleaf(root))
        {
            v.push_back(root->data);
            return;
        }
        if(root->left)
        {
            leaf(root->left,v);
        }
        if(root->right)
        {
            leaf(root->right,v);
        }
    }
    
    void addright(Node*root,vector<int>&v)
    {
        Node* a=root->right;
        vector<int>temp;
        while(a!=NULL)
        {
            if(!isleaf(a))
            {
                temp.push_back(a->data);
            }
            
            if(a->right!=NULL)
            {
                a=a->right;
            }
            
            else
            {
                a=a->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            v.push_back(temp[i]);
        }
    }
    

    bool isleaf(Node * root)
    {
        if(root->left==NULL and root->right==NULL)
        {
            return true;
        }
        return false;
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        
        if(!isleaf(root))
        {
            v.push_back(root->data);
        }
        addleft(root,v);
        leaf(root,v);
        addright(root,v);
        return v;
    }
};
