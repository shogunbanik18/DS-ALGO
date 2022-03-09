/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
// left view of a Binary
// using recursive traversal 
// tc: o(n)
// sc : o(H) height of the tree 
void f(Node * node,int level,vector<int>&v)
{
    if(node==NULL)
    {
        return;
    }
    
    if(level==v.size())
    {
        v.push_back(node->data);
    }
    
    f(node->left,level+1,v);
    f(node->right,level+1,v);
}

vector<int> leftView(Node *root)
{
    vector<int>v;
    f(root,0,v);
    return v;
}

//Right view a binary tree
// using recursive traversal 
// tc: o(n)
// sc : o(H) height of the tree 
void f(Node * node,int level,vector<int>&v)
{
    if(node==NULL)
    {
        return;
    }
    
    if(level==v.size())
    {
        v.push_back(node->data);
    }
    
    f(node->right,level+1,v);
    f(node->left,level+1,v);
}

vector<int> rightView(Node *root)
{
    vector<int>v;
    f(root,0,v);
    return v;
}
