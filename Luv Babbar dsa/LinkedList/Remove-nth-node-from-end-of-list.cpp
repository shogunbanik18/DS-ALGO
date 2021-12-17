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
    
    int countNode(ListNode* head)
    {
        int count=0;
        ListNode* start=head;
        while(start!=NULL)
        {
            count++;
            start=start->next;
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int l=countNode(head);
        // base case
        if(l==1)
        {
            return NULL;
        }
        
        if(l==n)
        {
            return head->next;
        }
        // cout<<l<<endl;
        ListNode*curr=head;
        ListNode* prev=NULL;
        int x=l-n;
        for(int i=0;i<x;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};
