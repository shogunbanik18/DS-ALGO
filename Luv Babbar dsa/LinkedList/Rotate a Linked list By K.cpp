struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    
    // Appraoch optimised
    // tc: o(N)
    // sc : o(1)
    // Node* rotate(Node* head, int k)
    // {
    //     //   base case 
    //     if(!head or !head->next or k==0)
    //     {
    //         return head;
    //     }
        
    //     Node*curr=head;
    //     int count=0;
    //     while(curr!=NULL)
    //     {
    //         count++;
    //         curr=curr->next;
    //     }
        
    //     curr->next=head;
        
    //     // k=k%count;
    //     if(k>count)
    //     {
    //         return head;
    //     }
    //     int t=count-k;
    //     while(t--)
    //     {
    //         curr=curr->next; 
    //     }
    //     head=curr->next;
    //     curr->next=NULL;
        
    //     return head;
    //     // Your code here
    // }
    
   Node* rotate(Node* head, int k)
   {
          Node*t=head;
          while(t->next)
          {
              t=t->next;
          }
          
          while(k--)
          {
              t->next=head;
              head=head->next;
              t=t->next;
              t->next=NULL;
          }
          return head;
   }
};
    
    
