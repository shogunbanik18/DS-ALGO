struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'

// // Brute Force
// // tc : o(n)
// // sc : o(n)
// class Solution
// {
//     public:
    
//     void inorder(Node*root , vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
        
//         inorder(root->left,v);
//         v.push_back(root->data);
//         inorder(root->right,v);
//     }
    
//     int kthLargest(Node *root, int K)
//     {
//         vector<int>v;
//         inorder(root,v);
        
//         // debug 
//         // for(auto x : v)
//         // {
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
        
//         int n = v.size();
//         int x = n-K;
//         // cout<<x<<endl;
        
//         int ans = v[x];
//         return ans;
//     }
// };


// // Optimisation 
// // tc : o(n)
// // sc : o(n) + o(1)
// class Solution
// {
//     public:
    
//     int count=0,ans;
    
//      //Largest element 
//     void inorder(Node* root ,int k)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
//         inorder(root->right,k);
       
//         count++;
        
//         if(count==k)
//         {
//             ans = root->data;
//             return;
//         }
        
//         inorder(root->left,k);
       
//     }
    
//     int kthLargest(Node *root, int K)
//     {
//       inorder(root,K);
//       return ans;
//     }
// };


// Optimisation 
// tc : o(n)
// sc : o(n) + o(1)
class Solution
{
    public:
    
    int count=0,ans;
    
     //Largest element 
    void inorder(Node* root ,int k)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->right,k);
       
        count++;
        
        if(count==k)
        {
            ans = root->data;
            return;
        }
        
        inorder(root->left,k);
       
    }
    
    int kthLargest(Node *root, int K)
    {
      inorder(root,K);
      return ans;
    }
};
