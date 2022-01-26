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

    
    // using counting method
    // tc:o(n)+o(n/2)
    // sc:o(1)
    ListNode* middleNode(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*temp=head;;
        ListNode*curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        int mid=(count/2)+1;
        for(int i=1;i<=mid-1;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    
    // optimised approach 
    // using hare tortoise method 
    // tc:o(n/2)
    // sc:o(1)
    ListNode* middleNode(ListNode* head) 
    {
        // base case 
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
