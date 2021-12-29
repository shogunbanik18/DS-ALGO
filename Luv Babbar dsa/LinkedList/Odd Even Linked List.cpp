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


// Leetcode 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head or !head->next or !head->next->next)
        {
            return head;
        }
        
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*even_start=head->next;
        
        while(odd->next and even->next)
        {
            odd->next=even->next;
            even->next=odd->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=even_start;
        return head;
    }
};

