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
    // using hashset
    // tc: o(n)
    // sc : o(n)
    bool hasCycle(ListNode *head)
    {
        bool ans=false;
        set<ListNode *>s;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(s.find(curr)!=s.end())
            {
                ans=true;
                break;
            }
            s.insert(curr);
            curr=curr->next;
        }
        return ans;
    }
    
    // using hare tortoise method || Floyd's Cycle detection Algorithm
    // tc : o(n)
    // sc:o(1)
    bool hasCycle(ListNode *head)
    {
        bool ans=false;
        ListNode *fast=head;
        ListNode *slow=head;
        // while(fast->next!=NULL and fast->next->next!=NULL)
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast)
            {
                ans =true;
                break;
            }
        }
        return ans;
    }
    
    // using dummy variable method 
    // tc: o(n)
    // sc:o(1)
    bool hasCycle(ListNode *head)
    {
        bool ans=false;
        ListNode *curr=head;
        if(curr==NULL)
        {
           return false;
        }
        
        while(curr!=NULL)
        {
            if(curr->val==100001)
            {
                ans=true;
                break;
            }
            curr->val=100001;
            curr=curr->next;
        }
        return ans;
    }
};
