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
