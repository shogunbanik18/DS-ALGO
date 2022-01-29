/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Harami question 
class Solution {
public:
    // dump solution 
    void deleteNode(ListNode* node)
    {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
