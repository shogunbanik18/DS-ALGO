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
    // using 2 pointer
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==NULL)
        {
            return head;
        }
        while(head!=NULL and head->val==val)
        {
            head=head->next;
        }
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
                curr=curr->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
    
//     using 1 pointer 
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==NULL)
        {
            return head;
        }
        // skipping duplicates 
        while(head!=NULL and head->val==val)
        {
            head=head->next;
        }
        ListNode*curr=head;
        while(curr!=NULL and curr->next!=NULL)
        {
            if(curr->next->val==val)
            {
                curr->next=curr->next->next;
            }
            else
            {
                curr=curr->next;
            }
        }
        return head;
    }
    
};
