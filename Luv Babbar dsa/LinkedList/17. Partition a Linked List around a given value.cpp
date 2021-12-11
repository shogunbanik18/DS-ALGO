
/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

// tc : O(N)
// sc: O(N)
struct Node* partition(struct Node* head, int x)
{
    Node*curr=head;
    vector<int>v;
    vector<int>equal;
    vector<int>v1;
    while(curr!=NULL)
    {
        if(curr->data<x)
        {
           v.push_back(curr->data);
        }
        
        else if(curr->data==x)
        {
            equal.push_back(x);
        }
        
        else if(curr->data>x)
        {
            v1.push_back(curr->data);
        }
        curr=curr->next;
    }
    
    
    for(int i=0;i<equal.size();i++)
    {
        v.push_back(equal[i]);    
    }

    for(int i=0;i<v1.size();i++)
        {
            v.push_back(v1[i]);    
        }
    
    Node*newNode =new Node(-1);
    Node*p=newNode;
    
    for(int i=0;i<v.size();i++)
    {
        p->next=new Node(v[i]);
        p=p->next;
    }
    return newNode->next;
    // code here
}
