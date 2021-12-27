/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node*curr1=head1;
    Node*curr2=head2;
    Node *dummy= new Node(-1);
    Node*curr3 =dummy;
    
    while(curr1!=NULL and curr2!=NULL)
    {
        if(curr1->data < curr2->data)
        {
            curr3->next=curr1;
            curr1=curr1->next;
        }
        else
        {
            curr3->next=curr2;
            curr2=curr2->next;
        }
        curr3=curr3->next;
    }
    
    while(curr1!=NULL)
    {
        curr3->next=curr1;
        curr1=curr1->next;
        curr3=curr3->next;
    }
    
    while(curr2!=NULL)
    {
        curr3->next=curr2;
        curr2=curr2->next;
        curr3=curr3->next;
    }
    return dummy->next;
    // code here
}  


// Leetcode 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */




class Solution {
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
     {
          ListNode*curr1=l1;
          ListNode*curr2=l2;
          ListNode*dummy=new ListNode(0) ;
          ListNode*p=dummy;
          
         while(curr1!=NULL and curr2!=NULL)
         {
             if(curr1->val<=curr2->val)
             {
                 p->next=curr1;
                 curr1=curr1->next;
             }
             
             else
             {
                 p->next=curr2;
                 curr2=curr2->next;
             }
             p=p->next;
         }
         
         while(curr1!=NULL)
         {
             p->next=curr1;
             curr1=curr1->next;
             p=p->next;
         }
         
          while(curr2!=NULL)
         {
             p->next=curr2;
             curr2=curr2->next;
             p=p->next;
         }
         return dummy->next;
     }
};
