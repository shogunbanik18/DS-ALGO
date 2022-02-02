
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
//########## using the concept of merge sort + Recursion   ############### 
// moving on bottom 
// tc:o(n)
// sc:o(1)
Node *mergetwolist(Node *a,Node *b)
{
    Node *dummy=new Node(0);
    Node*temp=dummy;
    Node *res=temp;
    while(a!=NULL and b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        else
        {
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a)
    {
        temp->bottom=a;
    }
    else
    {
        temp->bottom=b;
    }
    return res->bottom;
}

// using recursion +merge sort 
Node *flatten(Node *root)
{
    if(root==NULL or root->next==NULL)
    {
        return root;
    }
    root->next=flatten(root->next);
    root=mergetwolist(root,root->next);
    return root;
   // Your code here
}
