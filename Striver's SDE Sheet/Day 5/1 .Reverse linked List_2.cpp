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
    // tc:O(n)    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
         // base case 
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr;
        for(int i=0;i<left-1;i++)
        {
            prev=prev->next;
        }
        curr=prev->next;
        
        for(int i=0;i<right-left;i++)
        {
             ListNode*temp=prev->next;
             prev->next=curr->next;
             curr-> next = curr-> next -> next;
             prev-> next -> next = temp;
        }
        return dummy->next;
    }
};
