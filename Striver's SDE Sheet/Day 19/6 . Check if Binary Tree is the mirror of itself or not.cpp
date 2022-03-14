class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) 
    {
        if(node==NULL)
        {
            return;
        }
        
        Node*n =node->left;
        node->left= node->right;
        node->right =n;
        
        if(node->left)
        {
            mirror(node->left);
        }
       
        if(node->right)
        {
            mirror(node->right);
        }
        
    }
};
