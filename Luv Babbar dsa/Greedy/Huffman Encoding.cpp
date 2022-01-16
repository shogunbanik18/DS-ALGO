class Solution
{
// 	class for constructing the tree 
	    struct Node
	    {
	        int freq;
	        Node*left;
	        Node*right;
	        Node(int f)
	        {
	            freq=f;
	            left=right=NULL;
	        }
	    };
	    
	    class cmp
	    {
	      public:
	        bool operator()(Node*a,Node*b)
	        {
	            return a->freq > b->freq;
	        }
	    };
	   
	    void preorder(Node*root,string s,vector<string>&ans)
	    {
	        if(root==NULL)
	        {
	            return;
	        }
	        
	        if(root->left==NULL and root->right==NULL)
	        {
	            ans.push_back(s);
	            return;
	        }
	        if(root->left)
	        {
	            preorder(root->left,s+"0",ans);
	        }
	        if(root->right)
	        {
	            preorder(root->right,s+"1",ans);
	        }
	    }
	    
	    public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		  //  min heap 
		    priority_queue<Node*,vector<Node*>,cmp>pq;
		    vector<string>ans;
		    
		    for(int i=0;i<N;i++)
		    {
		        Node*temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1)
		    {
		        Node*x=pq.top();
		        pq.pop();
		        Node*y=pq.top();
		        pq.pop();
		        
		        Node*temp=new Node(x->freq+y->freq);
		        temp->left=x;
		        temp->right=y;
		        pq.push(temp);
		    }
		    
		    Node*root=pq.top();
		    preorder(root,"",ans);
		    return ans;
		    // Code here
		}
};
