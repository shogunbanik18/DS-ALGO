truct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Brute Force 
// tc : o(n) + o(n)
// sc : o(n)
// find inorder traversal + find the key and element greater to it 
class Solution{
  public:
    
    void inorder(Node*root, vector<Node*> & v)
    {
        if(root==NULL)
        {
            return ;
        }
        
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
  
    
    Node * inOrderSuccessor(Node *root, Node *p)
    {
        Node*successor;
        vector<Node*>v;
        
        inorder(root,v);
        
        
        // searchng for the key 
        
        int ind;
        for(int i=0;i<v.size();i++)
        {
            if(p==v[i])
            {
                ind = i;
            }
        }
        
        if(ind+1 <=v.size())
        {
            successor = v[ind+1];
        }
        
        else
        {
            successor = NULL;
        }
        return successor;
    }
};



// using the concept of binary search tree
// tc: o(h)
// sc : o(1)
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *p)
    {
        Node* successor =NULL;
        
        while(root!=NULL)
        {
            if(p->data >= root->data)
            {
                root=root->right;
            }
            
            else
            {
                successor = root;
                root = root->left;    
            }
        }
        
        return successor;
    }
};
