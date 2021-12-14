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

// merging of two sorted linked lists 
Node*mergetwolists(Node*a,Node*b)
{
    Node*temp=new Node(0);
    Node*res=temp;
    while(a!=NULL and b!=NULL)
    {
        if(a->data<b->data)
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
    
// Recursively calling for flattening linked list
Node *flatten(Node *root)
{
    if(root==NULL or root->next==NULL)
    {
        return root;
    }
    
    // recur for list on right 
    root->next=flatten(root->next);
    
    // merge 
    root=mergetwolists(root,root->next);
    return root;
   // Your code here
}
