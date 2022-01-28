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
//     using counting method 
//     tc:o(n)+ o(count-n) 
//     tc:o(n)+o(n)
//     sc:o(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int count=0;
        ListNode*curr=head;
        ListNode*temp=head;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        if(count==n)
        {
            return head->next;
        }
        int p=1;
        while(temp!=NULL and p<count-n)
        {
            p++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
