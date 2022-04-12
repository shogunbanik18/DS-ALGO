/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// using string stream 
// tc : o(n)
// sc  : o(n)
class Codec {
public:

    // Encodes a tree to a single string.
    // using the concept of level order traversal
    string serialize(TreeNode* root) 
    {
        string ans ="";
        queue<TreeNode* >q;
        
        if(root==NULL)
        {
            return ans;
        }
        
        q.push(root);
        while(!q.empty())
        {
            auto  a = q.front();
            q.pop();
            
            
            if(a==NULL)
            {
                ans += "#" ;
                ans += ",";
            }
            else
            {
                ans += to_string(a->val) + ",";
            }
            
            if(a!=NULL)
            {
                q.push(a->left);
                q.push(a->right);
                
            }
        }
        
        // cout<<ans<<endl;
        return ans;
        
    }

    // Decodes your encoded data to tree.
    // using the concept of string stream + getline
    TreeNode* deserialize(string data)
    {
        
        if(data.size()==0)
        {
            return NULL;
        }
        
        stringstream s(data);
        string str;
        
        getline(s,str,',');
        
        TreeNode * root = new TreeNode( stoi(str));
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str== "#")
            {
                curr->left = NULL;
            }
            
            else
            {
                TreeNode* leftnode = new TreeNode(stoi(str));
                curr ->left = leftnode;
                q.push(leftnode);
            }
            
            getline(s,str,',');
            if(str=="#")
            {
                curr->right = NULL;
            }
            
            else
            {
                TreeNode* rightnode = new TreeNode(stoi(str));
                curr ->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
