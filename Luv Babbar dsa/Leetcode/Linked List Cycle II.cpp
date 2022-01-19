/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Floyd's Cycledetection alorithm
    // Hare Tortoise Algorithm 
    ListNode *detectCycle(ListNode *head) 
    {
        // base case 
        if(head==NULL or head->next==NULL)
        {
            return NULL;
        }
        
        ListNode *slow=head;
        ListNode *fast=head;
        // check for cycle
        bool iscycle=false;
        
        while(slow!=NULL and fast!=NULL)
        {
            slow=slow->next;
            if(fast->next==NULL)
            {
                return NULL;
            }
            fast=fast->next->next;
            if(slow==fast)
            {
                iscycle=true;
                break;
            }
        }
        
        if(!iscycle)
        {
            return NULL;
        }
        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
