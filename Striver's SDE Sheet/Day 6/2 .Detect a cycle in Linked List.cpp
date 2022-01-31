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
    // brute force approach
    // tc:o(n)
    // sc:o(n)
    // // using unordered set 
    bool hasCycle(ListNode *head) 
    {
        ListNode *curr=head;
        unordered_set<ListNode *>set;
        while(curr!=NULL)
        {
             if(set.find(curr)!=set.end())
            {
                return true;
            }
            set.insert(curr);
            curr=curr->next;
        }
        return false;
    }
    
    // using hare tortoise method
    // tc:o(n)
    // sc:o(1)
    bool hasCycle(ListNode *head) 
    {
        // edge case 
        if(head==NULL or head->next==NULL)
        {
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
