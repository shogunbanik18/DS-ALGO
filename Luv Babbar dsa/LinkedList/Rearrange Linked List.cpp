struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        Node*odd=new Node(-1);
        Node*even=new Node(-1);
        Node*o=odd;
        Node*e=even;
        Node*curr=head;
        int count=1;
        while(curr!=NULL)
        {
            if(count%2==1)
            {
                o->next=curr;
                o=o->next;
            }
            else
            {
                e->next=curr;
                e=e->next;
            }
            curr=curr->next;
            count++;
        }
        o->next=even->next;
        e->next=NULL;
        head=o->next;
       // Your Code here
    }
};
