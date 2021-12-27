/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    
    int findheight(Node*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=findheight(root->left);
        int h=findheight(root->right);
        return max(l,h)+1;
    }
    
    void checkdepth(Node*root,int d,int h,bool&ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL and root->right==NULL)
        {
            if(d!=h)
            {
                ans=false;
                return;
            }
        }
        checkdepth(root->left,d+1,h,ans);
        checkdepth(root->right,d+1,h,ans);
    }
    
    bool check(Node *root)
    {
        int height=findheight(root);
        bool ans=true;
        checkdepth(root,1,height,ans);;
        return ans;
        //Your code here
    }
};
