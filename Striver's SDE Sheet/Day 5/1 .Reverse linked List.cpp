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
    // using 3 pointer approach
    // tc:O(N)
    // sc:O(1)
     ListNode* reverseList(ListNode* head)
     {
         if(head==NULL)
         {
             return NULL;
         }
         ListNode*prev=NULL;
         ListNode* curr=head;
         ListNode*next;
         while(curr!=NULL)
         {
             next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
         }
         return prev;
     }
};


// using recursion 
class Solution {
public:
    
     ListNode* reverse(ListNode* head,ListNode* prev)
     {
         if(head==NULL)
         {
             return prev;
         }
         
         ListNode* temp = head->next;
         head->next = prev;
         return reverse(temp,head);
     }
    
    
    ListNode* reverseList(ListNode* head) 
    {
        return reverse(head,NULL);
    }
};
