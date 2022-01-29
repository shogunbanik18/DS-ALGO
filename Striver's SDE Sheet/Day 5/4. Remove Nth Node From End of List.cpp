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
    // tc:o(n)+o(n)
    // sc:o(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode*curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        // edge cases
        if(count==n)
        {
            return head->next;
        }
        ListNode* temp=head;
        int p=1;
        while(temp!=NULL and p<count-n)
        {
            temp=temp->next;
            p++;
        }
        temp->next=temp->next->next;
        return head;
    }
        
//         // tc:O(2N)
//         // SC:O(1)
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            ListNode*curr=head;
            int count=1;
            while(curr->next!=NULL)
            {
                count++;
                curr=curr->next;
            }
            
            if(count==n)
            {
                return head->next;
            }
            
            ListNode*temp=head;
            int p=1;
           
            while(temp!=NULL and p<count-n)
            {
                p++;
                temp=temp->next;
            }
            ListNode*node=temp->next;
            temp->next=temp->next->next;
            delete(node);
            return head;
        }
    
        // tc:O(N)
        // SC:O(1)
        // using hare tortoise method 
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            ListNode*dummy=new ListNode(0);
            dummy->next=head;
            ListNode*fast=dummy;
            ListNode*slow=dummy;
            for(int i=1;i<=n;i++)
            {
                fast=fast->next;
            }
            while(fast->next!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
            ListNode*node=slow->next;
            slow->next=slow->next->next;
            return dummy->next;
        }
};
