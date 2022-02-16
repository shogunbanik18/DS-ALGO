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

// using the concept of new node and prev 
class Solution {
public:
    // iterative way 
    // tc:o(n)
    // sc:o(n)
    ListNode* swapPairs(ListNode* head)
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        
        ListNode* dummy =new ListNode(0);
        ListNode*prev=dummy;
        dummy->next=head;
        while(head!=NULL and head->next!=NULL)
        {
            ListNode*first=head;
            ListNode*second=head->next;
            
            prev->next=second;
            first->next=second->next;
            second->next=first;
            
            prev=first;
            head=first->next;
        }
        return dummy->next;
    }
    
     // using recursive solution 
       ListNode* swapPairs(ListNode* head)
       {
           if(head==NULL or head->next==NULL)
           {
               return head;
           }
           
           ListNode*temp=head->next;
           head->next =swapPairs(head->next->next);
           temp->next=head;
           return temp;
       }
};
  
   
