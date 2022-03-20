/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// using level order traversal (BFS) queue 
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return nullptr;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto a = q.front();
                q.pop();
                
                if(i==n-1)
                {
                    a->next = nullptr;
                }
                else
                {
                    auto b =q.front();
                    a->next = b;
                }
                
                if(a->left!=NULL)
                {
                    q.push(a->left);
                }
                
                if(a->right!=NULL)
                {
                    q.push(a->right);
                }
            }
        }
        return root; 
    }
};
